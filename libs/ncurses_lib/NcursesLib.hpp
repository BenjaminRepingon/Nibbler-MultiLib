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
# include "../../ILib.hpp"

class NcursesLib : public ILib
{
public:
	NcursesLib( void );
	~NcursesLib( void );

	bool		isCloseRequest( void );
	void		createWindow( int height, int width, std::string title );
	void		refreshWindow( void );
	void		destroyWindow( void );
	void		clearWindow( void );
	int			getKeyPressed( void );
private:
	std::string _title;
	WINDOW*		_window;
};

#endif
