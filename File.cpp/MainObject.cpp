#include "MainObject.h"
#include "BaseObject.h"

MainObject::MainObject(){
	mPosX = 0;
	mPosY = SCREEN_HEIGHT - 87;
    mVelX=0;
    mVelY=0;
    rect_.w = 90;
    rect_.h = 87;
}
MainObject::~MainObject(){

}
void MainObject::handleEvent( SDL_Event& e )
{

	//If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX -= 2*DOT_VEL; break;
            case SDLK_RIGHT: mVelX += 2*DOT_VEL; break;
            case SDLK_SPACE: loadFromFile("object.png");break;
        }
    }
	else if( e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX += 2*DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= 2*DOT_VEL; break;
            case SDLK_SPACE: loadFromFile("object1.png");break;
        }
    }
}

void MainObject::move()
{
	//Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
	mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}