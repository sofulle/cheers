// input.c

#include "cheers.h"

void event_handle(app_t *app) {
	SDL_Event event;

	app->wheel_y = 0;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
					if(app->text_input_ptr != NULL) app->text_input_ptr[strlen(app->text_input_ptr) - 1] = '\0';
				}
				break;
			case SDL_KEYUP:
				//event_keyup(app, &event.key);
				break;

			case SDL_WINDOWEVENT:
				//event_window(app, &event.window);
				break;

			case SDL_TEXTINPUT:
				if(app->text_input_ptr != NULL) strcat(app->text_input_ptr, event.text.text);
				break;

			case SDL_MOUSEBUTTONDOWN:
				object_hierarchy_event_exec(app, app->root, &event, object_onclick);
				break;
			case SDL_MOUSEBUTTONUP:
				object_hierarchy_event_exec(app, app->root, &event, object_onclick);
				break;
			case SDL_MOUSEMOTION:
				object_hierarchy_event_exec(app, app->root, &event, object_onhover);
				break;

			case SDL_MOUSEWHEEL:
				app->wheel_y = event.wheel.y;
				break;

			default:
				break;
		}
	}
}
