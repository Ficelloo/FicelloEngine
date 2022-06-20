add_rules("mode.debug","mode.release") 
add_rules("plugin.vsxmake.autoupdate") 

add_requires("libsdl")
add_requires("sol2")
add_requires("entt")

target("FicelloEngine") 
    set_kind("binary") 
    set_targetdir("bin") -- binary located in /bin
    set_languages("cxx20") -- c++
    add_files("src/*.cpp") 
    add_headerfiles("src/*.hpp")
    add_packages("libsdl") 
    add_packages("sol2")
    add_packages("entt")
