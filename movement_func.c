#include "main.h"

/**
 * move_forward - Move player forward
 * @cord: Players coordinate
 * @map: map
 */
void move_forward(Players_coordinates *cord, int map[24][24])
{
	double moveSpeed = 0.15;
	/*double playerRadius= 1;*/

	/*Check if there's a collision in the X direction*/
	if (!(map[(int)(cord->posX + cord->dirX * moveSpeed)][(int)cord->posY]))
		cord->posX += cord->dirX * moveSpeed;

	else if (!(map[(int)cord->posX][(int)(cord->posY + cord->dirY * moveSpeed)]))
		cord->posY += cord->dirY * moveSpeed;

	/*Check for collision in the Y direction*/
	if (!(map[(int)cord->posX][(int)(cord->posY + cord->dirY * moveSpeed)]))
		cord->posY += cord->dirY * moveSpeed;
	else if (!(map[(int)(cord->posX + cord->dirY * moveSpeed)][(int)cord->posY]))
		cord->posX += cord->dirX * moveSpeed;
}

/**
 * move_backward - move player backward
 * @cord: players coordinate
 * @map: map
 */
void move_backward(Players_coordinates *cord, int map[24][24])
{
	double moveSpeed = 0.15;
	/*double playerRadius = 1;*/

	if (!(map[(int)(cord->posX - cord->dirX * moveSpeed)][(int)cord->posY]))
		cord->posX -= cord->dirX * moveSpeed;
	else if (!(map[(int)cord->posX][(int)(cord->posY - cord->dirY * moveSpeed)]))
		cord->posY -= cord->dirY * moveSpeed;
	if (!(map[(int)cord->posX][(int)(cord->posY - cord->dirY * moveSpeed)]))
		cord->posY -= cord->dirY * moveSpeed;
	else if (!(map[(int)(cord->posX - cord->dirX * moveSpeed)][(int)cord->posY]))
		cord->posX -= cord->dirX * moveSpeed;
}

/**
 * move_left - move player left
 * @cord: Players coordinates
 */

void move_left(Players_coordinates *cord)
{
	double rotSpeed = -0.05;
	double dirX = cord->dirX;
	double dirY = cord->dirY;
	double planeY = cord->planeY;
	double planeX = cord->planeX;
	double oldDirX = dirX;

	cord->dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	cord->dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	double oldPlaneX = planeX;

	cord->planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	cord->planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
}

/**
 * move_right - moves player right
 * @cord: Players coordinates
 */

void move_right(Players_coordinates *cord)
{
	double rotSpeed = -0.05;
	double dirX = cord->dirX;
	double dirY = cord->dirY;
	double oldDirX = dirX;
	double planeX = cord->planeX;
	double planeY = cord->planeY;

	cord->dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	cord->dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	double oldPlaneX = planeX;

	cord->planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	cord->planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
}

