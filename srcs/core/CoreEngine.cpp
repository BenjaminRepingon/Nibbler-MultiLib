/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:02:44 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:23:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CoreEngine.hpp"

CoreEngine::CoreEngine( ILib * lib ) :
	_renderLib( lib ),
	_game( NULL ),
	_isRunning( FALSE )
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

bool			CoreEngine::start( void )
{
	if ( this->_isRunning == TRUE )
	{
		std::cerr << "CoreEngine alrady running !" << std::endl;
		return ( FALSE );
	}
	// if ( this->_game == NULL )
	// {
	// 	std::cerr << "CoreEngine need a game !" << std::endl;
	// 	return ( FALSE );
	// }
	this->_isRunning = TRUE;
	// this->_game->init();
	while ( this->_isRunning )
	{
		if ( this->_renderLib->isCloseRequest() )
		{
			this->stop();
			break ;
		}
	}
	return ( TRUE );
}

bool			CoreEngine::stop( void )
{
	if ( ! this->_isRunning )
		return ( FALSE );
	this->_isRunning = FALSE;
	return ( TRUE );
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
