#include "main.h"

/**
 * draw_minimap - Draws a minimap
 * @res: Struct that holds all the SDL resources
 * map: The programme map
 * @cord: Struct that holds players coordinates
 */

void draw_minimap(SDL_Resources *res, int map[24][24], Players_coordinates *cord)
{
	int minimap_size = 150;
	int tile_size = minimap_size / MAX_COLS; /*Scales down the map size*/
	int minimap_x = SCREEN_WIDTH - minimap_size - 10; /*Place the map at the top right corner*/
	int minimap_y = 10;

	/*Loop throught the map*/
	for (int y = 0; y < MAX_ROWS; y++)
	{
		for (int x = 0; x < MAX_COLS; x++)
		{
			/*Sets color based on if its an empty space or not*/
			if (map[y][x] == 1)
			{
				SDL_SetRenderDrawColor(res->renderer, 255, 255, 255, 255);
			}
			else
				SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 255);
			SDL_Rect rect = {minimap_x + x * tile_size, minimap_y + y * tile_size, tile_size, tile_size};
			SDL_RenderFillRect(res->renderer, &rect);
		}
	}

	int player_minimap_x = minimap_x + (int)(cord->posX * tile_size);
	int player_minimap_y = minimap_y + (int)(cord->posY * tile_size);
	SDL_SetRenderDrawColor(res->renderer, 255, 0, 0, 255);
	SDL_Rect player_rect = {player_minimap_x - tile_size / 4, player_minimap_y - tile_size / 4, tile_size / 2, tile_size / 2};
	SDL_RenderFillRect(res->renderer, &player_rect);

	/*Draw player direction*/
	int dir_length = 15;

	int dir_end_x = player_minimap_x + (int)(cord->dirX * dir_length);
	int dir_end_y = player_minimap_y + (int)(cord->dirY * dir_length);

	SDL_RenderDrawLine(res->renderer, player_minimap_x, player_minimap_y, dir_end_x, dir_end_y);
}
