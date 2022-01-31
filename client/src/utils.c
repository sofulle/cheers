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

SDL_Color add_color(SDL_Color color, int add) {
    SDL_Color ret;
    ret.r = color.r + add;
    ret.g = color.g + add;
    ret.b = color.b + add;
    ret.a = color.a;

    return ret;
}

Size_t set_size(int width, int height, bool is_percent_width, bool is_percent_height) {
    Size_t size;
    size.width = width;
    size.height = height;
    size.is_percent_width = is_percent_width;
    size.is_percent_height = is_percent_height;

    return size;
}

Pos_t set_pos(int x, int y, bool is_percent_x, bool is_percent_y) {
    Pos_t pos;
    pos.x = x;
    pos.y = y;
    pos.is_percent_x = is_percent_x;
    pos.is_percent_y = is_percent_y;

    return pos;
}

offset_t set_pad(int left, int right, int top, int bottom) {
    offset_t pad;
    pad.left = left;
    pad.right = right;
    pad.top = top;
    pad.bottom = bottom;

    return pad;
}

font_style_t set_font(font_t font_id, SDL_Color color) {
    font_style_t font;
    font.font_id = font_id;
    font.color = color;

    return font;
}

style_t set_clear_style(void) {
    style_t style;
    
    style.anchor = ANCHOR_TOP_LEFT;
    style.background_color = set_color(0, 0, 0, 0);
    style.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));
    style.size = set_size(0, 0, false, false);
    style.size.gwidth = 0;
    style.size.gheight = 0;
    style.position = set_pos(0 , 0, false, false);
    style.position.gx = 0;
    style.position.gy = 0;
    style.texture = NULL;
    style.z_index = 0;
    style.global_z_index = 0;
    style.text_content = NULL;
    style.text_placeholder = NULL;
    style.text_anchor = ANCHOR_TOP_LEFT;
    style.padding = set_pad(0, 0, 0, 0);
    style.is_static = false;
    style.is_auto_height  = false;

    return style;
}

//int max(int a, int b) {
//    if(a > b) return a;
//    else return b;
//}

SDL_Rect get_object_rect(object_t *object) {
    SDL_Rect rect;
    rect.x = object->style.position.gx;
    rect.y = object->style.position.gy;
    rect.w = object->style.size.gwidth;
    rect.h = object->style.size.gheight;

    return rect;
}
