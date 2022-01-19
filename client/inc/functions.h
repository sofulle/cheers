// functions.h
#ifndef CHEERS_FUNCTIONS_H
#define CHEERS_FUNCTIONS_H

#include "cheers.h"


// app
app_t *app_init();
void app_quit(app_t *app);

// 
void scene_init(app_t *app);
void scene_prepare(app_t *app);
void scene_update(app_t* app);
void scene_draw(app_t *app);
void scene_present(app_t *app);
void scene_logic(app_t *app);
void scene_quit(app_t *app);

// draw
SDL_Texture *render_texture(app_t *app, char *filename);
void draw_texture(app_t *app, SDL_Texture *texture, int x, int y, anchor_t anchor);
void draw_text(app_t *app, char *text, font_t font_id, SDL_Rect *rect, SDL_Color color, anchor_t anchor);

// event
void event_handle(app_t *app);

// object
object_t *object_add_root(void);
object_t *object_add(char id[256], object_t *parent, style_t *style);
void object_hierarchy_exec(app_t *app, object_t *parent, void (*func)(app_t*, object_t*));
void object_hierarchy_event_exec(app_t *app, object_t *parent, SDL_Event *event, void (*event_func)(app_t*, object_t*, SDL_Event*));
void object_hierarchy_search_n_exec_byzindex(app_t *app, object_t *parent, void (*func)(app_t*, object_t*), int z_index);
object_t *object_search_byid(char id[256], object_t *parent);
void object_start(app_t *app, object_t *object);
void object_update(app_t *app, object_t *object);
void object_draw(app_t *app, object_t *object);
void object_onclick(app_t *app, object_t *object, SDL_Event *event);
void object_onhover(app_t *app, object_t *object, SDL_Event *event);

// utils
SDL_Color set_color(int r, int g, int b, int a);
Size_t set_size(int width, int height, bool is_percent_width, bool is_percent_height);
Pos_t set_pos(int x, int y, bool is_percent_x, bool is_percent_y);
offset_t set_pad(int left, int right, int top, int bottom);
font_style_t set_font(font_t font, SDL_Color color);
style_t set_clear_style(void);
//int max(int a, int b);
SDL_Rect get_object_rect(object_t *object);


#endif // !CHEERS_FUNCTIONS_H
