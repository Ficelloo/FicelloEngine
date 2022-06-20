#include <SDL2/SDL.h>
#include <iostream>
#include <string>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


int test_func(lua_State* L)
{
	// parameters
	int n = lua_gettop(L);
	if (n < 1)
	{
		lua_pushstring(L, "test: not enough arguments");
		lua_error(L);
	}

	// getting string argument
	const char* str = lua_tostring(L, 1);
	if (str == NULL)
	{
		lua_pushstring(L, "test: non-string");
		lua_error(L);
	}

	const char* output = lua_pushstring(L, str);
	std::cout << output << '\n';
	return 1;
}

class FicelloEngine {
	public:
		FicelloEngine(int height_, int width_): height(height_), width(width_){
		    SDL_Init(SDL_INIT_VIDEO);       
		    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
		    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      
		    SDL_RenderClear(renderer);     
		    SDL_RenderPresent(renderer);    
		}

		~FicelloEngine(){
		    SDL_DestroyRenderer(renderer);
		    SDL_DestroyWindow(window);
		    SDL_Quit();
		}

	private:
		int height;     
		int width;      
		SDL_Renderer *renderer = nullptr;      
		SDL_Window *window = nullptr;      
};

int main(int argc, char* argv[]){
	if(argc < 2) {
		printf("Correct usage: FicelloEngine [file]");
		return -1;
	}

	FicelloEngine window(1080, 1920);
	SDL_Event event;    
				
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "test", test_func);
	luaL_dofile(L, argv[1]);
	lua_close(L);

	while(!(event.type == SDL_QUIT)){
		SDL_Delay(10); 
		SDL_PollEvent(&event);  // Catching the poll event.
	}
	return 0;
}