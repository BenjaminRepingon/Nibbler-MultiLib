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
	addComponent( new SnakePart( Vec2i( this->_pos.getX(), this->_pos.getY() ), 1, NULL ) );
	for ( size_t i = 1; i < this->_nbPart; i++ )
	{
		#warning "TODO: set SnakePart correctly !"
		addComponent( new SnakePart( Vec2i( this->_pos.getX() - i, this->_pos.getY() ), 1, static_cast<SnakePart*>(getComponents()[i - 1] )) );
	}
	this->_dir = Vec2i(0, 1);
	return ;
}

Snake::~Snake( void )
{
	return ;
}

int			Snake::update( ILib const * lib, double delta )
{

	if (lib->isKeyPressed(ILib::DOWN))
		this->_dir = Vec2i(0, 1);
	else if (lib->isKeyPressed(ILib::UP))
		this->_dir = Vec2i(0, -1);
	else if (lib->isKeyPressed(ILib::LEFT))
		this->_dir = Vec2i(-1, 0);
	else if (lib->isKeyPressed(ILib::RIGHT))
		this->_dir = Vec2i(1, 0);

	for ( size_t i = this->_components.size() - 1; i > 0; i-- )
		this->_components[i]->update( lib, delta );
	// printf("%d\n", this->_dir.get());
	this->_components[0]->setPos(this->_components[0]->getPos() + this->_dir);
	return ( true );
}

