#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
//WHAT THE FUCK IS GOING OOOOOOOOON
int main(int, char*[]) {
	try {
		//INIT
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw SDL_GetError();
		const Uint8 imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
		if (!(IMG_Init(imgFlags)&imgFlags))throw IMG_GetError();

		//WINDOW
		const int WIDTH = 640, HEIGHT = 480;
		SDL_Window *window = SDL_CreateWindow("Hello SDL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
		if (window == nullptr) throw SDL_GetError();
		//RENDERER
		SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr) throw SDL_GetError();

		//SPRITES

		SDL_Texture *bgTexture = IMG_LoadTexture(renderer, "../../res/gfx/bg.jpg");
		SDL_Texture *playerTexture = IMG_LoadTexture(renderer, "../../res/gfx/blue.png");

		if (bgTexture == nullptr) throw SDL_GetError();
		if (playerTexture == nullptr) throw SDL_GetError();
		SDL_Rect bgRect = { 0, 0, WIDTH, HEIGHT };
		SDL_Rect playerRect = { (WIDTH>>1)-50, (HEIGHT >> 1)-50, 100, 100 };
		SDL_Rect playerTarget = { 0,0,100,100 };
		
		//GAME LOOP
		for (bool isRunning = true;isRunning;)
		{
			//INPUT HANDLER

			
			SDL_Event evnt;
			while (SDL_PollEvent(&evnt)) 
			{
				switch (evnt.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_MOUSEMOTION: playerTarget.x = evnt.motion.x-50; playerTarget.y = evnt.motion.y - 50;

				default:;
				}
			}
			//UPDATE

			playerRect.x += (playerTarget.x - playerRect.x)*0.1f;
			playerRect.y += (playerTarget.y - playerRect.y)*0.1f;

			//DRAW
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);//ESTA FUNCION NO DEJA ROTAR UNA IMAGEN 
			SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);//ESTA FUNCION NO DEJA ROTAR UNA IMAGEN 

			SDL_RenderPresent(renderer);
		}
		//DESTROY 
		SDL_DestroyTexture(bgTexture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);

	}
	catch (const char *msg) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", msg);
	}
	SDL_Quit();
	SDL_Quit();
	return 0;
}
