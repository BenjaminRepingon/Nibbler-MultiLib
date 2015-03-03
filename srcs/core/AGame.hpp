/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:38:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/03 18:32:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_GAME_HPP
# define A_GAME_HPP

class AGame
{
public:
	virtual ~AGame( void ) {};

	virtual int				init( void ) = 0;
};

#endif
