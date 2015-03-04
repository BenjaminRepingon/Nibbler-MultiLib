/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:44:51 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:45:13 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_LIB_HPP
# define OPENGL_LIB_HPP
# include "../../ILib.hpp"

class OpenglLib : public ILib
{
public:
	OpenglLib( void );
	~OpenglLib( void );

	bool		isCloseRequest( void );

};

#endif
