#include <SDL.h>
#include <iostream>
#include <string>
#include "Forms.cpp"

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class FicelloEngine {
	public:
		FicelloEngine(int height_, int width_): height(height_), width(width_){
		    SDL_Init(SDL_INIT_VIDEO);       // init SDL as a video
		    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
		    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // draw color
		    SDL_RenderClear(renderer);      // clear new created window
		    SDL_RenderPresent(renderer);    
		}

		~FicelloEngine(){
		    SDL_DestroyRenderer(renderer);
		    SDL_DestroyWindow(window);
		    SDL_Quit();
		}

	private:
		int height;     // window height
		int width;      // window width
		SDL_Renderer *renderer = NULL;      // Pointer render var
		SDL_Window *window = NULL;      // Pointer window var 
};

int main(int argc, char * argv[]){
	if(argc < 2) {
		printf("Correct usage: FicelloEngine [file]");
		exit(-1);
	}
	
	int argv_lenght = strlen(argv[1]);

	if(argv_lenght < 5) { 
		printf("Correct usage: FicelloEngine [file]");
		exit(-1);
   	} else {
		FicelloEngine window(1080, 1920);
		SDL_Event event;    // Event variable
				
		lua_State* L = luaL_newstate();
		luaL_openlibs(L);
		lua_register(L, "test", test_func);
		luaL_dofile(L, argv[1]);
		lua_close(L);

		while(!(event.type == SDL_QUIT)){
			SDL_Delay(10);  // setting some Delay
			SDL_PollEvent(&event);  // Catching the poll event.
		}
	}
	return 0;
}