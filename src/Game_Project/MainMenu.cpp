#include <SDL\SDL.h>
#include <SDL\SDL_image.h>


class MainMenu {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* play;
	SDL_Texture* exit;
	SDL_Rect rPlay;
	SDL_Rect rExit;
	
public:
	void Start() {
		try {
			//Necesitamos pintar imagenes en el menu y se inicializan los flags que necesitaremos de sdl
			if (SDL_Init(SDL_INIT_VIDEO) != 0) throw SDL_GetError();
			const Uint8 imgFlags = IMG_INIT_PNG;
			if (!IMG_Init(imgFlags))throw IMG_GetError();

			//Se crea la ventana donde aparecera el menu principal
			const int WIDTH = 640, HEIGHT = 480;
			window = SDL_CreateWindow("Hello SDL",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
			if (window == nullptr) throw SDL_GetError();

			//Se crea el renderer donde se pintaran todos los elementos que apareceran por pantalla
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == nullptr) throw SDL_GetError();

			//Se carga la imagen de play y exit
			play = IMG_LoadTexture(renderer, "../../res/img/play.png");
			exit = IMG_LoadTexture(renderer, "../../res/img/exit.png");

			//Gestion de error por si no se consiguen cargar las imagenes.
			if (play == nullptr) throw SDL_GetError();
			if (exit == nullptr) throw SDL_GetError();

			//Se colocan los dos botones en el renderer
			rPlay = {150,80,180,50};
			rExit = { 150,200,180,50 };

		}
		catch (const char *msg) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", msg);
		}
	}

	/*
	Funcion que limpia la pantalla y vuelve a pintar los dos botones del menu principal.
	*/
	void Draw() {
		try {
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, play, NULL, &rPlay);
			SDL_RenderCopy(renderer, exit, NULL, &rExit);
			SDL_RenderPresent(renderer);
		}
		catch (const char *msg) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", msg);
		}
	}
	/*
	Cuando se pulsa en algun boton del menu se llama esta funciona para eliminar todos los elementos creados
	y dejar espacio para cargar la proxima escena
	*/
	void Close() {
		SDL_DestroyTexture(play);
		SDL_DestroyTexture(exit);
		SDL_DestroyWindow(window);
	}
};