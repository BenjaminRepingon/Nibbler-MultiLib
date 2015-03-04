/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:03:16 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:23:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_HPP
# define CORE_ENGINE_HPP
# include <iostream>
# include "../../ILib.hpp"
# include "AGame.hpp"

#ifndef TRUE
# define TRUE ( 1 )
#endif
#ifndef FALSE
# define FALSE ( 0 )
#endif
#ifndef NULL
# define NULL ( 0 )
#endif

class CoreEngine
{
public:
	CoreEngine( ILib * lib );
	CoreEngine( CoreEngine const & src );
	~CoreEngine( void );

	CoreEngine &			operator=( CoreEngine const & rhs );

	bool					start( void );
	bool					stop( void );

	/*
	**	GETTER
	*/
	ILib *					getRenderLib( void ) const;

	/*
	**	SETTER
	*/
	void					setrenderLib( ILib * renderLib );

private:
	CoreEngine( void );

	ILib *					_renderLib;
	AGame *					_game;
	bool					_isRunning;
};

#endif
