#include "main.h"

/**
 * ray_caster - Funtion cast ray and returns perpendicular wall dist
 * @res: Struct containing all the SDL resources
 * @map: Map of the game
 * Return: Returns the height of line to be drawn
 */

int ray_caster(SDL_Resources *res, int map[24][24])
{
	(void)res;
	(void)map;
	double posX = 22, posY = 12; /* Starting position of the player */
	double dirX = -1.0, dirY = 0.0; /* Initial direction of vector */

	double planeX = 0.0, planeY = 0.66; /* Camera plane or FOV */
	double perpWallDist; /* Perpendicular wall distance */
	unsigned int screenWidth = SCREEN_WIDTH;
	unsigned int x;
	unsigned int screenHeight = SCREEN_HEIGHT;
	int mapX, mapY, lineHeight, hit, side;
	double rayDirX, rayDirY, stepX, stepY, cameraX, deltaDistX, deltaDistY;
	double sideDistX, sideDistY;

	for (x = 0; x < screenWidth; x++) /* Loop sweeps through the screeen */
	{
		cameraX = 2 * (double)screenWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

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
			stepX = 1;
			sideDistY = (mapY + 1.0 - posX) * deltaDistX;
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
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		/*Calculare height of line to dray on screen*/
		lineHeight = (int)(screenHeight / perpWallDist);
	}
	return (lineHeight);
}
