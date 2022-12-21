#include <iostream>
#include "Serialiser.hpp"

int	main( void )
{
	std::cout << "Hello" << std::endl;
	Data	ptr;
	Data	*ptr2;
	ptr.str = "test";
	ptr.nr = 123;
	ptr.flt = 1.23;

	std::cout << "Data structure `ptr` content:\n";
	std::cout << " str: " << ptr.str << std::endl;
	std::cout << " int number: " << ptr.nr << std::endl;
	std::cout << " float number: " << ptr.flt << std::endl;

	Serialiser S;
	ptr2 = S.deserialize( S.serialize( &ptr ));
	
	std::cout << "Serialising Data...:\n";
	std::cout << "Deserialising Data...:\n";

	std::cout << "Data structure `ptr2`  content:\n";
	std::cout << " str: " << ptr2->str << std::endl;
	std::cout << " int number: " << ptr2->nr << std::endl;
	std::cout << " float number: " << ptr2->flt << std::endl;

	std::cout << "Verify that the content of ptr2 matches ptr!\n";
	return 0 ;
}
