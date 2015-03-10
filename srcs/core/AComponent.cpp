/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AComponent.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:44:01 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 10:48:42 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AComponent.hpp"


void		AComponent::setPos( Vec2i pos )
{
	this->_pos = pos;
	return ;
}

Vec2i		AComponent::getPos(void)
{
	return this->_pos;
}

void		AComponent::setPos2( Vec2i pos2 )
{
	this->_pos2 = pos2;
	return ;
}

Vec2i		AComponent::getPos2(void)
{
	return this->_pos2;
}
