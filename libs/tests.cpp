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
	while((ch = lib->getKeyPressed()) != 27)
	{
		lib->clearWindow();
		if (ch == KEY_DOWN)
			x++;
		else if (ch == KEY_UP)
			x--;
		else if (ch == KEY_LEFT)
			y--;
		else if (ch == KEY_RIGHT)
			y++;
		mvprintw(x, y, "yolooo");
		lib->refreshWindow();
	}

	lib->destroyWindow();


	return ( 0 );
}
