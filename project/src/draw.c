// draw.c

#include "cheers.h"

SDL_Texture *render_texture(app_t *app, char *filename) {
	SDL_Texture *texture;

	texture = IMG_LoadTexture(app->renderer, filename);

	return texture;
}

SDL_Texture* render_text(app_t *app, char *message, char *font_file_name, SDL_Color color, int font_size) {
    TTF_Font *font = TTF_OpenFont(font_file_name, font_size);

    SDL_Surface *surf = TTF_RenderUTF8_Blended(font, message, color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surf);

    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
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

void draw_text(app_t *app, char *text, int x, int y, int size, anchor_t anchor) {
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Texture *image = render_text(app, text, "resource/fonts/font00.ttf", color, size);

    SDL_Rect dest;
	dest.x = x;
	dest.y = y;

    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);

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

    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app->renderer, image, NULL, &dest);
    SDL_DestroyTexture(image);
}