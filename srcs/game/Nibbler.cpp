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
#include "objects/Snake.hpp"

#warning "TODO: copilian form for Nibbler"
Nibbler::Nibbler( void )
{
	return ;
}

Nibbler::~Nibbler( void )
{
	return ;
}

int				Nibbler::init( void )
{
	Snake *		snake;

	snake = new Snake( 10, 10, 5 );
	addObject( snake );

	return ( true );
}
