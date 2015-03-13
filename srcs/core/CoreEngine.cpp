/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:02:44 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 14:43:41 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <dlfcn.h>
#include "CoreEngine.hpp"

CoreEngine::CoreEngine( float fps, int lib ) :
	_fps( fps ),
	_game( NULL ),
	_isRunning( false ),
	_lib( lib )
{
	loadLib( "./libs/ncurses_lib/libncurses.dylib" );
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

void			CoreEngine::loadLib( std::string lib )
{
	char *			err;
	ILib *			(*f)( void );

	this->_handle = dlopen( lib.c_str(), RTLD_NOW );
	// handle = dlopen( "./libs/opengl_lib/libopengl.dylib", RTLD_NOW );
	// handle = dlopen( "./libs/sdl_lib/libsdl.dylib", RTLD_NOW );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		exit( 0 );
		return ;
	}
	f = ( ILib *(*)() ) dlsym( this->_handle, "getInstance" );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		return ;
	}
	// delete this->_renderLib;
	this->_renderLib = f();
}

void			CoreEngine::switchLib( void )
{
	std::string lib;

	if ( this->_lib != 1 && this->_renderLib->isKeyPressed( ILib::F1 ) )
	{
		lib = "./libs/ncurses_lib/libncurses.dylib";
		this->_lib = 1;
	}
	else if ( this->_lib != 2 && this->_renderLib->isKeyPressed( ILib::F2 ) )
	{
		lib = "./libs/opengl_lib/libopengl.dylib";
		this->_lib = 2;
	}
	else if ( this->_lib != 3 && this->_renderLib->isKeyPressed( ILib::F3 ) )
	{
		lib = "./libs/sdl_lib/libsdl.dylib";
		this->_lib = 3;
	}
	else
		return ;
	this->_renderLib->destroyWindow();
	dlclose( this->_handle );
	loadLib( lib );

	if ( ! this->_renderLib->createWindow( 850, 550, "Test" ) )
	{
		std::cerr << "Failed to create window !" << std::endl;
		return ;
	}
	this->_renderLib->updateKeys();

	return ;
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
	if ( this->_game == NULL )
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
	while ( this->_isRunning && this->_game->isRunnig())
	{
		startFrame = this->getTime();
		this->_renderLib->updateKeys();
		this->switchLib();
		this->_renderLib->clearWindow();
		if ( this->_renderLib->isCloseRequest())
		{
			this->stop();
			break ;
		}

		this->_game->update( this->_renderLib, dt );
		this->_game->render( this->_renderLib );

		this->_renderLib->refreshWindow();

		endFrame = this->getTime();
		dt = (endFrame - startFrame);
		// usleep( 200000 );
		usleep( (SECOND / this->_fps) - (dt * SECOND) );
#if DEBUG
		// std::cout << "FPS: " << 1.0 / (this->getTime() - startFrame) << std::endl;
#endif
	}
	this->stop();
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
