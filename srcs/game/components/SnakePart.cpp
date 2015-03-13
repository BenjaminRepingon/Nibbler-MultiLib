/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakePart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:53:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 14:51:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SnakePart.hpp"

SnakePart::SnakePart( Vec2i const & pos, int size, SnakePart *parent ) :
	_size( size ), _parent(parent), _colour(0xFF0000)
{
	setPos( pos );
	return ;
}

SnakePart::~SnakePart( void )
{
	return ;
}

SnakePart::SnakePart( SnakePart const & src )
{
	*this = src;
}

SnakePart &	SnakePart::operator=( SnakePart const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int			SnakePart::update( ILib const * lib, double delta )
{
	if (this->_parent != NULL)
		this->_pos = this->_parent->getPos();
	(void)lib;
	(void)delta;
	return ( true );
}

int			SnakePart::render( ILib const * lib ) const
{
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), this->_size, this->_colour );
	return ( true );
}

void		SnakePart::setParent( SnakePart * parent )
{
	this->_parent = parent;
	return ;
}

void		SnakePart::setColour( int c )
{
	this->_colour = c;
	return ;
}
