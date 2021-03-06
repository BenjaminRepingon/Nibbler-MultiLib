/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:38:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 10:31:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_GAME_HPP
# define A_GAME_HPP
# include <vector>
# include <iostream>

# include "../../ILib.hpp"

class CoreEngine;
class GameObject;
class AGame
{
public:
	virtual ~AGame( void ) {};

	virtual int					init( void ) = 0;
	virtual int					addObject( GameObject * object );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
	virtual int					isRunnig( void );
	virtual int					setRunnig( int state );
	void						setCore( CoreEngine *core );
	CoreEngine*					getCore( void );

protected:
	int							_isRunning;
	std::vector<GameObject *>	_objects;
	CoreEngine*					_core;
};

#endif
