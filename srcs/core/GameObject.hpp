/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 14:49:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_HPP
# define GAME_OBJECT_HPP
# include <vector>
# include "AComponent.hpp"
# include "AGame.hpp"

class GameObject
{
public:
	GameObject( void );
	~GameObject( void );
	GameObject( GameObject const & src );

	GameObject &				operator=( GameObject const & rhs );

	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;

	int							addComponent( AComponent * component );
	std::vector<AComponent *>	getComponents( void );
	void						setGame(AGame * game);
	AGame*						getGame( void ) const;
	virtual void				init( void );

protected:
	AGame*							_game;
	std::vector<AComponent *>		_components;
};

#endif
