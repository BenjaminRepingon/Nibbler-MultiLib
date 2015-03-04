/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILib.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:09:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:21:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_LIB_HPP
# define I_LIB_HPP

class ILib
{
public:
	virtual bool		isCloseRequest( void ) = 0;
};

#endif
