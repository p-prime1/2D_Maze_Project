#include "main.h"

/**
 * minmap - Draws a minimap
 * @res: Struct that holds all the SDL resources
 * @map: The programme map
 * @cord: Struct that holds players coordinates
 */

void minmap(SDL_Resources *res, int map[24][24],
		Players_coordinates *cord)
{
	int minimap_size = 150, tile_size = minimap_size / COLS,
	    minimap_x = SCREEN_WIDTH - minimap_size - 10, minimap_y = 10;

	SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 255);
	for (int y = 0; y < ROWS; y++)
	{
		for (int x = 0; x < COLS; x++)
		{
			SDL_SetRenderDrawColor(res->renderer,
					map[y][x] == 1 ? 255 : 0, 255, 255, 255);
			SDL_Rect rect = {minimap_x + x * tile_size,
				minimap_y + y * tile_size, tile_size, tile_size};
			SDL_RenderFillRect(res->renderer, &rect);
		}
	}

	int player_minimap_x = minimap_x + (int)(cord->posX * tile_size),
	    player_minimap_y = minimap_y + (int)(cord->posY * tile_size);

	SDL_SetRenderDrawColor(res->renderer, 255, 0, 0, 255);
SDL_Rect player_rect = {player_minimap_x - tile_size / 4,
		player_minimap_y - tile_size / 4, tile_size / 2, tile_size / 2};
	SDL_RenderFillRect(res->renderer, &player_rect);
	int dir_length = 15;
	int dir_end_x = player_minimap_x + (int)(cord->dirX * dir_length);
	int dir_end_y = player_minimap_y + (int)(cord->dirY * dir_length);

	SDL_RenderDrawLine(res->renderer, player_minimap_x,
			player_minimap_y, dir_end_x, dir_end_y);
}
