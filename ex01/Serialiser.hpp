/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:20:56 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/21 11:43:47 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISER_HPP
#define SERIALISER_HPP

#include <iostream>
#include <string>

typedef	struct Data
{
	std::string	str;
	int			nr;
	float		flt;
}	t_Data;

class Serialiser
{
	public:
		Serialiser();
		Serialiser( const Serialiser &src );
		Serialiser & operator=( const Serialiser &src );
		~Serialiser();
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif
