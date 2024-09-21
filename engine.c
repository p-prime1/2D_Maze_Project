#include "main.h"

/**
 * main - Runs the programme
 */


int main(void)
{

	int map[MAX_ROWS][MAX_COLS];
	int rows = 0, cols = 0;
	SDL_Resources res;
	Players_coordinates coordinates;
	coordinates.posX = 2;
	coordinates.posY = 2; /*Starting position*/
	coordinates.dirX = 1;
	coordinates.dirY = 0;
	coordinates.planeY = 0.66;
	coordinates.planeX = 0;

	parse_map("src/map.txt", map, &rows, &cols);

	sdl_init(&res);

	SDL_Event e;
	bool quit = false;
	

	/*Keeps the window open*/
	while (quit == false)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			/*User quits*/
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_UP:
					move_forward(&coordinates, map);
					break;
					
					case SDLK_DOWN:
					move_backward(&coordinates, map);
					break;

					case SDLK_LEFT:
					move_left(&coordinates);
					break;
					
					case SDLK_RIGHT:
					move_right(&coordinates);
					break;
				}
				
			}
		}
		SDL_RenderClear(res.renderer);
		ray_caster(&res, map, &coordinates);
	}
	free_resource(&res);

	return (0);
}

