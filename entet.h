#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#ifndef FFG_H_INCLUDED
#define FFG_H_INCLUDED
void scrolling_right(SDL_Rect *camera, SDL_Rect *position, const int cte);
void scrolling_left(SDL_Rect *camera, SDL_Rect *position, const int cte);
void scrolling_up(SDL_Rect *camera,SDL_Rect *position, const int cte);
void scrolling_down(SDL_Rect *camera, SDL_Rect *position, const int cte);




#endif //FFG_H_INCLUDED
