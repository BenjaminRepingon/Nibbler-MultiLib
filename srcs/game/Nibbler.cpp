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
#include "objects/Labyrinthe.hpp"

#warning "TODO: copilian form for Nibbler"
Nibbler::Nibbler( int sizex, int sizey ):
_width( sizex ), _height( sizey )
{
	return ;
}

Nibbler::~Nibbler( void )
{
	return ;
}

int				Nibbler::init( void )
{
	Snake *			snake;
	Food * 			food;
	Limit *			limit;
	Labyrinthe *	labyrinthe;

	limit = new Limit( _width, _height );
	labyrinthe = new Labyrinthe( _width, _height, 0 );
	food = 	new Food(5);
	snake = new Snake( 10, 10, 5, food );
	addObject( limit );
	addObject( labyrinthe );
	addObject( food );
	addObject( snake );
	_isRunning = true;

	return ( true );
}

int				Nibbler::getWidth( void )
{
	return this->_width;
}

int				Nibbler::getHeight( void )
{
	return this->_height;
}
