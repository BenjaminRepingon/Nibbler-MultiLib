/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:04:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 13:52:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "core/CoreEngine.hpp"
#include "game/Nibbler.hpp"
#include <cstdlib>

#warning "TODO: parse params"

int checkParams(int ac, char const *av[])
{
	int x;
	int y;
	if (ac == 3)
	{
		x = atoi(av[1]);
		y = atoi(av[2]);
		if (x <= 60 && y <= 60 && x > 5 && y > 5)
		{
			return 1;
		}
	}
	printf("Game Size must be betwwen x/y 5 and x/y 60\n");
	return 0;
}

int		main(int argc, char const *argv[])
{
	CoreEngine *	core;
	Nibbler *		nibbler;
	ILib *			lib;
	void *			handle;
	ILib *			(*f)( void );
	char *			err;


	srand(time(NULL));
	if (!checkParams(argc, argv))
		return 0;

	handle = dlopen( "./libs/sdl_lib/libsdl.dylib", RTLD_NOW );
	// handle = dlopen( "./libs/ncurses_lib/libncurses.dylib", RTLD_NOW );
	// handle = dlopen( "./libs/opengl_lib/libopengl.dylib", RTLD_NOW );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		return ( -1 );
	}
	f = ( ILib *(*)() ) dlsym( handle, "getInstance" );
	lib = f();
	core = new CoreEngine( 8, lib );

	nibbler = new Nibbler( atoi(argv[1]), atoi(argv[2]) );

	core->setGame( nibbler );
	core->start();
	return ( 0 );
}
