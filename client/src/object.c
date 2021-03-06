// object.c

#include "cheers.h"

object_t *object_add_root(void) {
    object_t *object = NULL;

    object = (object_t *) malloc(sizeof(object_t));
    if(object == NULL) {
        printf("object_add_root: malloc returns NULL");
        return NULL;
    }
    memset(object, 0, sizeof(object_t));

    strcat(object->id, "root");
    object->style = set_clear_style();
    object->style.size.gwidth = START_SCREEN_WIDTH;
    object->style.size.gheight = START_SCREEN_HEIGHT;
    object->children = NULL;
    object->parent = NULL;
    object->on_start = NULL;
    object->on_update = NULL;
    object->on_click = NULL;
    object->on_hover_start = NULL;
    object->on_hover_end = NULL;

    return object;
}

object_t *object_add(char id[256], object_t *parent, style_t *style) {
    object_t *object = NULL;

    if(parent == NULL) {
        printf("object_add: parent is NULL");
        return NULL;
    }

    object = (object_t *) malloc(sizeof(object_t));
    if(object == NULL) {
        printf("object_add: malloc returns NULL");
        return NULL;
    }
    memset(object, 0, sizeof(object_t));

    if(style == NULL) {
        object->style = set_clear_style();
    }
    else {
        object->style = *style;
    }

    for (int i = 0; i < 256; i++) {
        object->id[i] = id[i];
    }
    object->children = NULL;
    object->parent = parent;
    object->on_start = NULL;
    object->on_update = NULL;
    object->on_click = NULL;
    object->on_hover_start = NULL;
    object->on_hover_end = NULL;

    vector_push_back(&parent->children, object);

    return object;
}

void object_hierarchy_exec(app_t *app, object_t *parent, void (*func)(app_t*, object_t*)) {
    func(app, parent);
    for (vector_t *node = parent->children; node != NULL; node = node->next) {
        object_t *obj = (object_t *)node->data;
        object_hierarchy_exec(app, obj, func);
    }
}

void object_hierarchy_event_exec(app_t *app, object_t *parent, SDL_Event *event, void (*event_func)(app_t*, object_t*, SDL_Event *event)) {
    event_func(app, parent, event);
    for (vector_t *node = parent->children; node != NULL; node = node->next) {
        object_t *obj = (object_t *)node->data;
        object_hierarchy_event_exec(app, obj, event, event_func);
    }
}

void object_hierarchy_search_n_exec_byzindex(app_t *app, object_t *parent, void (*func)(app_t*, object_t*), int z_index) {
    if(parent->style.global_z_index == z_index) func(app, parent);
    for (vector_t *node = parent->children; node != NULL; node = node->next) {
        object_t *obj = (object_t *)node->data;
        object_hierarchy_search_n_exec_byzindex(app, obj, func, z_index);
    }
}

object_t *object_search_byid(char id[256], object_t *parent) {
    if(strcmp(id, parent->id) == 0) return parent;

    for (vector_t *node = parent->children; node != NULL; node = node->next) {
        object_t *parent = (object_t *)node->data;
        object_t *object = object_search_byid(id, parent);
        if(object != NULL) return object;
    }

    return NULL;
}

void object_start(app_t *app, object_t *object) {
    if(object->on_start != NULL) object->on_start(app, object);
}

void object_update(app_t *app, object_t *object) {
    SDL_Point position;
    SDL_Point size;

    if(object == NULL) return;

    if(object->parent == NULL) {
        SDL_GetWindowSize(app->window, &object->style.size.gwidth, &object->style.size.gheight);
        return;
    }

    object->style.global_z_index = object->parent->style.global_z_index + object->style.z_index;


    if(object->style.size.is_percent_width) object->style.size.gwidth = ((object->parent->style.size.gwidth - object->parent->style.padding.left - object->parent->style.padding.right) * object->style.size.width) / 100;
    else object->style.size.gwidth = object->style.size.width;

    if(object->style.size.is_percent_height) object->style.size.gheight = ((object->parent->style.size.gheight - object->parent->style.padding.top - object->parent->style.padding.bottom) * object->style.size.height) / 100;
    else object->style.size.gheight = object->style.size.height;

    //object->style.size.gwidth += (object->style.padding.left + object->style.padding.right);
    //object->style.size.gheight += (object->style.padding.top + object->style.padding.bottom);


    if(object->style.position.is_percent_x) position.x = object->parent->style.position.gx + (object->parent->style.size.gwidth * object->style.position.x) / 100;
    else 
    position.x = object->parent->style.position.gx + object->style.position.x;

    if(object->style.position.is_percent_y) position.y = object->parent->style.position.gy + (object->parent->style.size.gheight * object->style.position.y) / 100;
    else 
    position.y = object->parent->style.position.gy + object->style.position.y;

    size.x = object->style.size.gwidth;
    size.y = object->style.size.gheight;

    switch (object->style.anchor) {
        case ANCHOR_TOP_LEFT:
            position.x += object->parent->style.padding.left;
            position.y += object->parent->style.padding.top;
            break;

        case ANCHOR_TOP_CENTER:
            position.x -= (size.x / 2);
            position.y += object->parent->style.padding.top;
            break;

        case ANCHOR_TOP_RIGHT:
            position.x -= size.x;
            position.x -= object->parent->style.padding.right;
            position.y += object->parent->style.padding.top;
            break;

        case ANCHOR_CENTER_LEFT:
            position.y -= (size.y / 2);
            position.x += object->parent->style.padding.left;
            break;

        case ANCHOR_CENTER_CENTER:
            position.x -= (size.x / 2);
            position.y -= (size.y / 2);
            break;

        case ANCHOR_CENTER_RIGHT:
            position.x -= size.x;
            position.y -= (size.y / 2);
            position.x -= object->parent->style.padding.right;
            break;

        case ANCHOR_BOTTOM_LEFT:
            position.y -= size.y;
            position.x += object->parent->style.padding.left;
            position.y -= object->parent->style.padding.bottom;
            break;

        case ANCHOR_BOTTOM_CENTER:
            position.x -= (size.x / 2);
            position.y -= size.y;
            position.y -= object->parent->style.padding.bottom;
            break;

        case ANCHOR_BOTTOM_RIGHT:
            position.x -= size.x;
            position.y -= size.y;
            position.x -= object->parent->style.padding.right;
            position.y -= object->parent->style.padding.bottom;
            break;

        default:
            break;
    }

    object->style.position.gx = position.x;
    object->style.position.gy = position.y;

    if(object->on_update != NULL) object->on_update(app, object);
}

void object_draw(app_t *app, object_t *object) {
    if(object == NULL) {
        exit(1);
    }

    if(object->parent == NULL) {
        return;
    }

    //printf("object: %s  w: %d  h: %d  x: %d  y: %d\n", object->id, object->style.size.gwidth, object->style.size.gheight, object->style.position.x, object->style.position.y);

    if(object->style.texture != NULL) {
        SDL_Rect dest;
        dest.x = object->style.position.gx;
        dest.y = object->style.position.gy;
        dest.w = object->style.size.gwidth;
        dest.h = object->style.size.gheight;

        SDL_RenderCopy(app->renderer, object->style.texture, NULL, &dest);
    }
    else if(object->style.background_color.a > 0) {
        SDL_Rect dest;
        dest.x = object->style.position.gx;
        dest.y = object->style.position.gy;
        dest.w = object->style.size.gwidth;
        dest.h = object->style.size.gheight;

        SDL_SetRenderDrawColor(app->renderer, object->style.background_color.r, object->style.background_color.g, object->style.background_color.b, object->style.background_color.a);
        SDL_RenderFillRect(app->renderer, &dest);
    }

    if(object->style.text_content != NULL) {
        SDL_Point position;
        SDL_Point size;
        position.x = object->style.position.gx;
        position.y = object->style.position.gy;
        size.x = object->style.size.gwidth - object->style.padding.left - object->style.padding.right;
        size.y = object->style.size.gheight - object->style.padding.top - object->style.padding.bottom;

    switch (object->style.text_anchor) {
        case ANCHOR_TOP_LEFT:
            position.x += object->style.padding.left;
            position.y += object->style.padding.top;
            break;

        case ANCHOR_TOP_CENTER:
            position.x += (size.x / 2);
            position.y += object->style.padding.top;
            break;

        case ANCHOR_TOP_RIGHT:
            position.x += size.x;
            position.x -= object->style.padding.right;
            position.y += object->style.padding.top;
            break;

        case ANCHOR_CENTER_LEFT:
            position.y += (size.y / 2);
            position.x += object->style.padding.left;
            break;

        case ANCHOR_CENTER_CENTER:
            position.x += (size.x / 2);
            position.y += (size.y / 2);
            break;

        case ANCHOR_CENTER_RIGHT:
            position.x += size.x;
            position.y += (size.y / 2);
            position.x -= object->style.padding.right;
            break;

        case ANCHOR_BOTTOM_LEFT:
            position.y += size.y;
            position.x += object->style.padding.left;
            position.y -= object->style.padding.bottom;
            break;

        case ANCHOR_BOTTOM_CENTER:
            position.x += (size.x / 2);
            position.y += size.y;
            position.y -= object->style.padding.bottom;
            break;

        case ANCHOR_BOTTOM_RIGHT:
            position.x += size.x;
            position.y += size.y;
            position.x -= object->style.padding.right;
            position.y -= object->style.padding.bottom;
            break;

        default:
            break;
    }

        SDL_Rect dest;
        dest.x = position.x;
        dest.y = position.y;
        dest.w = size.x;
        dest.h = size.y;
        
        draw_text(app, object->style.text_content, object->style.font.font_id, &dest, object->style.font.color, object->style.text_anchor);
    
        if(dest.h > size.y) object->style.size.gheight = dest.h + object->style.padding.top + object->style.padding.bottom;
    }
}

void object_onclick(app_t *app, object_t *object, SDL_Event *event) {
    if(object->on_click_start == NULL && object->on_click_end == NULL) return;

    SDL_MouseButtonEvent e = event->button;
    int x = e.x, y = e.y;
    SDL_Rect obj = get_object_rect(object);

    if(e.button == SDL_BUTTON_LEFT) {
        if(x > obj.x && x < obj.x + obj.w && y > obj.y && y < obj.y + obj.h && object->is_clicked == false) {
            object->is_clicked = true;
            object->on_click_start(app, object, event);
        }
        else if(x > obj.x && x < obj.x + obj.w && y > obj.y && y < obj.y + obj.h && object->is_clicked == true) {
            object->is_clicked = false;
            object->on_click_end(app, object, event);
            object->on_click(app, object, event);
        }
        else if(object->is_clicked == true) {
            object->is_clicked = false;
            object->on_click_end(app, object, event);
        }
    }
}

void object_onhover(app_t *app, object_t *object, SDL_Event *event) {
    if(object->on_hover_start == NULL && object->on_hover_end == NULL) return;

    SDL_MouseMotionEvent e = event->motion;
    int x = e.x, y = e.y;
    SDL_Rect obj = get_object_rect(object);

    if(x > obj.x && x < obj.x + obj.w && y > obj.y && y < obj.y + obj.h && object->is_hovered == false) {
        object->is_hovered = true;
        object->on_hover_start(app, object, event);
    }
    if((x < obj.x || x > obj.x + obj.w || y < obj.y || y > obj.y + obj.h) && object->is_hovered == true) {
        object->is_hovered = false;
        object->on_hover_end(app, object, event);
    }
}
