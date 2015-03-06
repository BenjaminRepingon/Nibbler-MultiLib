/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:54:03 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 12:14:51 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

#warning "TODO: copilian form for Snake"
Snake::Snake( int posX, int posY, size_t nbPart ) :
	_pos( posX, posY ),
	_nbPart( nbPart )
{
	for ( size_t i = 0; i < this->_nbPart; i++ )
	{
		#warning "TODO: set SnakePart correctly !"
		addComponent( new SnakePart( Vec2i( this->_pos.getX() - i, this->_pos.getY() ), 1 ) );
	}
	return ;
}

Snake::~Snake( void )
{
	return ;
}
