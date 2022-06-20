#pragma once
#include <entt/entt.hpp>
#include <sstream>

//premier prototype de l'objet représentant l'engine

namespace ficello
{
	class engine
	{
		entt::registry globalRegistry_;
		std::ostream debugStream_; //flux de débugage, peut être utilisé sur std::cout/cerr ou sur un fichier pour crée un fichier de logs 
		//need a window class
		//need a renderer class

	public:

		//specify ctors, dtor and assignement :
		//disable copy of the engine
		engine() = default;
		engine(engine&) = delete;
		engine(engine&&) = default;
		void operator=(engine&) = delete;
		virtual ~engine() = default; //in case of herited classes of engine 

		//methodes
		void run();
	};
}
