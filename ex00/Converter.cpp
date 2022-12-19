/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/19 17:06:13 by nlouro           ###   ########.fr       */
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
	if ( VERBOSE )
		std::cout << "_input is: " << _input << std::endl;
	int	type = find_type(); 
	std::cout << "type is: " << type << std::endl;
	convert( type );
}

int		Converter::is_int( int len )
{
	int	i = 0;

	if ( _input[0] == '-' ||  _input[0] == '+' )
		i++;
	while ( i < len )
	{
		if ( isdigit( _input[i]) ) 
			i++;
		else
			return UNSUPPORTED ;
	}
	return INT ;
}

/*
 * already validated:
 * len > 1
 * single dot in string
 * last character is f
 */
int		Converter::is_float_or_double( int len )
{
	int	i = 0;

	if ( _input[0] == '-' ||  _input[0] == '+' )
		i++;
	while ( i < len )
	{
		if ( _input[i] == '.' || isdigit( _input[i]) ) 
			i++;
		else if ( i == len - 1 && _input[i] == 'f' )
			return FLOAT ;
		else
			return UNSUPPORTED ;
	}
	return DOUBLE ;
}

int		Converter::find_type( void )
{
	int	len = _input.length();

	if ( len == 0 )
	{
		std::cout << "Error: can't convert empty string.\nExiting..." << std::endl;
		exit(0);
	}
	if ( len == 1 )
	{
		if ( isdigit( _input[0]) )
			return INT ;
		else if ( isprint( _input[0]) )
			return CHAR ;
		else
	 		return 0;
	}
	if ( _input == "-inff" || _input == "+inff" || _input == "nanf" )
		return FLOAT ;
	else if ( _input == "-inf" || _input == "+inf" || _input == "nan" )
		return DOUBLE ;
	// validate number of dots
	std::size_t	found = _input.find(".");
	if ( found == std::string::npos ) // no dots
		return is_int( len ) ;
	if ( found == _input.rfind(".") ) // single dot in string 
		return is_float_or_double( len ) ;
	else
		return UNSUPPORTED ;
}

void	Converter::convert( int type )
{
	switch ( type )
	{
		case UNSUPPORTED:
			std::cout << "Error: unsupported/ invalid string" << std::endl;
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
	_char = static_cast<char>( _input[0] );
	_int = static_cast<int>( _char );
	_float = static_cast<float>( _char );
	_double	= static_cast<double>( _char );
	show_all();
}

void	Converter::convert_int( void )
{
	try
	{
		_int  = static_cast<int>( std::stoi( _input ));
	}
	//catch ( std::out_of_range & e )
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		std::cout << "Can't convert to integer. Exiting ..." << std::endl;
		exit(0);
	}
	_float = static_cast<float>( _int );
	_double = static_cast<double>( _int );
	if ( isprint( _int ))
		_char = static_cast<char>( _int );
	show_all();
}

void	Converter::convert_float( void )
{
	if ( _input == "-inff" || _input == "+inff" || _input == "nanf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << _input << std::endl;
		std::cout << "double: " << _input.substr(0, _input.length() - 1) << std::endl;
		return ;
	}
	try
	{
		_float = static_cast<float>( std::stof( _input ));
	}
	//catch ( std::out_of_range & e )
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		std::cout << "Can't convert to float. Exiting ..." << std::endl;
		exit(0);
	}
	_int = static_cast<int>( _float );
	_double = static_cast<double>( _float );
	if ( isprint( _int ))
		_char = static_cast<char>( _float );
	show_all();
}

void	Converter::convert_double( void )
{
	if ( _input == "-inf" || _input == "+inf" || _input == "nan" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << _input << "f" << std::endl;
		std::cout << "double: " << _input << std::endl;
		return ;
	}

	try
	{
		_double = static_cast<double>( std::stod( _input ));
	}
	//catch ( std::out_of_range & e )
	catch ( std::exception & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		std::cout << "Can't convert to double. Exiting ..." << std::endl;
		exit(0);
	}
	_int = static_cast<int>( _double );
	if ( isprint( _int ))
		_char = static_cast<char>( _double );
	_float = static_cast<float>( _double );
	show_all();
}

void	Converter::show_all( void )
{
	if ( !isprint( _int ))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( _char ) << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "float: " << _float << "f" <<std::endl;
	std::cout << "double: " << _double << std::endl;
}
