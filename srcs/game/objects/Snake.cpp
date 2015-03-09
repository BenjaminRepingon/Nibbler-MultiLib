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
Snake::Snake( int posX, int posY, size_t nbPart, Food *food ) :
	_pos( posX, posY ),
	_nbPart( nbPart ),
	_food( food ),
	_speed( 1.0 )
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
	// printf("%d\n", this->_dir.get());
	this->_components[0]->setPos(this->_components[0]->getPos() + this->_dir);
	this->checkCollision();
	return ( true );
}


int			Snake::checkCollision( void )
{
	std::vector<AComponent *> foodElements;
	foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( _food->getComponents()[i]->getPos() == this->getComponents()[0]->getPos() )
		{
			grow();
			popFood(i, foodElements );
		}
	}
	for (int k = 1;  k < (int)this->_components.size() ; k++)
	{
		if ( this->_components[0]->getPos() == this->_components[k]->getPos() )
		{
			this->getGame()->setRunnig(false);
			printf("KABOOM");
		}
	}
	return false;
}

void		Snake::grow( void )
{
	SnakePart *parent = static_cast<SnakePart*>(this->getComponents()[this->getComponents().size() - 1]);
	addComponent( new SnakePart( parent->getPos() , 1, static_cast<SnakePart*>(parent) ) );
	this->_nbPart++;
}

void		Snake::popFood( int i, std::vector<AComponent *> foodElements )
{
	static int r = 1;

	srand(r++);
	_food->getComponents()[i]->setPos(Vec2i( rand() % 25 , rand() % 25 ) );
	if (checkNewPosition(i, foodElements))
		popFood(i, foodElements);
	return ;
}

bool		Snake::checkNewPosition( int j, std::vector<AComponent *> foodElements )
{
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( _food->getComponents()[j]->getPos() == this->getComponents()[i]->getPos() && j != i)
			return true;
	}
	for (int l = 0;  l < (int)this->_components.size() - 1 ; l++)
	{
		if ( this->_components[l]->getPos() == _food->getComponents()[j]->getPos() )
			return true;
	}
	return false;
}