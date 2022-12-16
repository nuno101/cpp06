/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 18:47:48 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( std::string str ) : _input( str )
{
	std::cout << "Constructor called" << std::endl;
}

Converter::~Converter()
{
	std::cout << "Destructor called" << std::endl;
}

Converter::Converter( const Converter &src )
{
	std::cout << "Copy called" << std::endl;
	*this = src;
}

Converter & Converter::operator=( const Converter &src )
{
	this->_input = src._input;
	return *this ; 
}
