#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_render.h>
#include <math.h>

/*Screen Dimensions*/
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720
#define ROWS 24
#define COLS 24

/**
 * struct coordinates - Struct to hold the coordinates of the player
 * @posX: Position of the player on the x coordinate
 * @posY: Postion of the player on the y coordinate
 * @dirX: Direction of the ray on the X axis
 * @dirY: Direction of the ray on the y axis
 * @planeX: Camera plane on the x axis
 * @planeY: Camera plane on the y axis
 */
typedef struct coordinates
{
	double posX, posY;
	double dirX, dirY;
	double planeX;
	double planeY;
} Players_coordinates;

/**
 * struct Resource - Struct to hold SDL resources
 * @window: Window to be rendered to
 * @renderer: Window renderer
 * @surface: Surface to be rendered to
 * @texture: Displayed texture
 */

typedef struct Resource
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	SDL_Texture *texture;
} SDL_Resources;
void parse_map(const char *filename, int map[ROWS][COLS], int *rows,
		int *cols);
void free_resource(SDL_Resources *res);
int sdl_init(SDL_Resources *resources);
void ray_caster(SDL_Resources *res, int map[24][24],
		Players_coordinates *coord);
float degToRad(int a);
int FixAng(int a);
void move_left(Players_coordinates *cord);
void move_right(Players_coordinates *cord);
void move_forward(Players_coordinates *cord, int map[24][24]);
void move_backward(Players_coordinates *cord, int map[24][24]);
void minmap(SDL_Resources *res, int map[24][24], Players_coordinates *cord);
#endif
