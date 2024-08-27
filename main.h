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
 * @renderer: Window renderer
 * @surface: Surface to be rendered to
 * @Texture: Displayed texture
 */

typedef struct Resource
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	SDL_Texture *texture;
} SDL_Resources;

void free_resource(SDL_Resources *res);
int sdl_init(SDL_Resources *resources);
void sdl_renderer(SDL_Resources *res);

#endif
