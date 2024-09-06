#include "main.h"

/**
 * ray_caster - Funtion cast ray and returns perpendicular wall dist
 * @res: Struct containing all the SDL resources
 * @map: Map of the game
 * Return: Returns the height of line to be drawn
 */

int ray_caster(SDL_Resources *res, int map[10][10])
{
	(void)res;
	(void)map;
	double posX = 3.0, posY = 5.0; /* Starting position of the player */
	double dirX = -1.0, dirY = 0.0; /* Initial direction of vector */

	double planeX = 0.0, planeY = 0.66; /* Camera plane or FOV */
	double perpWallDist; /* Perpendicular wall distance */
	unsigned int screenWidth = SCREEN_WIDTH;
	unsigned int x;
	unsigned int screenHeight = SCREEN_HEIGHT;
	int mapX, mapY, lineHeight, hit, side;
	double rayDirX, rayDirY, stepX, stepY, cameraX, deltaDistX, deltaDistY;
	double sideDistX, sideDistY;

	SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 255);  // Clear screen with black
	SDL_RenderClear(res->renderer);


	for (x = 0; x < screenWidth; x++) /* Loop sweeps through the screeen */
	{
		cameraX = 2 * x / (double)screenWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);

		/*Position on the map*/
		mapX = (int)posX;
		mapY = (int)posY;

		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		hit = 0;

		/*Calculate step and initial sideDist*/
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		/*Perform DDA*/
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			/*Check if ray hit wall*/
			if (map[mapX][mapY] > 0)
				hit = 1;
		}
		/*Calculate perp wall disatance*/
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		/*Calculare height of line to dray on screen*/
		printf("perpWallDist: %f", perpWallDist);
		lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		unsigned int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		

		/*SDL_Color color = (SDL_Color){255, 0, 0, 255};*/
            SDL_Color color;
            switch (map[mapX][mapY]) {
                case 1:
                    color = (SDL_Color){255, 0, 0, 255};
                    break;
                default:
                    color = (SDL_Color){255, 255, 255, 255};
                    break;
	    }

        if (side == 1) 
	    {
                color.r /= 2;
                color.g /= 2;
                color.b /= 2;
        }
		printf("x: %u, drawStart: %d, drawEnd: %u\n", x, drawStart, drawEnd);

		if (SDL_SetRenderDrawColor(res->renderer, color.r, color.g, color.b, color.a) < 0)
			printf("RenderDraw color error: %s", SDL_GetError());
		if (SDL_RenderDrawLine(res->renderer, x, drawStart, x, drawEnd) < 0)
			printf("RenderDraw line error: %s", SDL_GetError());
	}
	SDL_RenderPresent(res->renderer);
	return (lineHeight);
}
