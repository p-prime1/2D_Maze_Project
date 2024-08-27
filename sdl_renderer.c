#include "main.h"

/**
 * sdl_renderer - Renders texture using hardware based rendering
 * @res: Stuct containing all SDL resource
 */

void sdl_renderer(SDL_Resources *res)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	window = res->window;

	/*Create render for window*/
	renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	/*Checks if render was successfull*/
	if (renderer == NULL)
		printf("Failed to create render! SDL_Error: %s\n", SDL_GetError());
	/*Initialize render colour*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0XFF, 0XFF, 0XFF);
	res->renderer = renderer;

}

