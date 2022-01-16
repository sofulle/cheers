// main.c

#include "cheers.h"

// int argc, char *argv[]

int main() {
	app_t *app = app_init();

	scene_init(app);

	while (true) {
		scene_prepare(app);

		scene_update(app);

		event_handle(app);

		scene_draw(app);

		scene_present(app);

		SDL_Delay(16);
	}

	app_quit(app);

	return 0;
}
