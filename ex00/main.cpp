#include <iostream>
#include "Converter.hpp"

int	main( int argc, char** argv )
{
	if ( argc != 2 )
	{
		std::cout << "Error: call like ./convert <parameter>" << std::endl;
		return -1;
	}
	std::cout << "Parameter: " << argv[1] << std::endl;
	return 0 ;
}
