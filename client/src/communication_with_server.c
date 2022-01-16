#include "cheers.h"

void communication_with_server(app_t *app, char **argv) {
    while (true) {
        int sockfd = 0;
        char buff[1024];
        struct sockaddr_in serv_addr;

        memset(buff, '0', sizeof(buff));
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("\n Error : Could not create socket \n");
            return;
        }

        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(atoi(argv[2]));

        if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
            printf("\n inet_pton error occured\n");
            return;
        }

        printf("Connecting to the server...\n");
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Error : Connect Failed \n");
            printf("Retrying... \n\n");
            sleep(5);
            close(sockfd);
            continue;
        }

        while (true) {
            scene_prepare(app);

            scene_update(app);

            //bzero(buff, 1024);
            memset(buff, 0, 1024);
            printf("Enter the string : ");
            for (int n = 0;(buff[n] = getchar()) != '\n'; n++)
                ;
            write(sockfd, buff, sizeof(buff));
            if (buff[0] == 'e') {
                close(sockfd);
                exit(1);
            }
            memset(buff, 0, 1024);
            read(sockfd, buff, sizeof(buff));
            //printf("From Server : %s", recvBuff);

            scene_draw(app, buff);

            scene_present(app);

            event_handle(app);

            SDL_Delay(16);

        }
        printf("Read error : Connect Failed \n");
        printf("Retrying... \n\n");
        close(sockfd);
        sleep(5);
    }
}
