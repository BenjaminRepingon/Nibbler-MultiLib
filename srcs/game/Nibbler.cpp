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
#include "objects/Limit.hpp"

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
	Food * 		food;
	Limit *		limit;

	food = 	new Food(5);
	snake = new Snake( 10, 10, 5, food );
	limit = new Limit( 0 );
	addObject( food );
	addObject( snake );
	addObject( limit );
	_isRunning = true;

	return ( true );
}

