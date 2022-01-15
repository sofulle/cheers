// draw.c

#include "cheers.h"

SDL_Texture *render_texture(app_t *app, char *filename) {
	SDL_Texture *texture;

	texture = IMG_LoadTexture(app->renderer, filename);

	return texture;
}

void draw_texture(app_t *app, SDL_Texture *texture, int x, int y, anchor_t anchor) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	switch (anchor) {
        case ANCHOR_TOP_LEFT:
            break;

        case ANCHOR_TOP_CENTER:
            dest.x -= (dest.w / 2);
            break;

        case ANCHOR_TOP_RIGHT:
            dest.x -= dest.w;
            break;

        case ANCHOR_CENTER_LEFT:
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_CENTER_CENTER:
            dest.x -= (dest.w / 2);
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_CENTER_RIGHT:
            dest.x -= dest.w;
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_BOTTOM_LEFT:
            dest.y -= dest.h;
            break;

        case ANCHOR_BOTTOM_CENTER:
            dest.x -= (dest.w / 2);
            dest.y -= dest.h;
            break;

        case ANCHOR_BOTTOM_RIGHT:
            dest.x -= dest.w;
            dest.y -= dest.h;
            break;

        default:
            break;
	}

	SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}

void draw_text(app_t *app, char *text, font_t font_id, SDL_Rect *rect, SDL_Color color, anchor_t anchor) {
    SDL_Surface *surf = TTF_RenderUTF8_Blended_Wrapped(app->fonts[font_id], text, color, rect->w);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surf);

    SDL_Rect dest;
	dest.x = rect->x;
	dest.y = rect->y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	if(rect->h < dest.h) rect->h = dest.h;

    switch (anchor) {
        case ANCHOR_TOP_LEFT:
            break;

        case ANCHOR_TOP_CENTER:
            dest.x -= (dest.w / 2);
            break;

        case ANCHOR_TOP_RIGHT:
            dest.x -= dest.w;
            break;

        case ANCHOR_CENTER_LEFT:
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_CENTER_CENTER:
            dest.x -= (dest.w / 2);
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_CENTER_RIGHT:
            dest.x -= dest.w;
            dest.y -= (dest.h / 2);
            break;

        case ANCHOR_BOTTOM_LEFT:
            dest.y -= dest.h;
            break;

        case ANCHOR_BOTTOM_CENTER:
            dest.x -= (dest.w / 2);
            dest.y -= dest.h;
            break;

        case ANCHOR_BOTTOM_RIGHT:
            dest.x -= dest.w;
            dest.y -= dest.h;
            break;

        default:
            break;
	}
	
    SDL_RenderCopy(app->renderer, texture, NULL, &dest);
    SDL_DestroyTexture(texture);
}
