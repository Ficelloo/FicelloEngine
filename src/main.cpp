#include <engine.hpp>

int main(int argc, char* argv[])
{
	try
	{
		ficello::engine myFicello{};
		myFicello.run();
	}
	catch (std::exception& e)
	{
		ficello::logsStream << e.what();
	#ifdef NDEBUG
		std::cerr << "unexcepted execption, go to logs.txt to get more informations"
	#endif // NDEBUG

	}
	
}

