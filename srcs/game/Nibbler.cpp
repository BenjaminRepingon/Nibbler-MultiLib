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
	_limit = new Limit( _width, _height );
	_labyrinthe = new Labyrinthe( _width, _height, 5 );
	_food = new Food(5);
	_snake = new Snake( 10, 10, 5 );

	addObject( _limit );
	addObject( _labyrinthe );
	addObject( _food );
	addObject( _snake );

	//we pop food so it dosent collide with anything
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		popFood(i, foodElements );
	}

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

int			Nibbler::update( ILib const * lib, double delta )
{
	AGame::update(lib, delta);
	if (!_snake->getInvincible() && (this->checkBasicCollision(_snake->getComponents()[0])
		|| this->checkWallCollision(_snake->getComponents()[0]) ))
		this->setRunnig(false);
	if (_snake->getInvincible() && this->checkBasicCollision(_snake->getComponents()[0]))
		this->setRunnig(false);
	this->checkFoodCollision(_snake->getComponents()[0]);
	return ( true );
}

int			Nibbler::checkFoodCollision( AComponent *element )
{
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( foodElements[i]->getPos() == element->getPos() && i == ((int)foodElements.size() - 1))
		{
			_snake->setInvincible(true);
			// foodElements[i]->setPos(Vec2i(-10, -10));
			popFood(i, foodElements );
			_snake->setColour(0xFFFFFF);
			return true;
		}
		if ( foodElements[i]->getPos() == element->getPos())
		{
			_snake->grow();
			popFood(i, foodElements );
			return true;
		}
	}
	return false;
}

int			Nibbler::checkFoodCollision( AComponent *element, int j )
{
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( foodElements[i]->getPos() == element->getPos() && j != i)
		{
			_snake->grow();
			popFood(i, foodElements );
			return true;
		}
	}
	return false;
}

void		Nibbler::popFood( int i, std::vector<AComponent *> foodElements )
{
	int x = (rand() % (this->getWidth() - 1)+ 1);
	int y = (rand() % (this->getHeight() - 1) ) + 1;

	_food->getComponents()[i]->setPos(Vec2i(  x,  y));
	if (checkBasicCollision(_food->getComponents()[i]) || checkWallCollision(_food->getComponents()[i]) || checkFoodCollision(_food->getComponents()[i], i))
		popFood(i, foodElements);
	return ;
}

int			Nibbler::checkBasicCollision( AComponent *element )
{

	std::vector<AComponent *> snake = _snake->getComponents();
	for (int k = 1;  k < (int)snake.size() ; k++)
	{
		
		if ( element->getPos() == snake[k]->getPos())
			return true;
		if ( _width <= snake[k]->getPos().getX() || _height <= snake[k]->getPos().getY()
				|| 0 >= snake[k]->getPos().getX() || 0 >= snake[k]->getPos().getY())
			return true;
	}
	return false;
}

int			Nibbler::checkWallCollision( AComponent *element )
{
	// std::vector<AComponent *> snake = _snake->getComponents();
	std::vector<AComponent *> walls = _labyrinthe->getComponents();
	for (int m = 1;  m < (int)walls.size() ; m++)
	{
		if ( element->getPos().getX() == walls[m]->getPos().getX() && walls[m]->getPos().getX() == walls[m]->getPos2().getX())
		{
			if (walls[m]->getPos().getY() > walls[m]->getPos2().getY())
			{
				if (element->getPos().getY() <= walls[m]->getPos().getY() && element->getPos().getY() >= walls[m]->getPos2().getY())
					return true;
			}
			else
			{
				if (element->getPos().getY() >= walls[m]->getPos().getY() && element->getPos().getY() <= walls[m]->getPos2().getY())
					return true;
			}
		}
		else if ( element->getPos().getY() == walls[m]->getPos().getY() && walls[m]->getPos().getY() == walls[m]->getPos2().getY() )
		{
			if (walls[m]->getPos().getX() > walls[m]->getPos2().getX())
			{
				if (element->getPos().getX() <= walls[m]->getPos().getX() && element->getPos().getX() >= walls[m]->getPos2().getX())
					return true;
			}
			else
			{
				if (element->getPos().getX() >= walls[m]->getPos().getX() && element->getPos().getX() <= walls[m]->getPos2().getX())
					return true;
			}
		}
	}
	return false;
}
