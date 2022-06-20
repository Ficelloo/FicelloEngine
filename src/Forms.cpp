#include <SDL.h>

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

static int test_func(lua_State *L)
{
  // parameters
  int n = lua_gettop(L);
  if(n < 1)
  {
    lua_pushstring(L, "test: not enough arguments");
	  lua_error(L);
  }

  // getting string argument
  const char *str = lua_tostring(L, 1);
  if(str == NULL)
  {
    lua_pushstring(L, "test: non-string");
	  lua_error(L);
  }

  const char* output = lua_pushstring(L, str);
  printf(output);
  return 1;
}