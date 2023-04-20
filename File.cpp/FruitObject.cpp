#include "CommonFunc.h"
#include "BaseObject.h"
#include "FruitObject.h"

FruitObject::FruitObject()
{
	mPosX = rand()%SCREEN_WIDTH;//rect_.x
	mPosY = 0;//rect_.y
	rect_.w = W_FRUIT;
	rect_.h = H_FRUIT;
	y_val_ = 0;
}

FruitObject::~FruitObject()
{
}

void FruitObject::HandleMove(const int& x_border, const int& y_border)
{
	mPosY  += 0.5*y_val_;

	if (mPosY  > SCREEN_HEIGHT + 20)
	{
		Reset(y_border);
	}

}

void FruitObject::Reset(const int& yboder)
{
	mPosY  = 0 - rand()%200;

	int rand_x = rand() % 500;
	if (rand_x > SCREEN_WIDTH)
	{
		rand_x = (int)(SCREEN_WIDTH * 0.5);
	}
	mPosX = rand_x;
}

bool FruitObject::checkfruit()
{
	if(mPosY!=0){
		mPosY=0;
		return 1;
	}
	if(mPosX!=0){
		mPosX = rand()%SCREEN_WIDTH;
		return 1;
	}
	return 0;
}

