#pragma once
#include <entt/entt.hpp>
#include <ostream>

//premier prototype de l'objet repr�sentant l'engine

namespace ficello
{
	class engine
	{
		entt::registry globalRegistry_;
		//std::ostream debugStream_; //flux de d�bugage, peut �tre utilis� sur std::cout/cerr ou sur un fichier pour cr�e un fichier de logs 
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
