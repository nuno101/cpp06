/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:59:42 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/21 12:40:18 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class	Base
{
	public:
		virtual	~Base();
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate( void );
void	identify( Base *ptr );
void	identify( Base &ptr );

#endif
