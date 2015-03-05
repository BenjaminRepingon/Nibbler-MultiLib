/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:46:14 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 15:50:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AGame.hpp"

int			AGame::addObject( GameObject * object )
{
	this->_objects.push_back( object );
	return ( true );
}

int			AGame::update( double delta )
{
	for ( size_t i = 0; i < this->_objects.size(); i++ )
		this->_objects[i]->update( delta );
	return ( true );
}
int			AGame::render( ILib const * lib ) const
{
	for ( size_t i = 0; i < this->_objects.size(); i++ )
		this->_objects[i]->render( lib );
	return ( true );
}
