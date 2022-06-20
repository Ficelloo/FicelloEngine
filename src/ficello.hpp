#pragma once
#include <entt/entt.hpp>
#include <sstream>

//engine object

namespace ficello
{
	class engine
	{
		entt::registry globalRegistry_;
		std::ostream debugStream_; // logs debuging
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
