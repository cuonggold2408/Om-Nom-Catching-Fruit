//dinh nghia cac thong so
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <SDL_mixer.h>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

extern SDL_Event g_event;
extern TTF_Font* gFont;
extern TTF_Font* gFont1;
extern TTF_Font* gFontTime;
extern SDL_Surface* gMark;

//The music that will be played
extern Mix_Music *gMusic;

// extern Mix_Music *gMusic
extern Mix_Chunk *gBomb;
extern Mix_Chunk *geatfruit;
extern Mix_Chunk *gdied;
// extern Mix_Chunk *gLow
//Screen
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B =255;
const int COLOR_KEY_A =255;

//Screen dimension constants
const int DOT_HEIGHT = 87;
const int DOT_WIDTH = 90;
const double DOT_VEL = 2;

const int RENDER_DRAW_COLOR = 0xff; // 255

namespace SDLGame{
    bool CheckCollision( SDL_Rect object1,  SDL_Rect object2);
}

#endif