#include <iostream>
#include "Base.hpp"

int	main( void )
{
	Base	*ptr;
	for (int i = 0; i < 9; i++)
	{
		ptr = generate();
		identify( ptr );
		identify( *ptr );
	}
	delete ptr;
	return 0 ;
}
