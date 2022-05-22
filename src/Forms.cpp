#include <SDL.h>

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

static int circle(lua_State *L)
{
	lua_pushnumber(L, 20);
	return 1;
}
