/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:40:13 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:40:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_LIB_HPP
# define NCURSES_LIB_HPP
# include <ncurses.h>
# include <vector>
# include "../../ILib.hpp"
# include "../../srcs/utils/vec.hpp"

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
	void				drawSquare(int posX, int posY, int size) const;
	void				drawLine( float x1, float y1, float x2, float y2 ) const;

private:
	std::string 		_title;
	WINDOW*				_window;
	bool				_keys[SIZEOF];

};

#endif
