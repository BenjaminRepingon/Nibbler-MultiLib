/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:41:29 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 11:04:47 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nibbler.hpp"
#include "objects/Snake.hpp"
#include "objects/Food.hpp"

#warning "TODO: copilian form for Nibbler"
Nibbler::Nibbler( void )
{
	return ;
}

Nibbler::~Nibbler( void )
{
	return ;
}

int				Nibbler::init( void )
{
	Snake *		snake;
	static int t = 1;

	srand(t++);

	snake = new Snake( 10, 10, 5 );
	addObject( snake );
	addObject( new Food(15));
	return ( true );
}

int			Nibbler::update( ILib const * lib, double delta )
{
	for ( size_t i = 0; i < this->_objects.size(); i++ )
		this->_objects[i]->update( lib, delta );
	return ( true );
}

void		Nibbler::checkFood(void)
{
	
	return ;
}