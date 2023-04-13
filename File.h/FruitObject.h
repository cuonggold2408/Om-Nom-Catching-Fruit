#ifndef FRUIT_OBJECT_H
#define FRUIT_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define W_FRUIT 40
#define H_FRUIT 40

class FruitObject : public BaseObject
{
public:
	FruitObject();
	~FruitObject();

	void HandleMove(const int& x_border, const int& y_border);
	void set_y_val(const double& val) { y_val_ = val; }
	void Reset(const int& yboder);
	bool FruitExit(const int& ye);
	void SetRect(const int& x, const int& y) { mPosX = x; mPosY = y; rect_.x = mPosX; rect_.y = mPosY; }
	SDL_Rect GetRect() const { return rect_; }
private:
	int x_val_;
	double y_val_;
	SDL_Rect rect_;

};
#endif 