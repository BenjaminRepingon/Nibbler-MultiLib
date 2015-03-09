/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakePart.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:54:55 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/06 12:12:09 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_PART_HPP
# define SNAKE_PART_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"

class SnakePart : public AComponent
{
public:
	// SnakePart( void );
	SnakePart( Vec2i const & pos, int size, SnakePart *parent );
	~SnakePart( void );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
	void						setParent( SnakePart * parent );

private:
	int							_size;
	SnakePart *					_parent;
};

#endif