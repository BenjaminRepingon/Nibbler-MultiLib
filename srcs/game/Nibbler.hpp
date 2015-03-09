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

class Nibbler : public AGame
{
public:
	Nibbler( void );
	virtual ~Nibbler( void );

	virtual int				init( void );
};

#endif
