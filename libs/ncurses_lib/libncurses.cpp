/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libncurses.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:27:03 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:46:05 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesLib.hpp"

extern "C"
ILib *		getInstance( void )
{
	return ( new NcursesLib() );
}
