/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/17 11:57:59 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( std::string str ) : _input( str )
{
	if ( VERBOSE )
		std::cout << "Constructor called" << std::endl;
}

Converter::~Converter()
{
	if ( VERBOSE )
		std::cout << "Destructor called" << std::endl;
}

Converter::Converter( const Converter &src )
{
	if ( VERBOSE )
		std::cout << "Copy called" << std::endl;
	*this = src;
}

Converter & Converter::operator=( const Converter &src )
{
	if ( VERBOSE )
		std::cout << "Assign called" << std::endl;
	this->_input = src._input;
	return *this ; 
}

void	Converter::run( void )
{
	std::cout << "_input is: " << _input << std::endl;
	int	type = find_type(); 
	std::cout << "type is: " << type << std::endl;
	convert( type );
}

int		Converter::find_type( void )
{
	int	i = 0;
	int	len = _input.length();
	bool has_digits = false;
	bool has_decimal = false;

	if ( len == 0 )
	{
		std::cout << "Error: can't convert empty string" << std::endl;
		exit(0);
	}
	if ( len == 1 )
	{
		if ( isdigit( _input[0]) )
			return INT ;
		else if ( isalpha( _input[0]) )
			return CHAR ;
		else
	 		return 0;
	}
	if ( _input == "-inff" || _input == "+inff" || _input == "nanf" )
		return FLOAT ;
	else if ( _input == "-inf" || _input == "+inf" || _input == "nan" )
		return DOUBLE ;
	while ( i < len )
	{
		if ( isdigit( _input[i]) )
			has_digits = true;
		else if ( _input[i] =='.' )
		{
			if ( has_decimal == false )
				has_decimal = true;
			else // found two dots
				return UNSUPPORTED ;
		}
		i++;
	}
	if (has_digits && !has_decimal)
		return INT ;
	return UNSUPPORTED ;
}

void	Converter::convert( int type )
{
	switch ( type )
	{
		case UNSUPPORTED:
			std::cout << "Error: unsupported string" << std::endl;
			break;
		case CHAR:
			std::cout << _input << " is a char" << std::endl;
			break;
		case INT:
			std::cout << _input << " is an int " << std::endl;
			break;
		case FLOAT:
			std::cout << _input << " is a float" << std::endl;
			break;
		case DOUBLE:
			std::cout << _input << " is a double" << std::endl;
			break;
		default:
			std::cout << "Error: unknown type" << std::endl;
	}
}

void	Converter::show_all ( void )
{
	std::cout << "_input: " << _input << std::endl;
	std::cout << "char: " << _char << std::endl;
}
