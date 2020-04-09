#ifndef __LIBS__
#define __LIBS__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <memory>

#endif

#ifndef __DISPLAY__
#define __DISPLAY__

using namespace std;

typedef struct SDLColors {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

class SDLDisplay
{
public:
    SDLDisplay(const char *name, int width, int height, Uint32 flag);
    ~SDLDisplay();
    void putRect(int xpos, int ypos, int width, int height, SDLColors color);
    void putImage(int xpos, int ypos, const char *imgDirectory, int width = 0, int height = 0);
    void clearScreen();
    void refreshScreen();
    void cleanRessources();
    void cleanSurfaceAndTexture();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect rect;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect textureRect;
};

#endif
