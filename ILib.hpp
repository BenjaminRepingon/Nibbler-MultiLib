/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILib.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:09:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:21:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_LIB_HPP
# define I_LIB_HPP
# include <iostream>

class ILib
{
public:
	virtual bool		isCloseRequest( void ) = 0;
	virtual bool		createWindow( int height, int width, std::string title) = 0;
	virtual bool		refreshWindow( void ) = 0;
	virtual bool		destroyWindow( void ) = 0;
	virtual bool		clearWindow( void ) = 0;
	virtual	int			getKeyPressed( void ) = 0;
	virtual void		drawSquare(int posX, int posY, int size) = 0;
};

#endif
