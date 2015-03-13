/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:41:36 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 16:10:23 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HPP
# define NIBBLER_HPP
# include "../core/AGame.hpp"
# include "objects/Snake.hpp"
# include "objects/Food.hpp"
# include "objects/Limit.hpp"
# include "objects/Labyrinthe.hpp"

class Nibbler : public AGame
{
public:
	Nibbler( int, int );
	virtual ~Nibbler( void );

	virtual int				init( void );
	int						getWidth( void );
	int						getHeight( void );
	int						checkBasicCollision( AComponent* );
	int						checkWallCollision( AComponent* );
	int						checkFoodCollision( AComponent*, Snake* );
	int						checkFoodCollision( AComponent*, int j);
	int						update( ILib const * lib, double delta );
	void					popFood( int i, std::vector<AComponent *> foodElements );
	void					checkLevel( void );

private:
	int						_width;
	int						_height;

	Snake*					_snake;
	Snake*					_snake2;
	Food*					_food;
	Limit*					_limit;
	Labyrinthe*				_labyrinthe;

	int 					_level;
};

#endif
