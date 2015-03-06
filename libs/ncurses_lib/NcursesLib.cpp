/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:40:04 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 10:35:24 by rbenjami         ###   ########.fr       */
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

bool		NcursesLib::isCloseRequest( void ) const
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

void		NcursesLib::updateKeys( void )
{
	static int keyLink[][2] = 
	{
		{ESC, 27},
		{RIGHT, KEY_RIGHT},
		{LEFT, KEY_LEFT},
		{UP, KEY_UP},
		{DOWN, KEY_DOWN},
		{F1, '1'},
		{F2, '2'},
		{F3, '3'}
	};

	int ch;
	ch = getch();
	for (int i = 0; i < SIZEOF; i++)
	{
		this->_keys[i] = (keyLink[i][1] == ch);
	}
}

bool		NcursesLib::isKeyPressed( e_key key ) const
{
	return (this->_keys[key]);
}

void		NcursesLib::drawSquare(int posX, int posY, int size) const
{
	for (int x = 0; x < size; x++)
	{
			for (int y = 0; y < size; y++)
				mvprintw(posX + x, posY + y, "*");
	}

}
