/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:54:27 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 11:32:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP
# include "../../core/GameObject.hpp"
# include "../components/SnakePart.hpp"
# include "../Nibbler.hpp"
# include "Food.hpp"
# include <cstdlib> 

class Snake : public GameObject
{
public:
	// Snake( void );
	Snake( int posX, int posY, size_t nbPart, Food *food );
	~Snake( void );

	virtual int					update( ILib const * lib, double delta );



private:
	Vec2i						_pos;
	Vec2i						_dir;
	size_t						_nbPart;
	Food						*_food;
	float						_speed;

	int							checkCollision( void );
	void			grow( void );
	void			popFood( int i, std::vector<AComponent *> foodElements );
	bool			checkNewPosition( int j, std::vector<AComponent *> foodElements );


};

#endif
