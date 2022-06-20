#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <sol/sol.hpp>

#include "Rendering/Forms.h"

int main(int argc, char* argv[]){
	if(argc < 2) {
		printf("Correct usage: FicelloEngine [file]");
		return -1;
	}

	sol::state lua{};
	lua.set_function("window", window_func);
				
	luaL_openlibs(lua);
	luaL_dofile(lua, argv[1]);
	lua_close(lua);

	SDL_Event event;    

	while(!(event.type == SDL_QUIT)){
		SDL_Delay(10); 
		SDL_PollEvent(&event);  // Catching the poll event.
	}
	return 0;
}