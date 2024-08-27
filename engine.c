#include "main.h"

/**
 * main - Runs the programme
 */
int main(void)
{

	SDL_Resources res;

	sdl_init(&res);

	SDL_Event e;
	bool quit = false;

	/*Keeps the window open*/
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}
	}
	free_resource(&res);

	return (0);
}
