#include "CommonFunc.h"
#include "BaseObject.h"
#include "FruitObject.h"

FruitObject::FruitObject()
{
	mPosX = rand()%SCREEN_WIDTH;//rect_.x
	mPosY = -rand()%200;//rect_.y
	rect_.w = W_FRUIT;
	rect_.h = H_FRUIT;
	y_val_ = 0;
}

FruitObject::~FruitObject()
{
}

void FruitObject::HandleMove(const int& x_border, const int& y_border)
{
	mPosY  += 0.25*y_val_;

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

bool FruitObject::FruitExit(const int& ye)
{
	if (ye >= SCREEN_HEIGHT + 2)
	{
		return true;
	}
	return false;
}
