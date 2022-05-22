cmake_minimum_required (VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project (FicelloEngine)

add_executable(FicelloEngine main.cpp)

# find SDL2 package
INCLUDE(FindPkgConfig)

# Searching SDL2 package
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

# Linking project with libraries
target_link_libraries(FicelloEngine ${SDL2_LIBRARIES})

