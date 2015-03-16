/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:46:14 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 15:39:18 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CoreEngine.hpp"
#include "GameObject.hpp"
#include "AGame.hpp"

int			AGame::addObject( GameObject * object )
{
	object->setGame(this);
	object->init();
	this->_objects.push_back( object );
	return ( true );
}

int			AGame::update( ILib const * lib, double delta )
{
	for ( size_t i = 0; i < this->_objects.size(); i++ )
		this->_objects[i]->update( lib, delta );
	return ( true );
}

int			AGame::render( ILib const * lib ) const
{
	for ( size_t i = 0; i < this->_objects.size(); i++ )
		this->_objects[i]->render( lib );
	return ( true );
}

int			AGame::isRunnig( void )
{
	return ( this->_isRunning );
}

int			AGame::setRunnig( int state )
{
	this->_isRunning = state;
	return true;
}

void		AGame::setCore( CoreEngine *core )
{
	this->_core = core;
}

CoreEngine*	AGame::getCore( void )
{
	return this->_core;
}
