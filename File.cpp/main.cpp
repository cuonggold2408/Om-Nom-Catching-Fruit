#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "FruitObject.h"
#include <iostream>
SDL_Color gTextColor = {0x00, 0x00, 0x00};
SDL_Color gTextColormark = {0xFF, 0x00, 0x00};
const int itemGame_over = 2;
const int itemMenu = 2;
// Scene textures

BaseObject gBackgroundTexture;
BaseObject gTextTexture;
BaseObject bkgameover;
BaseObject bkMENU;
BaseObject g_icon;
BaseObject pts;
BaseObject g_bkground;
MainObject gMain;
MainObject icon1;
MainObject icon2;
MainObject icon3;
FruitObject *p_fruit_melon = new FruitObject();
FruitObject *p_fruit_bom = new FruitObject();
FruitObject *p_fruit_nho = new FruitObject();
FruitObject *p_fruit_star = new FruitObject();
FruitObject *p_fruit_cherry = new FruitObject();
int mark = 0;
int count_die = 0;


class TextObject : public BaseObject
{
    public:
    enum
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };
    SDL_Color GetColor(){return text_color;}
    void SetColor(const int& type);
    // bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
	// bool loadFromFile(std::string path);
    // void free();
    void confirmOx_Oy(int x, int y){Ox = x;Oy = y;}
    int getOx(){return Ox;}
    int getOy(){return Oy;}
    SDL_Rect getRect(){return hcn;}
    void SetRect()
    {
        hcn.x = Ox;
        hcn.y = Oy;
        hcn.w = mWidth;
        hcn.h = mHeight;
    }
    // bool render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    private:
    std::string str;
    SDL_Color text_color;
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
    int Ox, Oy;
    SDL_Rect hcn;
};
// void TextObject::free()
// {
//     // Free texture if it exists
//     if (mTexture != NULL)
//     {
//         SDL_DestroyTexture(mTexture);
//         mTexture = NULL;
//         mWidth = 0;
//         mHeight = 0;
//     }
// }
// bool TextObject::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
// {
//     //Set rendering space and render to screen
//     SDL_Rect renderQuad = { x, y, mWidth, mHeight };

//     //Set clip rendering dimensions
//     if( clip != NULL )
//     {
//         renderQuad.w = clip->w;
//         renderQuad.h = clip->h;
//     }

//     //Render to screen
//     SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
// }
// bool TextObject::loadFromRenderedText( std::string textureText, SDL_Color textColor )
// {
    //Get rid of preexisting texture
    

    //Render text surface
//     SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
//     if( textSurface == NULL )
//     {
//         printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
//     }
//     else
//     {
//         //Create texture from surface pixels
//         mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
//         if( mTexture == NULL )
//         {
//             printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
//         }
//         else
//         {
//             //Get image dimensions
//             mWidth = textSurface->w;
//             mHeight = textSurface->h;
//         }

//         //Get rid of old surface
//         SDL_FreeSurface( textSurface );
//     }
    
//     //Return success
//     return mTexture != NULL;
// }
void TextObject::SetColor(const int& type)
{
    if(type == RED_TEXT)
    {
        text_color = {255, 0, 0};
    }
    else if(type == WHITE_TEXT)
    {
        text_color = {255, 255, 255};
    }
    else if(type == BLACK_TEXT)
    {
        text_color = {0, 0, 0};
    }
}
// bool TextObject::loadFromFile(std::string path)
// {
//     // Get rid of preexisting texture
//     free();

//     // The final texture
//     SDL_Texture *newTexture = NULL;

//     // Load image at specified path
//     SDL_Surface *loadedSurface = IMG_Load(path.c_str());
//     if (loadedSurface == NULL)
//     {
//         printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//     }
//     else
//     {
//         // Color key image
//         SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGBA(loadedSurface->format, 0xFF, 0xFF, 0xFF, 0xFF));

//         // Create texture from surface pixels
//         newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//         if (newTexture == NULL)
//         {
//             printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//         }
//         else
//         {
//             // Get image dimensions
//             mWidth = loadedSurface->w;
//             mHeight = loadedSurface->h;
//         }

//         // Get rid of old loaded surface
//         SDL_FreeSurface(loadedSurface);
//     }

//     // Return success
//     mTexture = newTexture;
//     return mTexture != NULL;
// }

bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

bool init()
{
	// srand(time(0));

	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				// Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// Loading success flag
	bool success = true;

	// Load background texture

	if (!gBackgroundTexture.loadFromFile("background1.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	// Load background texture
	if (!gMain.loadFromFile("object1.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!icon1.loadFromFile("heart.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!bkMENU.loadFromFile("bkopen.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!icon2.loadFromFile("heart.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!icon3.loadFromFile("heart.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!bkgameover.loadFromFile("backgroundexit.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!pts.loadFromFile("pts1.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!p_fruit_melon->loadFromFile("melon.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!p_fruit_bom->loadFromFile("bom.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!p_fruit_nho->loadFromFile("nho.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!p_fruit_star->loadFromFile("star.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!p_fruit_cherry->loadFromFile("cherry.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	gFont = TTF_OpenFont("lazy.ttf", 28);
	gFontTime = TTF_OpenFont("lazy.ttf", 20);
	if (gFont == NULL || gFontTime == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		// Render text
		SDL_Color textColor = {0, 0, 0};
		if (!gTextTexture.loadFromRenderedText("Mark = ", textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}
	return success;
}

void close()
{
	// Free loaded images
	gBackgroundTexture.free();

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
bool checkpositionforrect(const int& x, const int& y, SDL_Rect rect)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
        return false;
}
int showGameover(SDL_Event e)
{
    SDL_Rect item[itemGame_over];
    item[0].x = 200;
    item[0].y = 400;
    item[1].x = 200;
    item[1].y = 450;

    int x, y;
    TextObject text_menu[itemGame_over];
    text_menu[0].SetColor(1);
    text_menu[0].loadFromRenderedText("Play new",text_menu[0].GetColor());
    text_menu[0].confirmOx_Oy(item[0].x, item[0].y);
    text_menu[0].SetRect();

    text_menu[1].SetColor(1);
    text_menu[1].loadFromRenderedText("Exit",text_menu[1].GetColor());
    text_menu[1].confirmOx_Oy(item[1].x, item[1].y);
    text_menu[1].SetRect();

    bool Selected[itemGame_over] = {0, 0};
    bool quit = false;
    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                quit = true;
                break;
                case SDL_MOUSEMOTION:
                {
                    SDL_GetMouseState( &x, &y );
                    for(int i = 0; i < itemGame_over; i++)
                    {
                        if(checkpositionforrect(x, y, text_menu[i].getRect()))
                        {
                            if(Selected[i] == 0)
                            {
                                Selected[i] = 1;
                                text_menu[i].SetColor(2);
                            }
                        }
                        else
                        {
                            if(Selected[i] == 1)
                            {
                                Selected[i] = 0;
                                text_menu[i].SetColor(1);
                                
                            }
                        }
                    }
                }
                break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    SDL_GetMouseState( &x, &y );
                    for(int i = 0; i < itemGame_over; i++)
                    {
                        if(checkpositionforrect(x, y, text_menu[i].getRect()))
                        {
                            return i;
                        }
                    }
                }
                break;
                case SDL_KEYDOWN:
                {
                    if(e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return 1;
                    }
                }
                default:
                break;
            }
        }
        SDL_RenderClear( gRenderer );

        bkgameover.render(0, 0);
        for(int i = 0; i < itemGame_over; i++)
        {
            if(i == 0) text_menu[i].loadFromRenderedText("Play new",text_menu[i].GetColor());
            if(i == 1) text_menu[i].loadFromRenderedText("Exit",text_menu[i].GetColor());
            text_menu[i].render(text_menu[i].getOx(), text_menu[i].getOy());
        }

        SDL_RenderPresent(gRenderer);
    }
    return 1;
}
int showMenu(SDL_Event e)
{
    SDL_Rect item[itemMenu];
    item[0].x = 146;
    item[0].y = 238;
    item[1].x = 150;
    item[1].y = 350;

    int x, y;
    TextObject text_menu[itemMenu];
    text_menu[0].SetColor(0);
    // text_menu[0].loadFromRenderedText("Play Game",text_menu[0].GetColor());
	text_menu[0].loadFromFile("pts1.png");
    text_menu[0].confirmOx_Oy(item[0].x, item[0].y);
    text_menu[0].SetRect();

    text_menu[1].SetColor(0);
    text_menu[1].loadFromRenderedText("Exit",text_menu[1].GetColor());
    text_menu[1].confirmOx_Oy(item[1].x, item[1].y);
    text_menu[1].SetRect();

    bool Selected[itemMenu] = {0, 0};
    bool quit = false;
    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                quit = true;
                break;
                case SDL_MOUSEMOTION:
                {
                    SDL_GetMouseState( &x, &y );
                    for(int i = 0; i < itemMenu; i++)
                    {
                        if(checkpositionforrect(x, y, text_menu[i].getRect()))
                        {
                            if(Selected[i] == 0)
                            {
                                Selected[i] = 1;
                                text_menu[i].SetColor(2);
                            }
                        }
                        else
                        {
                            if(Selected[i] == 1)
                            {
                                Selected[i] = 0;
                                text_menu[i].SetColor(0);
                                
                            }
                        }
                    }
                }
                break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    SDL_GetMouseState( &x, &y );
                    for(int i = 0; i < itemMenu; i++)
                    {
                        if(checkpositionforrect(x, y, text_menu[i].getRect()))
                        {
                            return i;
                        }
                    }
                }
                break;
                case SDL_KEYDOWN:
                {
                    if(e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return 1;
                    }
                }
                default:
                break;
            }
        }
        SDL_RenderClear( gRenderer );

        bkMENU.render(0, 0);
        for(int i = 0; i < itemMenu; i++)
        {
            // if(i == 0) text_menu[i].loadFromRenderedText("Play Game",text_menu[i].GetColor());
			if(i == 0) text_menu[i].loadFromFile("pts1.png");
            if(i == 1) text_menu[i].loadFromRenderedText("Exit",text_menu[i].GetColor());
            text_menu[i].render(text_menu[i].getOx(), text_menu[i].getOy());
        }

        SDL_RenderPresent(gRenderer);
    }
    return 1;
}


int main(int argc, char *args[])
{
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;


			// khoi tao menu ban dau vao game
			int check = showMenu(e);
			if(check) quit = true;
			else quit = false;
			// ket thuc ham khoi tao menu


			while (!quit)
			{
				// Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					gMain.handleEvent(e);
				}

				gMain.move();
				p_fruit_melon->set_y_val(rand() % 10);
				p_fruit_melon->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fruit_bom->set_y_val(rand() % 8);
				p_fruit_bom->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fruit_nho->set_y_val(rand() % 10);
				p_fruit_nho->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fruit_star->set_y_val(rand() % 5);
				p_fruit_star->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fruit_cherry->set_y_val(rand() % 10);
				p_fruit_cherry->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				// Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				// Render background texture to screen
				gBackgroundTexture.render(0, 0);

				// Render Foo' to the screen
				gMain.render(gMain.get_mPosX(), gMain.get_mPosY());
				icon1.render(510, 0);
				icon2.render(540, 0);
				icon3.render(570, 0);
				p_fruit_melon->render(p_fruit_melon->get_mPosX(), p_fruit_melon->get_mPosY());
				p_fruit_bom->render(p_fruit_bom->get_mPosX(), p_fruit_bom->get_mPosY());
				p_fruit_nho->render(p_fruit_nho->get_mPosX(), p_fruit_nho->get_mPosY());
				p_fruit_star->render(p_fruit_star->get_mPosX(), p_fruit_star->get_mPosY());
				p_fruit_cherry->render(p_fruit_cherry->get_mPosX(), p_fruit_cherry->get_mPosY());

				// check va cham qua
				bool is_col = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_melon->GetRect()) && gMain.Ok();
				bool is_col1 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_nho->GetRect()) && gMain.Ok();
				bool is_col2 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_star->GetRect()) && gMain.Ok();
				bool is_col3 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_cherry->GetRect()) && gMain.Ok();
				bool is_col_bom = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_bom->GetRect()) && gMain.Ok();
				if (is_col || is_col1 || is_col2 || is_col3 || is_col_bom)
				{
					if (is_col2)
					{
						mark = mark + 10;
						p_fruit_star->Reset(-5000);
					}
					else if (is_col1 || is_col3 || is_col)
					{
						mark = mark + 5;
					}
					else
					{
						mark /= 2;
						++count_die;
						if(count_die==1){
							icon3.free();
						}
						if(count_die==2){
							icon2.free();
						}
						if(count_die>=3){
							icon1.free();


							// ham khoi tao game over
							int ret = showGameover(e);
							if(ret == 0)
							{
								quit = false;
							}
							else quit = true;
							// ket thuc game over
						}
					}

					if (is_col)
					{
						p_fruit_melon->Reset(-50);
					}

					if (is_col1)
					{
						p_fruit_nho->Reset(-100);
					}

					if (is_col2)
					{
						p_fruit_star->Reset(-5000);
					}

					if (is_col3)
					{
						p_fruit_cherry->Reset(-20);
					}
					if (is_col_bom)
					{
						p_fruit_bom->Reset(-4000);
					}
				}

				// in diem
				char str[10];
				std::string val_str_mark = std::to_string(mark);
				std::string strMark("Score : ");
				strMark += val_str_mark;
				gMark = TTF_RenderText_Solid(gFontTime, strMark.c_str(), gTextColormark);
				gTextTexture.loadFromRenderedText(strMark, gTextColormark);
				gTextTexture.render(0, 0);

				if (gMain.check())
				{
					if (mark < 1)
					{
						mark = 0;
					}
				}

				// an bom end game
				// bool is_col_bom = SDLGame::CheckCollision(gMain.GetRect(),p_fruit_bom->GetRect())&&gMain.Ok();
				// if(is_col_bom){
				// 	count_die++;
				// 	if(count_die==3){
				// 		bkgameover.loadFromFile("backgroundexit.png");
				// 	}
				// }

				// Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	// Free resources and close SDL
	close();

	return 0;
}