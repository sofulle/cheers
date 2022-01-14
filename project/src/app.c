// init.c

#include "cheers.h"

app_t *app_init(void) {
	app_t *app = NULL;
	int image_flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int window_flags = SDL_WINDOW_RESIZABLE;
	int renderer_flags = SDL_RENDERER_ACCELERATED;
	int mixer_flags = MIX_INIT_MP3 | MIX_INIT_OGG;

	// allocate memory for app struct
	app = (app_t *) malloc(sizeof(app_t));
	if (app == NULL) return NULL;
	memset(app, 0, sizeof(app_t));

	// SDL init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	// Set SDL hints
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

	// IMG init
	if ((IMG_Init(image_flags) & image_flags) != image_flags) {
		printf("IMG: Failed to init required jpg and png support!\n");
		printf("IMG: %s\n", SDL_GetError());
		exit(1);
	}
	
	// Set MIX default settings
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_AllocateChannels(8);

	// Create SDL window
	app->window = SDL_CreateWindow(APP_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, START_SCREEN_WIDTH, START_SCREEN_HEIGHT, window_flags);
	if (app->window == NULL) {
		printf("Failed to open %d x %d window: %s\n", START_SCREEN_WIDTH, START_SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	// Set window default settings
	SDL_SetWindowMinimumSize(app->window, START_SCREEN_WIDTH, START_SCREEN_HEIGHT);

	// Create SDL renderer for main app window
	app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);
	if (app->renderer == NULL) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	// TTF init
	if(TTF_Init() < 0) {
		printf("TTF: Failed to init!\n");
		printf("TTF: %s\n", SDL_GetError());
		exit(1);
	}

	// MIX init
	if ((Mix_Init(mixer_flags) & mixer_flags) != mixer_flags) {
		printf("MIX: Failed to init!\n");
		printf("MIX: %s\n", SDL_GetError());
		exit(1);
	}

	return app;
}

void app_quit(app_t *app) {
	free(app);
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
}