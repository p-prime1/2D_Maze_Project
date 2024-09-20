#include "main.h"

/**
 * move_forward - Move player forward
 * @cord: Players coordinate
 * @map: map
 */
void move_forward(Players_coordinates *cord, int map[24][24])
{
	double moveSpeed = 0.5;
	
	/*Check if there's a collision in the X direction*/
	if (map[(int)(cord->posX + cord->dirX * moveSpeed)][(int)cord->posY] == 0)
		cord->posX += cord->dirX * moveSpeed;

	else if (map[(int)cord->posX][(int)(cord->posY + cord->dirY * moveSpeed)] == 0)
		cord->posY += cord->dirY * moveSpeed;

	/*Check for collision in the Y direction*/
	if (map[(int)cord->posX][(int)(cord->posY + cord->dirY * moveSpeed)] == 0)
		cord->posY += cord->dirY * moveSpeed;
	else if (map[(int)(cord->posX + cord->dirY * moveSpeed)][(int)cord->posY]== 0)
		cord->posX += cord->dirX * moveSpeed;
}

/**
 * move_backward - move player backward
 * @cord: players coordinate
 * @map: map
 */
void move_backward(Players_coordinates *cord, int map[24][24])
{
	double moveSpeed = 0.5;

	if (map[(int)(cord->posX - cord->dirX * moveSpeed)][(int)cord->posY] == 0)
		cord->posX -= cord->dirX * moveSpeed;
	else if (map[(int)(cord->posX)][(int)(cord->posY - cord->dirY * moveSpeed)] == 0)
		cord->posY -= cord->dirY * moveSpeed;
	if (map[(int)cord->posX][(int)(cord->posY - cord->dirY * moveSpeed)] == 0)
		cord->posY -= cord->dirY * moveSpeed;
	else if (map[(int)(cord->posX - cord->dirX * moveSpeed)][(int)cord->posY] == 0)
		cord->posX -= cord->dirX * moveSpeed;
}

/**
 * move_left - move player left
 * @cord: Players coordinates
 */

void move_left(Players_coordinates *cord)
{
	double rotSpeed = 0.05;
	double dirX = cord->dirX;
	double dirY = cord->dirY;
	double planeY = cord->planeY;
	double planeX = cord->planeX;
	double oldDirX = dirX;

	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	double oldPlaneX = planeX;

	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	cord->planeX = planeX;
	cord->planeY = planeY;
	cord->dirX = dirX;
	cord->dirY = dirY;
}

/**
 * move_right - moves player right
 * @cord: Players coordinates
 */

void move_right(Players_coordinates *cord)
{
	double rotSpeed = 0.05;
	double dirX = cord->dirX;
	double dirY = cord->dirY;
	double oldDirX = dirX;
	double planeX = cord->planeX;
	double planeY = cord->planeY;

	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	double oldPlaneX = planeX;

	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	cord->planeX = planeX;
	cord->planeY = planeY;
	cord->dirX = dirX;
	cord->dirY = dirY;
}

