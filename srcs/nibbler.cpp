/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:04:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:24:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/CoreEngine.hpp"

#warning "TODO: parse params"
int		main(/*int argc, char const *argv[]*/)
{
	CoreEngine *	core;
	ILib *			lib;

	lib = NULL;
	core = new CoreEngine( lib );

	core->start();
	return ( 0 );
}
