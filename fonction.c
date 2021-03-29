#include "entet.h"
void scrolling_right(SDL_Rect *camera, SDL_Rect *position, const int cte)
{
  position->x+=1;
  camera->x += cte;
  if(camera->x >=8704-1024) 
  {
    camera->x = 0;
    position->x=0;
  }
}

void scrolling_left(SDL_Rect *camera, SDL_Rect *position, const int cte)
{
  position->x-= 15; 
  camera->x -= cte;
  if(camera->x <= 0)
  {
    camera->x = 0;

  }
}
void scrolling_up(SDL_Rect *camera,SDL_Rect *position, const int cte)
{
  
  position->y-=15; 
  //camera->y-=cte;
  /*if(camera->y<=0)
  {
    camera->y=1128-300;*/
    if(position->y=200)  
  {
  /*position->x+=1;*/
  position->y=30;
  camera->x += cte;
  //position->y=300;
     //camera->y = 350;
    //position->y=300;  scrolling_up(&camera,&positionper,speed);
  }
}
void scrolling_down(SDL_Rect *camera, SDL_Rect *position, const int cte)
{
  position->y+=300;  
  //camera->y+=cte;
  /*if(camera->y>=300) //img_height-screen_height
  {
    camera->y=0;
  }*/
  if(position->y >= 300)
  {
    //camera->y = 300;
    position->y=300;

  }
}

