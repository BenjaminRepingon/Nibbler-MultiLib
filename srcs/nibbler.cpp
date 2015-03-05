/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:04:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 17:33:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "core/CoreEngine.hpp"
#include "game/Nibbler.hpp"

#warning "TODO: parse params"
int		main(/*int argc, char const *argv[]*/)
{
	CoreEngine *	core;
	Nibbler *		nibbler;
	ILib *			lib;
	void *			handle;
	ILib *			(*f)( void );
	char *			err;

	handle = dlopen( "./libs/ncurses_lib/libncurses.dylib", RTLD_NOW );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		return ( -1 );
	}
	f = ( ILib *(*)() ) dlsym( handle, "getInstance" );
	lib = f();
	core = new CoreEngine( 60, lib );

	nibbler = new Nibbler();

	core->setGame( nibbler );
	core->start();
	return ( 0 );
}
