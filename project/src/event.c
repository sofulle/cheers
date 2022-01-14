// input.c

#include "cheers.h"

void event_init(app_t *app) {

}

void event_handle(app_t *app) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				event_keydown(app, &event.key);
				break;

			case SDL_KEYUP:
				event_keyup(app, &event.key);
				break;

			case SDL_WINDOWEVENT:
				event_window(app, &event.window);
				break;

			default:
				break;
		}
	}
}

void event_keydown(app_t *app, SDL_KeyboardEvent *event) {
	if (event->repeat == 0) {
		if (((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W)) && !app->control.is_locked) {
			app->control.up = 1;
		}
	}
}

void event_keyup(app_t *app, SDL_KeyboardEvent *event) {
	if (event->repeat == 0) {
		if ((event->keysym.scancode == SDL_SCANCODE_UP) || (event->keysym.scancode == SDL_SCANCODE_W)) {
			app->control.up = 0;
		}
	}
}

void event_window(app_t *app, SDL_WindowEvent *event) {
	switch (event->event)
	{
	case SDL_WINDOWEVENT_RESIZED:
		break;
	
	default:
		break;
	}
}
