/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:02:44 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 17:37:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CoreEngine.hpp"

CoreEngine::CoreEngine( float fps, ILib * lib ) :
	_fps( fps ),
	_renderLib( lib ),
	_game( nullptr ),
	_isRunning( false )
{
	return ;
}

CoreEngine::CoreEngine( CoreEngine const & src )
{
	*this = src;
	return ;
}

CoreEngine::~CoreEngine( void )
{
	return ;
}

CoreEngine &	CoreEngine::operator=( CoreEngine const & rhs )
{
	if ( this != &rhs )
	{
		this->_renderLib = rhs.getRenderLib();
	}
	return ( * this );
}

double			CoreEngine::getTime( void )
{
	struct timeval		tv;

	gettimeofday( &tv, NULL );
	return ( tv.tv_sec + (double)tv.tv_usec / SECOND );
}

bool			CoreEngine::start( void )
{
	double		startFrame;
	double		endFrame;
	double		dt;

	if ( this->_isRunning == true )
	{
		std::cerr << "CoreEngine alrady running !" << std::endl;
		return ( false );
	}
	if ( this->_game == nullptr )
	{
		std::cerr << "CoreEngine need a game !" << std::endl;
		return ( false );
	}
	if ( ! this->_renderLib->createWindow( 850, 550, "Test" ) )
	{
		std::cerr << "Failed to create window !" << std::endl;
		return ( false );
	}
	this->_isRunning = true;
	this->_game->init();
	while ( this->_isRunning )
	{
		startFrame = this->getTime();
		if ( this->_renderLib->isCloseRequest() )
		{
			this->stop();
			break ;
		}

		this->_game->update( dt );
		this->_game->render( this->_renderLib );

		endFrame = this->getTime();
		dt = (endFrame - startFrame);
		usleep( (SECOND / this->_fps) - (dt * SECOND) );
#if DEBUG
		// std::cout << "FPS: " << 1.0 / (this->getTime() - startFrame) << std::endl;
#endif
	}
	return ( true );
}

bool			CoreEngine::stop( void )
{
	if ( ! this->_isRunning )
		return ( false );
	this->_renderLib->destroyWindow();
	this->_isRunning = false;
	return ( true );
}

/*
**	GETTER
*/
ILib *			CoreEngine::getRenderLib( void ) const
{
	return ( this->_renderLib );
}

/*
**	SETTER
*/
void			CoreEngine::setrenderLib( ILib * renderLib )
{
	this->_renderLib = renderLib;
	return ;
}

void			CoreEngine::setGame( AGame * game )
{
	this->_game = game;
	return ;
}
