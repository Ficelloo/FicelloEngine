add_rules("mode.debug","mode.release") --ajout d'un mode de debug et de release
add_rules("plugin.vsxmake.autoupdate") --regle d'update auto de la solution pour les flemmards qui devs sous VS (ingnoré sous linux)

add_requires("libsdl") --requiert la SDL2
add_requires("sol2")
add_requires("entt")
--add_requires("sol2") --demande lua et sol2

target("ficello") --nouvelle cible de compilation
    set_kind("binary") --on veut un executable
    set_targetdir("bin") --les binaires sont automatiquement envoye dans le dossier bin (pas build car deja pris par vs...)
    set_languages("cxx20") --activation des features du C++20 (attention ne compile pas si le compilo ne supporte pas C++ 20)
    add_files("src/*.cpp") --inclus tous les .cpp dans le dossier src
    add_headerfiles("src/*.hpp") --pareil avec les headers
    add_packages("libsdl") --ajout des packages a notre target 
    add_packages("sol2")
    add_packages("entt")
