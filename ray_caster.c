#include "main.h"

/**
 * ray_caster - Funtion cast ray and returns perpendicular wall dist
 * @res: Struct containing all the SDL resources
 * @map: Map of the game
 * Return: Returns the height of line to be drawn
 */

void ray_caster(SDL_Resources *res, int map[24][24])
{
	double planeX = 0.0, planeY = 0.66; /* Camera plane or FOV */
	int posX = 5, posY = 11; /*Starting position*/
	double dirX = -1, dirY = 0;
	double perpWallDist; /* Perpendicular wall distance */
	int screenWidth = SCREEN_WIDTH;
	int screenHeight = SCREEN_HEIGHT;
	int mapX, mapY, lineHeight, hit, side, x;
	double rayDirX, rayDirY, stepX, stepY, cameraX, deltaDistX, deltaDistY;
	double sideDistX, sideDistY;
	for (x = 0; x < screenWidth - 1; x++)
	{
		cameraX = 2 * x / (double)screenWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		mapX = (int)posX;
		mapY = (int)posY;
		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		hit = 0;
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
			sideDistY = (mapY + 1.0 - posX) * deltaDistX;
		}
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
			if (map[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
		{
			perpWallDist = (sideDistY - deltaDistY);
		}
		if (perpWallDist <= 0)
			perpWallDist = 0.1;
		int drawStart, drawEnd;
		/*Calculate height of line to draw on screen*/
		lineHeight = (int)(screenHeight / perpWallDist);
		/*Calculate lowest and highest pixel to fill in current stripe*/
		drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		/*Set Wall color*/
		SDL_SetRenderDrawColor(res->renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(res->renderer, x, drawStart, x, drawEnd);
	}
	SDL_RenderPresent(res->renderer);
}

