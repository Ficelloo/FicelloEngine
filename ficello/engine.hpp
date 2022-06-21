#pragma once
#include "logsStream.hpp"
#include <entt/entt.hpp>
#include <stdexcept>

//engine object

namespace ficello
{
	class engine
	{
		entt::registry globalRegistry_{};
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
