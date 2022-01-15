// structs.h
#ifndef CHEERS_STRUCTS_H
#define CHEERS_STRUCTS_H

typedef struct app_s app_t;

typedef struct s_control {
	int up;
	int down;
	int left;
	int right;
	int use;
	int start;
	bool is_locked;
	bool D;
	bool E;
	bool V;
} t_control;

typedef struct Size_s {
	int width;
	int height;
	int gwidth;
	int gheight;
	bool is_percent_width;
	bool is_percent_height;
} Size_t;

typedef struct Pos_s {
	int y;
	int x;
	int gx;
	int gy;
	bool is_percent_x;
	bool is_percent_y;
} Pos_t;

typedef struct offset_s {
	int top;
	int bottom;
	int left;
	int right;
} offset_t;

typedef struct font_style_s {
	font_t font_id;
	SDL_Color color;
} font_style_t;

typedef struct style_s {
	Pos_t position;
	offset_t padding;
	anchor_t anchor;
	Size_t size;
	font_style_t font;
	SDL_Color background_color;
	SDL_Texture *texture;
	int z_index;
	int global_z_index;
	char *text_content;
	anchor_t text_anchor;
} style_t;

typedef struct object_s {
	char id[256];
	bool is_focused;
	style_t style;
	struct object_s *parent;
	vector_t *children;
	void (*on_start)(app_t *app, struct object_s *object);
	void (*on_update)(app_t *app, struct object_s *object);
	void (*on_click)(app_t *app, struct object_s *object);
	void (*on_hover)(app_t *app, struct object_s *object);
} object_t;

typedef struct app_s {
	SDL_Renderer *renderer;
	SDL_Window *window;
	t_control control;
	object_t *root;
	TTF_Font *fonts[FONT_COUNT];
	SDL_Rect glyphs[FONT_COUNT][GLYPHS_COUNT];
	SDL_Texture *font_textures[FONT_COUNT];
} app_t;


#endif // !CHEERS_STRUCTS_H
