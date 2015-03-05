/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:40:04 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:40:52 by rbenjami         ###   ########.fr       */
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
	return ( 0 );
}

bool NcursesLib::createWindow( int height, int width, std::string title)
{	
	this->_title = title;

	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	this->_window = newwin(height, width, 0, 0);
	wrefresh(this->_window);
	return TRUE;
}

bool NcursesLib::refreshWindow( void )
{
	wrefresh( this->_window );
	return TRUE;
}

bool NcursesLib::destroyWindow( void )
{
	delwin( this->_window );
	endwin( );
	return TRUE;
}

bool NcursesLib::clearWindow( void )
{
	// wclear(this->_window); seems to be too slow
	clear( );
	return TRUE;
}

int	NcursesLib::getKeyPressed( void )
{
	return getch( );
}
