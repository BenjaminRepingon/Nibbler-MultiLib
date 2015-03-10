/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:22:15 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 17:24:22 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <assert.h>
#include <ncurses.h>
#include <unistd.h>
#include "../ILib.hpp"

int		main( void )
{
	ILib *			lib;
	void *			handle;
	ILib *			(*f)( void );

	handle = dlopen( LIB, RTLD_NOW );
	f = ( ILib *(*)() ) dlsym( handle, "getInstance" );
	lib = f();

	assert( lib->isCloseRequest() == 0 );

	lib->createWindow(2, 20, "prout");
	int ch = 0, x = 0, y = 0;
	lib->updateKeys();

	while(!lib->isKeyPressed(ILib::ESC))
	{
		lib->drawLine(10, 0, 10, 20);
		lib->drawLine(10, 0, 10, 20);
		lib->drawLine(10, 0, 10, 20);
		lib->drawLine(10, 0, 10, 20);
		lib->clearWindow();
		if (lib->isKeyPressed(ILib::DOWN))
			x++;
		else if (lib->isKeyPressed(ILib::UP))
			x--;
		else if (lib->isKeyPressed(ILib::LEFT))
			y--;
		else if (lib->isKeyPressed(ILib::RIGHT))
			y++;
		lib->drawSquare(x,y, 2);
		lib->refreshWindow();
		lib->updateKeys();
		usleep(200);
	}
	lib->destroyWindow();
	return ( 0 );
}
