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
SDL_Texture* render_text(app_t *app, char *message, char *font_file_name, SDL_Color color, int font_size);
void draw_texture(app_t *app, SDL_Texture *texture, int x, int y, anchor_t anchor);
void draw_text(app_t *app, char *text, int x, int y, int size, anchor_t anchor);

// event
void event_init(app_t *app);
void event_handle(app_t *app);
void event_keydown(app_t *app, SDL_KeyboardEvent *event);
void event_keyup(app_t *app, SDL_KeyboardEvent *event);
void event_window(app_t *app, SDL_WindowEvent *event);

// object
object_t *object_add_root(void);
object_t *object_add(char id[256], object_t *parent, style_t *style, void (*on_start)(app_t *, object_t *), void (*on_update)(app_t *, object_t *), void (*on_click)(app_t *, object_t *), void (*on_hover)(app_t *, object_t *));
void object_hierarchy_exec(app_t *app, object_t *parent, void (*func)(app_t*, object_t*));
void object_hierarchy_search_n_exec_byzindex(app_t *app, object_t *parent, void (*func)(app_t*, object_t*), int z_index);
object_t *object_search_byid(char id[256], object_t *parent);
void object_draw(app_t *app, object_t *object);
void object_update(app_t *app, object_t *object);

// utils
SDL_Color set_color(int r, int g, int b, int a);
style_t set_clear_style(void);


#endif // !CHEERS_FUNCTIONS_H
