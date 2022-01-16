// main.c

#include "cheers.h"

int main(int argc, char *argv[]) {
	if (argc != 3) {
        printf("\n Usage: %s <ip of server> <port>\n", argv[0]);
        return 1;
    }

	app_t *app = app_init();

	event_init(app);
	scene_init(app);
	communication_with_server(app, argv);
	app_quit(app);

	return 0;
}
