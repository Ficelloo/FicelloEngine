#include <SDL.h>

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

class FicelloEngine{
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
    FicelloEngine window(200, 400);
    SDL_Event event;    // Event variable
    
    lua_State* L = luaL_newstate();
	luaL_openlibs(L);
    luaL_dostring(L, "print('Hello world from Lua!')");
	lua_close(L);

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  // setting some Delay
        SDL_PollEvent(&event);  // Catching the poll event.
    }
}

