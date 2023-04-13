#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class MainObject : public BaseObject{
    public: 
        MainObject();
        ~MainObject();
        void handleEvent( SDL_Event& e );
        void move();
        void SetRect(const int& x, const int& y) { mPosX = x; mPosY = y; rect_.x = mPosX; rect_.y = mPosY; }
	    SDL_Rect GetRect() const { return rect_; }

    private:
		double mVelX, mVelY;    
        SDL_Rect rect_;
};

#endif