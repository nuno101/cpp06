/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:37:04 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/17 17:21:01 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

enum types {
	UNSUPPORTED = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class	Converter
{
	private:
		std::string	_input;

	public:
		Converter( std::string str);
		~Converter();
		Converter( const Converter &src );
		Converter &operator=( const Converter &src );
		void	run( void );
		int		find_type ( void );
		int		is_int( int len );
		int		is_float_or_double( int len );
		void	convert( int type );
		void	convert_char( void );
		void	convert_int( void );
		void	convert_float( void );
		void	convert_double( void );
};

#endif
