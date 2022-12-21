#include <iostream>
#include "Serialiser.hpp"

int	main( void )
{
	std::cout << "Hello" << std::endl;
	Data	ptr;
	ptr.name = "test";

	std::cout << "Data name: " << ptr.name << std::endl;

	Serialiser S;
	S.serialize( &ptr );

	return 0 ;
}
