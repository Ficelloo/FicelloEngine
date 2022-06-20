add_rules("mode.debug","mode.release")
add_rules("plugin.vsxmake.autoupdate")

add_requires("libsdl") -- require sdl2
add_requires("lua") -- require lua
add_requires("sol2") -- require sol2

target("FicelloEngine") 
    set_kind("binary") 
    set_targetdir("bin") 
    set_languages("cxx20") -- c++ 20
    add_files("src/*.cpp") 
    add_packages("libsdl") 
    add_packages("lua")
    add_packages("sol2")
