#include "SDLDisplay.hpp"

using namespace std;

SDLDisplay::SDLDisplay(const char *name, int width, int height, Uint32 flag)
:window(NULL), renderer(NULL), surface(NULL), texture(NULL)
{
    if( 0 != SDL_Init(SDL_INIT_VIDEO)){
        fprintf(stderr,"Erreur SDL_Init : %s", SDL_GetError());
        cleanRessources();
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag);

    if(window == NULL){
        fprintf(stderr,"Erreur SDL_CreateWindow : %s", SDL_GetError());
        cleanRessources();
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL){
        fprintf(stderr,"Erreur SDL_CreateRenderer : %s", SDL_GetError());
        cleanRessources();
        exit(EXIT_FAILURE);
    }


}

SDLDisplay::~SDLDisplay()
{
    cleanSurfaceAndTexture();
    cleanRessources();
}

void SDLDisplay::cleanRessources()
{
    if(renderer != NULL){
        SDL_DestroyRenderer(renderer);
    }

    if(window != NULL){
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

void SDLDisplay::cleanSurfaceAndTexture()
{
    if(surface  == NULL){
        //cout << "NULL SURFACE" << endl;
    }
    if(texture == NULL){
        //cout << "NULL texture" << endl;
    }
    if(surface != NULL){
        SDL_FreeSurface(surface);
        surface = NULL;
    }
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void SDLDisplay::clearScreen()
{
    cleanSurfaceAndTexture();
    if(0 != SDL_RenderClear(renderer)){
        fprintf(stderr,"Erreur SDL_RenderClear : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
}

void SDLDisplay::refreshScreen()
{
    if(0 != SDL_SetRenderDrawColor(renderer,0,0,0,255)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
    SDL_RenderPresent(renderer);
}

void SDLDisplay::putRect(int xpos, int ypos, int width, int height, SDLColors color)
{
    if(0 != SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a)){
        fprintf(stderr,"Erreur SDL_SetRenderDrawColor : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
    rect.x = xpos;
    rect.y = ypos;
    rect.h = height;
    rect.w = width;
    if(0 != SDL_RenderFillRect(renderer,&rect)){
        fprintf(stderr,"Erreur SDL_RenderDrawRect : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
}

void SDLDisplay::putImage(int xpos, int ypos, const char *imgDirectory, int width, int height)
{
    //cout << "Ici je load la surface" << endl;
    surface = IMG_Load(imgDirectory);
    if(surface == NULL){
        fprintf(stderr,"Erreur IMG_Load : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
    //cout << "Ici je met la surface sur une texture" << endl;
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    //cout << "Ici je clean la surface" << endl;
    SDL_FreeSurface(surface);
    surface = NULL;
    if(texture == NULL){
        fprintf(stderr,"Erreur SDL_CreateTexture : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }

    textureRect = {xpos,ypos};
    if(width != 0 and height != 0){
        textureRect.w = width;
        textureRect.h = height;
    }
    /*if(0 != SDL_QueryTexture(texture,NULL,NULL,&textureRect.w,&textureRect.h)){
        fprintf(stderr,"Erreur SDL_QueryTexture : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }*/

    if(0 != SDL_RenderCopy(renderer,texture,NULL,&textureRect)){
        fprintf(stderr,"Erreur SDL_RenderCopy : %s",SDL_GetError());
        cleanSurfaceAndTexture();
        cleanRessources();
        exit(EXIT_FAILURE);
    }
}
