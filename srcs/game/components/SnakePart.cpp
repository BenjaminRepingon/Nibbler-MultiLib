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
SnakePart::SnakePart( Vec2i const & pos, int size ) :
	_pos( pos ),
	_size( size )
{
	return ;
}

SnakePart::~SnakePart( void )
{
	return ;
}

int			SnakePart::update( ILib const * lib, double delta )
{
	(void)lib;
	(void)delta;
	return ( true );
}

int			SnakePart::render( ILib const * lib ) const
{
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), this->_size );
	return ( true );
}
