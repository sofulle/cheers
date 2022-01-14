// utils.c

#include "cheers.h"

SDL_Color set_color(int r, int g, int b, int a) {
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;

    return color;
}

style_t set_clear_style(void) {
    style_t style;
    
    style.anchor = ANCHOR_TOP_LEFT;
    style.background_color = set_color(0, 0, 0, 0);
    style.font_color = set_color(0, 0, 0, 0);
    style.font_family = 0;
    style.font_size = 0;
    style.size.width = 0;
    style.size.height = 0;
    style.size.gwidth = 0;
    style.size.gheight = 0;
    style.size.is_percent_width = false;
    style.size.is_percent_height= false;
    style.position.x = 0;
    style.position.y = 0;
    style.global_position.x = 0;
    style.global_position.y = 0;
    style.percentage_position.x = -1;
    style.percentage_position.y = -1;
    style.texture = NULL;
    style.z_index = 0;
    style.global_z_index = 0;
    style.text_content = NULL;
    style.text_anchor = ANCHOR_TOP_LEFT;

    return style;
}