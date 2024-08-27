#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_render.h>

/*Screen Dimensions*/
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/**
 * struct Resource - Struct to hold SDL resources
 * @window: Window to be rendered to
 * @renderer: Rendered to
 * @surface: Surface to be rendered to
 */

typedef struct Resource
{
	SDL_Window *window;
	SDL_Window *renderer;
	SDL_Surface *surface;
} SDL_Resources;

void free_resource(SDL_Resources *res);
int sdl_init(SDL_Resources *resources);

#endif
