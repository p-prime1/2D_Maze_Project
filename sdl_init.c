#include "main.h"

/**
 * sdl_init - Initializes SDL and Creates a window
 * @resources: A struct conatining SDL resources
 * Return: Returns 0 on success or -1 on failure
 */

int sdl_init(SDL_Resources *resources)
{
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

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
	/*Get window surface*/
	surface = SDL_GetWindowSurface(window);
	/*Fill the surface with white*/
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0XFF, 0XFF, 0XFF));
	/*Update the surface*/
	SDL_UpdateWindowSurface(window);
	resources->surface = surface;

	return (0);
}
