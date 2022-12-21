/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:28:30 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/21 10:39:25 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialiser.hpp"

Serialiser::Serialiser()
{
	if ( VERBOSE )
		std::cout << "Constructor called" << std::endl;	
}

Serialiser::~Serialiser()
{
	if ( VERBOSE )
		std::cout << "Destructor called" << std::endl;	
}

Serialiser::Serialiser( const Serialiser &src )
{
	if ( VERBOSE )
		std::cout << "Copy called" << std::endl;	
	*this = src;
}

Serialiser & Serialiser::operator=( const Serialiser &src )
{
	if ( VERBOSE )
		std::cout << "Assign called" << std::endl;	
	( void ) &src;
	return *this;
}

uintptr_t Serialiser::serialize(Data* ptr)
{
	return ( reinterpret_cast<uintptr_t>( ptr ) );
}

Data* Serialiser::deserialize(uintptr_t raw)
{
	return ( reinterpret_cast<Data *>( raw ) );
}
