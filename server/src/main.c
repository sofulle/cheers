#include "../inc/server.h"

int main(int argc, char **argv) {
    int listenfd = 0;
    int connfd = 0;
    pid_t pid;
    struct sockaddr_in serv_addr;
    char buff[1024];
    if (argc < 2) {
        printf("HUI\n");
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(buff, '0', sizeof(buff));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 10);

    while (1) {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        pid = 0;
        if (pid == 0) {
            //child
            while (1) {
                for (;;) {
                    bzero(buff, 1024);

                    // read the message from client and copy it in buffer
                    read(connfd, buff, sizeof(buff));
                    if (buff[0] == 'e') {
                        close(listenfd);
                        exit(1);
                    }
                    // print buffer which contains the client contents
                    printf("From client: %s", buff);
                    char *s = request_hundler(buff);
                    write(connfd, s, mx_strlen(s));
                }
                sleep(3);
            }
        }
        else if (pid > 0) {
            //master server
            printf("Created subserver for %d, pid: %d\n", connfd, pid);
            connfd = 0;
            pid = 0;
            continue;
        }
        else {
            exit(1);
        }
    }
    close(listenfd);
    return 0;
}
