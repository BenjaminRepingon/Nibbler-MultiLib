/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:40:13 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/11 18:24:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_LIB_HPP
# define NCURSES_LIB_HPP
# include <ncurses.h>
# include <vector>
# include <map>
# include "../../ILib.hpp"
# include "../../srcs/utils/vec.hpp"

# define COLOR_SQUARE (1000)

class NcursesLib : public ILib
{
public:
	NcursesLib( void );
	~NcursesLib( void );

	bool				isCloseRequest( void ) const;
	bool				createWindow( int height, int width, std::string title );
	bool				refreshWindow( void );
	bool				destroyWindow( void );
	bool				clearWindow( void );
	bool				isKeyPressed( e_key ) const;
	void				updateKeys( void );
	void				drawSquare( int posX, int posY, int size, int color ) const;
	void				drawLine( float x1, float y1, float x2, float y2, int color ) const;
	void				drawText( float x1, float y1, char* s, int points, int color ) const;

	static std::map<int, int>	_colors;
private:
	std::string 		_title;
	WINDOW*				_window;
	bool				_keys[SIZEOF];

};

#endif
