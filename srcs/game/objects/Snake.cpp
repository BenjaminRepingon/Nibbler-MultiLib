/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:54:03 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/12 12:31:49 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include "../Nibbler.hpp"
#include <stdlib.h>
#include <stdio.h>


#warning "TODO: copilian form for Snake"
Snake::Snake( int posX, int posY, size_t nbPart) :
	_pos( posX, posY ),
	_nbPart( nbPart ),
	_invincible( false ),
	_speed( 1 ),
	_points( 0 )
{
	return ;
}

Snake::~Snake( void )
{
	return ;
}

int			Snake::update( ILib const * lib, double delta )
{
	float speed = this->_speed * delta;
	if (lib->isKeyPressed(ILib::DOWN) && this->_dir != Vec2i(0, -1))
		this->_dir = Vec2i(0, 1);
	else if (lib->isKeyPressed(ILib::UP) && this->_dir != Vec2i(0, 1))
		this->_dir = Vec2i(0, -1);
	else if (lib->isKeyPressed(ILib::LEFT) && this->_dir != Vec2i(1, 0))
		this->_dir = Vec2i(-1, 0);
	else if (lib->isKeyPressed(ILib::RIGHT) && this->_dir != Vec2i(-1, 0))
		this->_dir = Vec2i(1, 0);

	for ( size_t i = this->_components.size() - 1; i > 0; i-- )
		this->_components[i]->update( lib, delta );
	this->_components[0]->setPos(this->_components[0]->getPos() + this->_dir);
	Nibbler *game = static_cast<Nibbler*>( this->getGame() );
	lib->drawText( game->getWidth()+2, 5, "Player1", _points , 0xFFFFFF );
	return ( true );
}

void						Snake::init( void )
{
	Nibbler *game = static_cast<Nibbler*>( this->getGame() );

	addComponent( new SnakePart( Vec2i( this->_pos.getX(), this->_pos.getY() ), 1, NULL ) );
	for ( size_t i = 1; i < this->_nbPart; i++ )
	{
		#warning "TODO: set SnakePart correctly !"
		addComponent( new SnakePart( Vec2i( this->_pos.getX() - i, this->_pos.getY() ), 1, static_cast<SnakePart*>(getComponents()[i - 1] )) );
	}
	this->_dir = Vec2i(0, 1);
}


void		Snake::grow( void )
{
	SnakePart *parent = static_cast<SnakePart*>(this->getComponents()[this->getComponents().size() - 1]);
	addComponent( new SnakePart( parent->getPos() , 1, static_cast<SnakePart*>(parent) ) );
	this->_nbPart++;
	if (this->_invincible)
		setColour(0xFFFFFF);
	_points++;
}

bool						Snake::getInvincible( void )
{
	this->_endFrame = this->getTime();
	this->_dt = (this->_endFrame - this->_startFrame);
	if (this->_dt >= 5)
	{
		this->_invincible = false;
		setColour(0xff0000);
	}
	return _invincible;
}

void						Snake::setInvincible( bool a )
{
	this->_startFrame = getTime();
	this->_invincible = a;
	return ;
}

double						Snake::getTime( void )
{
	struct timeval		tv;

	gettimeofday( &tv, NULL );
	return ( tv.tv_sec + (double)tv.tv_usec / SECOND );
}

void						Snake::setColour( int c )
{
	for (int i = 0; i < (int)this->getComponents().size(); i++)
		static_cast<SnakePart*>(this->getComponents()[i])->setColour(c);
	return ;
}

int 						Snake::getPoints( void )
{
	return this->_points;
}
