#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"

// Texture wrapper class
class BaseObject
{
public:
	// Initializes variables
	BaseObject();

	// Deallocates memory
	~BaseObject();

	// Loads image at specified path
	bool loadFromFile(std::string path);

	// Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	// Deallocates texture
	void free();

	// Renders texture at given point
	void render(int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int get_mPosX() { return mPosX; }
	int get_mPosY() { return mPosY; }

	// Gets image dimensions
	int getWidth();
	int getHeight();
	// void SetRect(const int& x, const int& y) { mPosX = x; mPosY = y; mCollider.x = mPosX; mCollider.y = mPosY; }
	// SDL_Rect getRect(){
	// 	return mCollider;
	// }
	void SetRect(const int &x, const int &y)
	{
		mPosX = x;
		mPosY = y;
		rect_.x = mPosX;
		rect_.y = mPosY;
	}
	SDL_Rect GetRect() const { return rect_; }

protected:
	// The actual hardware texture
	SDL_Texture *mTexture;
	double mPosX, mPosY;
	// SDL_Rect mCollider;
	// Image dimensions
	int mWidth;
	int mHeight;
	SDL_Rect rect_;
};

#endif