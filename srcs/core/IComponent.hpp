/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IComponent.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:32:03 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/05 15:41:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_COMPONENT_HPP
# define I_COMPONENT_HPP
# include "../../ILib.hpp"

class IComponent
{
public:
	virtual int					update( double delta ) = 0;
	virtual int					render( ILib const * lib ) const = 0;
};

#endif
