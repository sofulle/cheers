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
    object->style.global_size.x = START_SCREEN_WIDTH;
    object->style.global_size.y = START_SCREEN_HEIGHT;
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

    //printf("object: %s  x: %d  y: %d  w: %d  h: %d  parent: %s\n", object->id, rect.x, rect.y, rect.w, rect.h, object->parent->id);

    if(object->style.texture != NULL) {
        SDL_Rect dest;
        dest.x = object->style.global_position.x;
        dest.y = object->style.global_position.y;
        dest.w = object->style.global_size.x;
        dest.h = object->style.global_size.y;

        SDL_RenderCopy(app->renderer, object->style.texture, NULL, &dest);
    }
    else {
        SDL_Rect dest;
        dest.x = object->style.global_position.x;
        dest.y = object->style.global_position.y;
        dest.w = object->style.global_size.x;
        dest.h = object->style.global_size.y;

        SDL_SetRenderDrawColor(app->renderer, object->style.background_color.r, object->style.background_color.g, object->style.background_color.b, object->style.background_color.a);
        SDL_RenderFillRect(app->renderer, &dest);
    }
}

void object_update(app_t *app, object_t *object) {
    SDL_Point position;
    SDL_Point size;

    if(object == NULL) return;

    if(object->parent == NULL) {
        SDL_GetWindowSize(app->window, &object->style.global_size.x, &object->style.global_size.y);
        return;
    }

    object->style.global_z_index = object->parent->style.global_z_index + object->style.z_index;

    if(object->style.percentage_size.w >= 0) object->style.global_size.x = (object->parent->style.global_size.x * object->style.percentage_size.w) / 100;
    else object->style.global_size.x = object->style.size.x;

    if(object->style.percentage_size.h >= 0) object->style.global_size.y = (object->parent->style.global_size.y * object->style.percentage_size.h) / 100;
    else object->style.global_size.y = object->style.size.y;


    if(object->style.percentage_position.x >= 0) position.x = object->parent->style.global_position.x + (object->parent->style.global_size.x * object->style.percentage_position.x) / 100;
    else 
    position.x = object->parent->style.global_position.x + object->style.position.x;

    if(object->style.percentage_position.y >= 0) position.y = object->parent->style.global_position.y + (object->parent->style.global_size.y * object->style.percentage_position.y) / 100;
    else 
    position.y = object->parent->style.global_position.y + object->style.position.y;

    size = object->style.global_size;

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

    object->style.global_position = position;

    if(object->on_update != NULL) object->on_update(app, object);
}
