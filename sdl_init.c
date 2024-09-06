#include "main.h"

/**
 * sdl_init - Initializes SDL and Creates a window
 * @resources: A struct conatining SDL resources
 * Return: Returns 0 on success or -1 on failure
 */

int sdl_init(SDL_Resources *resources)
{
	SDL_Window *window = NULL;
	/*SDL_Surface *surface = NULL;*/
	SDL_Renderer *renderer;

	/*Initialize SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return (-1);
	}
	/*Create window*/
	window = SDL_CreateWindow("2D_Maze Game", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return (-1);
	}



	resources->window = window;

	/*Create render for window*/
	renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	/*Checks if render was successfull*/
	if (renderer == NULL)
		printf("Failed to create render! SDL_Error: %s\n", SDL_GetError());
	/*Initialize render colour*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0XFF, 0XFF, 0XFF);
	resources->renderer = renderer;


	resources->window = window;
	return (0);
}
