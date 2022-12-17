/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:37:04 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/17 10:42:08 by nlouro           ###   ########.fr       */
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
		char		_char;
//		int			_int;
//		float		_float;
//		double		_double;
		
	public:
		Converter( std::string str);
		~Converter();
		Converter( const Converter &src );
		Converter &operator=( const Converter &src );
		void	run( void );
		int		find_type ( void );
		void	show_all( void );
};

#endif
