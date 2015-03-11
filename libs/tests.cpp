/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:22:15 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/11 15:23:42 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <assert.h>
#include <ncurses.h>
#include <unistd.h>
#include "../ILib.hpp"

int		main( void )
{
	bool			error;
	ILib *			lib;
	void *			handle;
	ILib *			(*f)( void );

	handle = dlopen( LIB, RTLD_NOW );
	f = ( ILib *(*)() ) dlsym( handle, "getInstance" );
	lib = f();

	assert( lib->createWindow(850, 550, "test") );

	assert( lib->isCloseRequest() == 0 );
	int ch = 0, x = 0, y = 0;
	lib->updateKeys();

	while(!lib->isCloseRequest())
	{
		// lib->drawLine(10, 0, 10, 20);
		// lib->drawLine(10, 0, 10, 20);
		lib->clearWindow();
		lib->updateKeys();
		lib->drawLine(0, 0, 60, 0);
		lib->drawLine(60, 0, 60, 60);
		lib->drawLine(60, 60, 0, 60);
		lib->drawLine(0, 60, 0, 0);
		if (lib->isKeyPressed(ILib::DOWN))
			x++;
		else if (lib->isKeyPressed(ILib::UP))
			x--;
		else if (lib->isKeyPressed(ILib::LEFT))
			y--;
		else if (lib->isKeyPressed(ILib::RIGHT))
			y++;
		lib->drawSquare(x,y, 2);
		lib->drawSquare(0,0, 1);
		// lib->drawSquare(30,30, 1);
		// lib->drawSquare(-31,-31, 1);
		lib->refreshWindow();
		usleep(50000);
	}
	lib->destroyWindow();
	return ( 0 );
}
