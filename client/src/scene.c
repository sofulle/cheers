// scene.c

#include "cheers.h"

void button_submit_onhoverstart(app_t *app, object_t *object, SDL_Event *event) {
    if(!object->is_clicked)
        object->style.background_color = set_color(62, 53, 101, 255);
}
void button_submit_onhoverend(app_t *app, object_t *object, SDL_Event *event) {
    if(!object->is_clicked)
        object->style.background_color = set_color(62, 67, 101, 255);
}


void button_submit_onclickstart(app_t *app, object_t *object, SDL_Event *event) {
    object->style.background_color = set_color(244, 4, 64, 255);
}
void button_submit_onclickend(app_t *app, object_t *object, SDL_Event *event) {
    object->style.background_color = set_color(62, 67, 101, 255);
}
void button_submit_onclick(app_t *app, object_t *object, SDL_Event *event) {
    object->style.text_content = "Never gonna give...";
}

void scene_init(app_t *app) {
    style_t style_background = set_clear_style();
    style_background.position = set_pos(0, 0, false, false);
    style_background.size = set_size(100, 100, true, true);
    style_background.anchor = ANCHOR_TOP_LEFT;
    style_background.background_color = set_color(31, 32, 44, 255);

    style_t style_container = set_clear_style();
    style_container.position = set_pos(50, 0, true, false);
    style_container.size = set_size(270, 100, false, true);
    style_container.anchor = ANCHOR_TOP_CENTER;
    style_container.z_index = 1;

    style_t style_logo = set_clear_style();
    style_logo.position = set_pos(50, 65, true, false);
    style_logo.size = set_size(80, 80, false, false);
    style_logo.anchor = ANCHOR_TOP_CENTER;
    style_logo.texture = render_texture(app, "resource/img/logo.png");

    style_t style_title = set_clear_style();
    style_title.position = set_pos(50, 165, true, false);
    style_title.size = set_size(100, 42, true, false);
    style_title.anchor = ANCHOR_TOP_CENTER;
    //style_title.text_content = "Cheers!";
    style_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_title.font = set_font(FONT_ROBOTO_REGULAR_36, set_color(255, 255, 255, 255));

    style_t style_subtitle = set_clear_style();
    style_subtitle.position = set_pos(50, 217, true, false);
    style_subtitle.size = set_size(100, 19, true, false);
    style_subtitle.anchor = ANCHOR_TOP_CENTER;
    //style_subtitle.text_content = "Lets start your own party!";
    style_subtitle.text_anchor = ANCHOR_CENTER_CENTER;
    style_subtitle.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_input_name = set_clear_style();
    style_input_name.position = set_pos(50, 264, true, false);
    style_input_name.size = set_size(100, 48, true, false);
    style_input_name.padding.left = 15;
    style_input_name.anchor = ANCHOR_TOP_CENTER;
    style_input_name.background_color = set_color(62, 67, 101, 255);
    //style_input_name.text_content = app->text;
    style_input_name.text_anchor = ANCHOR_CENTER_LEFT;
    style_input_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_input_username = set_clear_style();
    style_input_username.position = set_pos(50, 327, true, false);
    style_input_username.size = set_size(100, 48, true, false);
    style_input_username.padding.left = 15;
    style_input_username.anchor = ANCHOR_TOP_CENTER;
    style_input_username.background_color = set_color(62, 67, 101, 255);
    style_input_username.text_content = app->composition;
    style_input_username.text_anchor = ANCHOR_CENTER_LEFT;
    style_input_username.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_button_submit = set_clear_style();
    style_button_submit.position = set_pos(50, 432, true, false);
    style_button_submit.size = set_size(90, 48, true, false);
    style_button_submit.padding.left = 15;
    style_button_submit.anchor = ANCHOR_TOP_CENTER;
    style_button_submit.background_color = set_color(62, 67, 101, 255);
    //style_button_submit.text_content = "Nam";
    style_button_submit.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_submit.font = set_font(FONT_ROBOTO_REGULAR_18, set_color(255, 255, 255, 255));

    style_t style_copyright = set_clear_style();
    style_copyright.position = set_pos(50, 100, true, true);
    style_copyright.size = set_size(100, 14, true, false);
    style_copyright.anchor = ANCHOR_BOTTOM_CENTER;
    style_copyright.padding.bottom = 20;
    //style_copyright.text_content = "Cop & Past Inc.";
    style_copyright.text_anchor = ANCHOR_CENTER_CENTER;
    style_copyright.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 255));

    object_add("background", app->root, &style_background);
    object_add("container", app->root, &style_container);
    object_add("logo", object_search_byid("container", app->root), &style_logo);
    object_add("title", object_search_byid("container", app->root), &style_title);
    object_add("subtitle", object_search_byid("container", app->root), &style_subtitle);
    object_add("input_name", object_search_byid("container", app->root), &style_input_name);
    object_add("input_username", object_search_byid("container", app->root), &style_input_username);
    object_add("button_submit", object_search_byid("container", app->root), &style_button_submit);
    object_add("copyright", object_search_byid("container", app->root), &style_copyright);

    object_hierarchy_exec(app, app->root, object_start);

    //SDL_StartTextInput();

    object_search_byid("button_submit", app->root)->on_hover_start = button_submit_onhoverstart;
    object_search_byid("button_submit", app->root)->on_hover_end = button_submit_onhoverend;

    object_search_byid("button_submit", app->root)->on_click_start = button_submit_onclickstart;
    object_search_byid("button_submit", app->root)->on_click_end = button_submit_onclickend;
    object_search_byid("button_submit", app->root)->on_click = button_submit_onclick;
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
