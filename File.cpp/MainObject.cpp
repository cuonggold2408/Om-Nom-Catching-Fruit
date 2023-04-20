#include "MainObject.h"
#include "BaseObject.h"
#include <iostream>
MainObject::MainObject()
{
    mPosX = 0;
    mPosY = SCREEN_HEIGHT - 87;
    mVelX = 0;
    mVelY = 0;
    rect_.w = 90;
    rect_.h = 87;
    Hamom = false;
    checkhamom = 0;
}
MainObject::~MainObject()
{
}
void MainObject::handleEvent(SDL_Event &e)
{

    // If a key was pressed
    if (e.type == SDL_KEYDOWN)
    {
        // Adjust the velocity
        if (e.key.repeat == 0)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_LEFT:
                if (Hamom)
                {
                    checkhamom++;
                }

                mVelX -= 2 * DOT_VEL;
                break;
            case SDLK_RIGHT:
                if (Hamom)
                {
                    checkhamom++;
                }
                mVelX += 2 * DOT_VEL;
                break;
            case SDLK_SPACE:
                Hamom = true;
                if (Hamom)
                {
                    loadFromFile("object.png");
                    checkhamom++;
                }
                break;
            }
        }
        else
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_SPACE:
                loadFromFile("object.png");
                Hamom = false;
                mark--;
                // checkhamom--;
                break;
            }
        }
        // std::cout << checkhamom << "\n";  
    }


    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_LEFT:
        {
            if (Hamom)
            {
                checkhamom--;
            }
            mVelX += 2 * DOT_VEL;
            break;
        }
        case SDLK_RIGHT:
        {
            if (Hamom)
            {
                checkhamom--;
            }

            mVelX -= 2 * DOT_VEL;
            break;
        }
        case SDLK_SPACE:
            loadFromFile("object1.png");
            Hamom = false;
            checkhamom--;
            break;
        }
        // std::cout << checkhamom << "\n";
    }
}

void MainObject::move()
{
    // Move the dot left or right
    mPosX += mVelX;

    // If the dot went too far to the left or right
    if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH))
    {
        // Move back
        mPosX -= mVelX;
    }
}

bool MainObject::Ok()
{
    return Hamom;
}

bool MainObject::check()
{
    if (checkhamom >= 10 || checkhamom < 0)
    {
        checkhamom = 0;
        return 1;
    }
    return 0;
}

bool MainObject::checkvel()
{
    if(mVelX != 0){
        mVelX = 0;
        return 1;
    }
    if(mVelY != 0){
        mVelY = 0;
        return 1;
    }
    return 0;
}