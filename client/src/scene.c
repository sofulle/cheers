// scene.c

#include "cheers.h"

void scene_init(app_t *app) {
    init_login_window(app);
    init_main_window(app);

    //object_hierarchy_exec(app, app->root, object_start);

    //set_active_login_window(app);
    set_active_main_window(app);
}

void scene_prepare(app_t* app) {
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
	SDL_RenderClear(app->renderer);
}

void scene_update(app_t* app) {
    object_hierarchy_exec(app, app->root, object_update);
}

void scene_draw(app_t* app) {
    for (int i = 0; i < 16; i++) {
        object_hierarchy_search_n_exec_byzindex(app, app->root, object_draw, i);
    }
}

void scene_present(app_t* app) {
	SDL_RenderPresent(app->renderer);
}

void scene_free(app_t* app) {

}
