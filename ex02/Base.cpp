/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:09:52 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/21 12:46:38 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	if ( VERBOSE )
		std::cout << "Destructor called" << std::endl;
}

// functions requested
Base	*generate( void )
{
	Base	*newabc;

	switch( rand() % 3 )
	{
		case 0:
			newabc = new A();
			if ( VERBOSE )
				std::cout << "Type A class generated" << std::endl;
			break;
		case 1:
			newabc = new B();
			if ( VERBOSE )
				std::cout << "Type B class generated" << std::endl;
			break;
		case 2:
			newabc = new C();
			if ( VERBOSE )
				std::cout << "Type C class generated" << std::endl;
			break;
		default:
			exit(1);
	}
	return newabc;
}

void	identify( Base *ptr )
{
	if (dynamic_cast<A*>( ptr ) != nullptr)
		std::cout << "Type A found" << std::endl;
	else if (dynamic_cast<B*>( ptr ) != nullptr)
		std::cout << "Type B found" << std::endl;
	else if (dynamic_cast<C*>( ptr ) != nullptr)
		std::cout << "Type C found" << std::endl;
}

void	identify( Base &ptr )
{
	try
	{
		(void) dynamic_cast<A&>( ptr );
		std::cout << "Type A found" << std::endl;
	} catch ( std::exception ) {}
	try
	{
		(void) dynamic_cast<B&>( ptr );
		std::cout << "Type B found" << std::endl;
	} catch ( std::exception ) {}
	try
	{
		(void) dynamic_cast<C&>( ptr );
		std::cout << "Type C found" << std::endl;
	} catch ( std::exception ) {}
}
