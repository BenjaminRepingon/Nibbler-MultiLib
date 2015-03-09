/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakePart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:53:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 12:13:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SnakePart.hpp"

#warning "TODO: copilian form for SnakePart"
SnakePart::SnakePart( Vec2i const & pos, int size, SnakePart *parent ) :	
	_size( size ), _parent(parent)
{
	setPos( pos );
	return ;
}

SnakePart::~SnakePart( void )
{
	return ;
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
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), this->_size );
	return ( true );
}

void		SnakePart::setParent( SnakePart * parent )
{
	this->_parent = parent;
	return ;
}
