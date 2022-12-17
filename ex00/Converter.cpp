/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/17 15:28:58 by nlouro           ###   ########.fr       */
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
	bool has_decimals = false;

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
			if ( has_decimals == false )
				has_decimals = true;
			else // found two dots
				return UNSUPPORTED ;
		}
		i++;
	}
	if (has_digits && !has_decimals)
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
			if ( VERBOSE )
				std::cout << _input << " is a char" << std::endl;
			convert_char();
			break;
		case INT:
			if ( VERBOSE )
				std::cout << _input << " is an int " << std::endl;
			convert_int();
			break;
		case FLOAT:
			if ( VERBOSE )
				std::cout << _input << " is a float" << std::endl;
			convert_float();
			break;
		case DOUBLE:
			if ( VERBOSE )
				std::cout << _input << " is a double" << std::endl;
			convert_double();
			break;
		default:
			std::cout << "Error: unknown type" << std::endl;
	}
}

/*
 * each concert_type function converts the user input string to the type
 * and to the other types using static_cast's
 */
void	Converter::convert_char( void )
{
	char	c = static_cast<char>( _input[0] );
	int		i = static_cast<int>( _input[0] );
	float	f = static_cast<float>( _input[0] );
	double	d = static_cast<double>( _input[0] );
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	Converter::convert_int( void )
{
	int	i;
	try
	{
		i = static_cast<int>( std::stoi( _input ));
	}
	catch ( std::out_of_range & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		std::cout << "Can't convert integer. Exiting ..." << std::endl;
		exit(0);
	}
	float	f = static_cast<float>( i );
	double	d = static_cast<double>( i );

	if ( isprint( i ))
		std::cout << "char: " << static_cast<char>( i ) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "float: " << f << "f" <<std::endl;
	std::cout << "double: " << d << std::endl;
}

void	Converter::convert_float( void )
{
	if ( _input == "-inff" || _input == "+inff" || _input == "nanf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << _input << std::endl;
		//std::cout << "double: " << d << std::endl;
	}
	float	f = static_cast<float>( std::stof( _input ));
	int		i = static_cast<int>( f );
	double	d = static_cast<double>( f );
	std::cout << "int: " << i << std::endl;
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "float: " << f << "f" <<std::endl;
	std::cout << "double: " << d << std::endl;
}

void	Converter::convert_double( void )
{
	if ( _input == "-inf" || _input == "+inf" || _input == "nan" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << _input << "f" << std::endl;
		std::cout << "double: " << _input << std::endl;
	}
}
