/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:57:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 16:09:22 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

#warning "TODO: copilian form for GameObject"
GameObject::GameObject( void )
{
	return ;
}

GameObject::~GameObject( void )
{
	return ;
}

int			GameObject::update( double delta )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->update( delta );
	return ( true );
}

int			GameObject::render( ILib const * lib ) const
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->render( lib );
	return ( true );
}

