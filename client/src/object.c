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
    object->on_hover = NULL;

    return object;
}

object_t *object_add(char id[256], object_t *parent, style_t *style, void (*on_start)(app_t *, object_t *), void (*on_update)(app_t *, object_t *), void (*on_click)(app_t *, object_t *), void (*on_hover)(app_t *, object_t *)) {
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
    object->on_start = on_start;
    object->on_update = on_update;
    object->on_click = on_click;
    object->on_hover = on_hover;

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
    else {
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
        size.x = object->style.size.gwidth;
        size.y = object->style.size.gheight;

        switch (object->style.text_anchor) {
            case ANCHOR_TOP_LEFT:
                break;

            case ANCHOR_TOP_CENTER:
                position.x += (size.x / 2);
                break;

            case ANCHOR_TOP_RIGHT:
                position.x += size.x;
                break;

            case ANCHOR_CENTER_LEFT:
                position.y += (size.y / 2);
                break;

            case ANCHOR_CENTER_CENTER:
                position.x += (size.x / 2);
                position.y += (size.y / 2);
                break;

            case ANCHOR_CENTER_RIGHT:
                position.x += size.x;
                position.y += (size.y / 2);
                break;

            case ANCHOR_BOTTOM_LEFT:
                position.y += size.y;
                break;

            case ANCHOR_BOTTOM_CENTER:
                position.x += (size.x / 2);
                position.y += size.y;
                break;

            case ANCHOR_BOTTOM_RIGHT:
                position.x += size.x;
                position.y += size.y;
                break;

            default:
                break;
        }
        draw_text(app, object->style.text_content, position.x, position.y, object->style.font_size, object->style.text_anchor);
    }
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


    if(object->style.size.is_percent_width) object->style.size.gwidth = (object->parent->style.size.gwidth * object->style.size.width) / 100;
    else object->style.size.gwidth = object->style.size.width;

    if(object->style.size.is_percent_height) object->style.size.gheight = (object->parent->style.size.gheight * object->style.size.height) / 100;
    else object->style.size.gheight = object->style.size.height;


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
            break;

        case ANCHOR_TOP_CENTER:
            position.x -= (size.x / 2);
            break;

        case ANCHOR_TOP_RIGHT:
            position.x -= size.x;
            break;

        case ANCHOR_CENTER_LEFT:
            position.y -= (size.y / 2);
            break;

        case ANCHOR_CENTER_CENTER:
            position.x -= (size.x / 2);
            position.y -= (size.y / 2);
            break;

        case ANCHOR_CENTER_RIGHT:
            position.x -= size.x;
            position.y -= (size.y / 2);
            break;

        case ANCHOR_BOTTOM_LEFT:
            position.y -= size.y;
            break;

        case ANCHOR_BOTTOM_CENTER:
            position.x -= (size.x / 2);
            position.y -= size.y;
            break;

        case ANCHOR_BOTTOM_RIGHT:
            position.x -= size.x;
            position.y -= size.y;
            break;

        default:
            break;
    }

    object->style.position.gx = position.x;
    object->style.position.gy = position.y;

    if(object->on_update != NULL) object->on_update(app, object);
}
