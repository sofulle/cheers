// input.c

#include "cheers.h"

void event_handle(app_t *app) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				//event_keydown(app, &event.key);
				break;
			case SDL_KEYUP:
				//event_keyup(app, &event.key);
				break;

			case SDL_WINDOWEVENT:
				//event_window(app, &event.window);
				break;

			case SDL_TEXTINPUT:
				strcat(app->text, event.text.text);
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

			default:
				break;
		}
	}
}
