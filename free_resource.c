#include "main.h"

/**
 * free_resource - Function frees all resources used by the program
 * @res: Struct containing all resources used by the progrma
 */

void free_resource(SDL_Resources *res)
{
	/*Destroys window if it exist*/
	if (res->window != NULL)
	{
		SDL_DestroyWindow(res->window);
		res->window = NULL;
	}

	/*Quits sdl subsytems*/
	SDL_Quit();
}
