// scene.c

#include "cheers.h"

void obj_down(app_t *app, object_t *object) {
    object->style.percentage_position.x--;
    object->style.position.x--;
} //////////

void scene_init(app_t *app) {
    style_t root_style = set_clear_style();
    root_style.percentage_position.x = 50;
    root_style.percentage_position.y = 50;
    root_style.size.width = 400;
    root_style.size.height = 200;
    root_style.background_color = set_color(20, 30, 167, 255);
    root_style.anchor = ANCHOR_CENTER_CENTER;

    style_t main_style = set_clear_style();
    main_style.position.x = 0;
    main_style.percentage_position.y = 50;
    main_style.size.width = 50;
    main_style.size.height = 10;
    main_style.size.is_percent_width = true;
    main_style.size.is_percent_height = true;
    main_style.background_color = set_color(20, 166, 167, 255);
    main_style.anchor = ANCHOR_CENTER_LEFT;
    main_style.text_content = "Never gonna give you up";
    main_style.text_anchor = ANCHOR_BOTTOM_RIGHT;
    main_style.font_size = 24;

    style_t in_style = set_clear_style();
    in_style.percentage_position.x = 50;
    in_style.percentage_position.y = 50;
    in_style.size.width = 100;
    in_style.size.height = 100;
    in_style.background_color = set_color(20, 30, 20, 255);
    in_style.anchor = ANCHOR_BOTTOM_RIGHT;

    style_t img_style = set_clear_style();
    img_style.position.x = 5;
    img_style.position.y = 5;
    img_style.size.width = 90;
    img_style.size.height = 90;
    img_style.texture = render_texture(app, "resource/img/image.png");
    img_style.anchor = ANCHOR_TOP_LEFT;
    img_style.z_index = 1;

    object_add("main", app->root, &root_style, NULL, NULL, NULL, NULL);
    object_add("not_main", app->root, &main_style, NULL, NULL, NULL, NULL);
    object_add("in", object_search_byid("main", app->root), &in_style, NULL, NULL, NULL, NULL);
    object_add("img", object_search_byid("in", app->root), &img_style, NULL, NULL, NULL, NULL);

    object_search_byid("in", app->root)->on_update = obj_down;
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
