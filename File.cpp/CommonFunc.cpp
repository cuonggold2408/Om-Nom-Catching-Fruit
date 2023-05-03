#include "CommonFunc.h"

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Event g_event;

TTF_Font* gFont = NULL;
TTF_Font* gFont1 = NULL;
TTF_Font* gFontTime = NULL;

SDL_Surface* gMark = NULL;

Mix_Music *gMusic = NULL;

// Mix_Music *gMusic = NULL;
Mix_Chunk *gBomb = NULL;
Mix_Chunk *geatfruit = NULL;
Mix_Chunk *gdied = NULL;
// Mix_Chunk *gMedium = NULL;
// Mix_Chunk *gLow = NULL;

int mark = 0;

bool SDLGame::CheckCollision(const SDL_Rect a, const SDL_Rect b)
{
	int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}