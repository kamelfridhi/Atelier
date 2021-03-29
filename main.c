#include "entet.h"

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen, *background, *image, *per;
    screen = SDL_SetVideoMode(1024, 600, 32, SDL_SWSURFACE);

    bool running = true;
    const int FPS = 25;
    const int speed = 30;
    Uint32 start;
    background =IMG_Load("back.jpg");
    per=IMG_Load("per.png");
    SDL_SetColorKey(background, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0x00, 0xff, 0xff));
    SDL_Rect camera, positionper;
    camera.x = 0;
    camera.y = 350;
    camera.w = 1024;
    camera.h = 600;
    positionper.x=0;
    positionper.y=300;
    /*camera.x = 0;
    camera.y = 0;
    camera.w = 700;
    camera.h = 224;
    positionper.x=0;
    positionper.y=150;*/
    bool b[4] = {0,0,0,0};
    while(running) {
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=1;
                            break;
                        case SDLK_DOWN :
                            b[3] = 1;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 1;
                            break;
                        case SDLK_LEFT:
                            b[1] = 1;
                            break;
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=0;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 0;
                            break;
                        case SDLK_LEFT:
                            b[1] = 0;
                            break;
                        case SDLK_DOWN :
                            b[3] = 0;
                            break;
                            
                    }
                    break;
            }
        }
        if(b[0])
        {
          scrolling_right(&camera,&positionper,speed);
        }
        else if(b[1])
        {
          scrolling_left(&camera,&positionper,speed);
          
        }
        else if(b[2])
        {
          scrolling_up(&camera,&positionper,speed);
        }
        else if(b[3])
        {
          scrolling_down(&camera,&positionper,speed);
        }
        SDL_BlitSurface(background, &camera, screen, NULL);
        SDL_BlitSurface(per,NULL,screen,&positionper);

        SDL_Flip(screen);
        if(1000/FPS > SDL_GetTicks()-start) {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));// tayah l'usage taa proc
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(per);
    SDL_Quit();
    return 0;
}
