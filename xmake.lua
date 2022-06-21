add_rules("mode.debug","mode.release") 
add_rules("plugin.vsxmake.autoupdate") 

if is_mode("release") then
   add_defines("NDEBUG")
end

add_requires("libsdl")
add_requires("sol2")
add_requires("entt")
add_packages("libsdl")
add_packages("sol2")
add_packages("entt")

target("ficelloEngine") 
    set_kind("static") 
    set_targetdir("bin")
    set_languages("cxx20")
    add_files("ficello/*.cpp") 
    add_headerfiles("ficello/*.hpp") 
    

target("ficello")
    set_kind("binary") 
    set_targetdir("bin")
    set_languages("cxx20")
    add_files("src/*.cpp") 
    add_headerfiles("src/*.hpp")
    add_deps("ficelloEngine")
    add_includedirs("ficello")

