/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:40:04 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 17:36:24 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesLib.hpp"

NcursesLib::NcursesLib( void )
{
	return ;
}

NcursesLib::~NcursesLib( void )
{
	return ;
}

bool		NcursesLib::isCloseRequest( void )
{
	return ( getch() == 27 );
}

bool		NcursesLib::createWindow( int height, int width, std::string title)
{
	this->_title = title;

	initscr();
	cbreak();
	nodelay( stdscr, true );
	keypad( stdscr, true );
	noecho();
	curs_set( 0 );
	this->_window = newwin( height, width, 0, 0 );
	wrefresh(this->_window);
	return ( true );
}

bool		NcursesLib::refreshWindow( void )
{
	wrefresh( this->_window );
	return ( true );
}

bool		NcursesLib::destroyWindow( void )
{
	delwin( this->_window );
	endwin( );
	return ( true );
}

bool		NcursesLib::clearWindow( void )
{
	// wclear(this->_window); seems to be too slow
	clear( );
	return ( true );
}

int			NcursesLib::getKeyPressed( void )
{
	return getch( );
}

void NcursesLib::drawSquare(int posX, int posY, int size)
{
	for (int x = 0; x < size; x++)
	{
			for (int y = 0; y < size; y++)
				mvprintw(posX + x, posY + y, "*");
	}
	
}
