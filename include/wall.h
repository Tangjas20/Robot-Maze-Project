#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"

// Conditional compilation directives to ensure the right "include" path for Windows or Unix is used
#ifdef _WIN32
    #include "include\SDL2\SDL.h"
    #include "SDL2_gfx\SDL2_gfxPrimitives.h"
#else
    #include "SDL2/SDL.h"
    #include "SDL2/SDL2_gfxPrimitives.h"
#endif

#include "structures.h"

void wallSetPosition(struct Wall * wall, int x, int y, int width, int height);
void wallUpdate(SDL_Renderer * renderer, struct Wall * wall);

void insertFirstWall(struct Wall_collection ** head, int key, struct Wall * wall);
void insertAndSetFirstWall(struct Wall_collection ** head, int key, int x, int y, int width, int height);
void updateAllWalls(struct Wall_collection * head, SDL_Renderer * renderer);
void horizontalwall(struct Wall_collection ** head,int length,int startx,int starty,int gorightanddown);
int insertAndSetDiagonalWall(struct Wall_collection ** head, int key, int x1, int y1, int x2, int y2);
#endif // WALL_H_INCLUDED
