/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 10:49:28 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_HPP
# define GAME_OBJECT_HPP
# include <vector>
# include "AComponent.hpp"

class GameObject
{
public:
	GameObject( void );
	~GameObject( void );

	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;

	int							addComponent( AComponent * component );
private:
	std::vector<AComponent *>		_components;
};

#endif
