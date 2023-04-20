#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
extern int mark;
class MainObject : public BaseObject{
    public: 
        MainObject();
        ~MainObject();
        void handleEvent( SDL_Event& e );
        void move();
        void SetRect(const int& x, const int& y) { mPosX = x; mPosY = y; rect_.x = mPosX; rect_.y = mPosY; }
	    SDL_Rect GetRect() const { return { mPosX, mPosY, rect_.w, rect_.h }; }
        bool Ok();
        bool check();
        bool checkvel();
    private:
		double mVelX, mVelY;    
        SDL_Rect rect_;
        bool Hamom;
        int checkhamom;
};

#endif