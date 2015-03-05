/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 16:09:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_HPP
# define GAME_OBJECT_HPP
# include <vector>
# include "IComponent.hpp"

class GameObject
{
public:
	GameObject( void );
	~GameObject( void );

	virtual int					update( double delta );
	virtual int					render( ILib const * lib ) const;
private:
	std::vector<IComponent *>		_components;
};

#endif
