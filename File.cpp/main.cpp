#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "FruitObject.h"

SDL_Color gTextColor = {0x00, 0x00, 0x00};
SDL_Color gTextColormark = {0xFF, 0x00, 0x00};

// Scene textures

BaseObject gBackgroundTexture;
BaseObject gTextTexture;
BaseObject g_icon;
BaseObject g_bkground;
MainObject gMain;
FruitObject *p_fruit_melon = new FruitObject();
FruitObject *p_fruit_bom = new FruitObject();
FruitObject *p_fruit_nho = new FruitObject();
FruitObject *p_fruit_star = new FruitObject();
FruitObject *p_fruit_cherry = new FruitObject();

// Starts up SDL and creates window
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

int main(int argc, char *args[])
{
	int mark = 0;
	int count_die = 0;
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

			// While application is running
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
				p_fruit_melon->render(p_fruit_melon->get_mPosX(), p_fruit_melon->get_mPosY());
				p_fruit_bom->render(p_fruit_bom->get_mPosX(), p_fruit_bom->get_mPosY());
				p_fruit_nho->render(p_fruit_nho->get_mPosX(), p_fruit_nho->get_mPosY());
				p_fruit_star->render(p_fruit_star->get_mPosX(), p_fruit_star->get_mPosY());
				p_fruit_cherry->render(p_fruit_cherry->get_mPosX(), p_fruit_cherry->get_mPosY());

				bool is_col = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_melon->GetRect());
				bool is_col1 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_nho->GetRect());
				bool is_col2 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_star->GetRect());
				bool is_col3 = SDLGame::CheckCollision(gMain.GetRect(), p_fruit_cherry->GetRect());

				// if (is_col || is_col1 || is_col2 || is_col3)
				// {
					if (is_col3)
					{
						mark = mark + 5;
					}
					// else
					// {
					// 	mark = mark + 1;
					// }

				// 	if (is_col)
				// 	{
				// 		p_fruit_melon->Reset(-50);
				// 	}

				// 	if (is_col1)
				// 	{
				// 		p_fruit_nho->Reset(-100);
				// 	}

				// 	if (is_col2)
				// 	{
				// 		p_fruit_star->Reset(-20);
				// 	}

				// 	if (is_col3)
				// 	{
				// 		p_fruit_cherry->Reset(-5000);
				// 	}
				// }
				char str[10];
				// SDL_itoa(mark, str, 10);
				std::string val_str_mark = std::to_string(mark);
				std::string strMark("Score : ");
				strMark += val_str_mark;
				gMark = TTF_RenderText_Solid(gFontTime, strMark.c_str(), gTextColormark);
				gTextTexture.loadFromRenderedText(strMark, gTextColormark);
				gTextTexture.render(0, 0);
 
				// //Reset fruit
				// bool is_die = p_fruit_melon->FruitExit(p_fruit_melon->GetRect().y);
				// bool is_die1 = p_fruit_nho->FruitExit(p_fruit_nho->GetRect().y);
				// bool is_die2 = p_fruit_cherry->FruitExit(p_fruit_cherry->GetRect().y);

				// if (is_die1 || is_die || is_die2)
				// {
				// 	count_die++;
				// 	g_icon.loadFromFile("iconx.png");
				// 	g_bkground.loadFromFile("background1.png");
				// 	// SDLGame::ApplySurface(g_icon, g_bkground, 400 + 30 * count_die, 10);
				// 	if (is_die1)
				// 	{
				// 		p_fruit_melon->Reset(-100);
				// 	}
				// 	if (is_die)
				// 	{
				// 		p_fruit_nho->Reset(-50);
				// 	}
				// 	if (is_die2)
				// 	{
				// 		p_fruit_cherry->Reset(-200);
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
