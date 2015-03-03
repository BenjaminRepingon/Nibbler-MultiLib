/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:02:44 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/03 18:02:51 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CoreEngine.hpp"

CoreEngine::CoreEngine( RenderLib * renderLib ) :
	_renderLib( renderLib )
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
	return ( 1 );
}

bool			CoreEngine::stop( void )
{
	return ( 1 );
}

/*
**	GETTER
*/
RenderLib *		CoreEngine::getRenderLib( void ) const
{
	return ( this->_renderLib );
}

/*
**	SETTER
*/
void			CoreEngine::setrenderLib( RenderLib * renderLib )
{
	this->_renderLib = renderLib;
	return ;
}
