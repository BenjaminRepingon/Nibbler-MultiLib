/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AComponent.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:32:03 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 10:52:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_COMPONENT_HPP
# define A_COMPONENT_HPP
# include "../../ILib.hpp"
# include "../utils/vec.hpp"
class GameObject;

class AComponent
{
public:
	virtual int					update( ILib const * lib, double delta ) = 0;
	virtual int					render( ILib const * lib ) const = 0;

	/*
	**	SETTER
	*/

	void						setPos(Vec2i pos);
	Vec2i						getPos(void);
	void						setPos2(Vec2i pos2);
	Vec2i						getPos2(void);
	
protected:
	Vec2i 			_pos;
	Vec2i 			_pos2;

};

#endif
