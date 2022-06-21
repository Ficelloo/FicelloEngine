#include "logsStream.hpp"

#ifdef NDEBUG
	#include <fstream>
	std::ofstream logs{ "logs.txt", std::ios::out };
	std::ostream& ficello::logsStream{ logs };
#else
	std::ostream& ficello::logsStream{ std::cerr };
#endif // NDEBUG




