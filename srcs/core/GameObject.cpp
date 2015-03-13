/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:57:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 14:49:03 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "AGame.hpp"

GameObject::GameObject( void )
{
	return ;
}

GameObject::~GameObject( void )
{
	return ;
}

GameObject::GameObject( GameObject const & src )
{
	*this = src;
}

GameObject &	GameObject::operator=( GameObject const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int			GameObject::update( ILib const * lib, double delta )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->update( lib, delta );
	return ( true );
}

int			GameObject::render( ILib const * lib ) const
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->render( lib );
	return ( true );
}

int			GameObject::addComponent( AComponent * component )
{
	this->_components.push_back( component );
	return ( true );
}

std::vector<AComponent *>	GameObject::getComponents( void )
{
	return this->_components;
}

void						GameObject::setGame(AGame * game)
{
	_game = game;
}

AGame*						GameObject::getGame( void ) const
{
	return ( this->_game );
}

void						GameObject::init( void )
{

}
