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
# include <cstdlib> 

# define SECOND		(1000000.0)


class Snake : public GameObject
{
public:
	// Snake( void );
	Snake( int posX, int posY, size_t nbPart );
	~Snake( void );

	virtual int					update( ILib const * lib, double delta );
	virtual void				init( void );
	void						grow( void );
	bool						getInvincible( void );
	void						setInvincible( bool );
	double						getTime( void );
	void						setColour( int c );

private:
	Vec2i						_pos;
	Vec2i						_dir;
	size_t						_nbPart;
	bool						_invincible;
	double						_startFrame;
	double						_endFrame;
	double						_dt;
	// Food						*_food;
	// Labyrinthe					*_labyrinthe;

	float						_speed;

	int							_points;

	// int							checkCollision( void );

	// void			popFood( int i, std::vector<AComponent *> foodElements );
	// bool			checkNewPosition( int j, std::vector<AComponent *> foodElements );


};

#endif
