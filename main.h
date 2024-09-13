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
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 540


typedef struct coordinates
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
} Players_coordinates;

/**
 * struct Resource - Struct to hold SDL resources
 * @window: Window to be rendered to
 * @renderer: Window renderer
 * @surface: Surface to be rendered to
 * @Texture: Displayed texture
 */

typedef struct Resource
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	SDL_Texture *texture;

} SDL_Resources;
void free_resource(SDL_Resources *res);
int sdl_init(SDL_Resources *resources);
void ray_caster(SDL_Resources *res, int map[24][24], Players_coordinates *coordinates);
float degToRad(int a);
int FixAng(int a);
void move_left(Players_coordinates *cord);
void move_right(Players_coordinates *cord);
void move_forward(Players_coordinates *cord, int map[24][24]);
void move_backward(Players_coordinates *cord, int map[24][24]);

#endif
