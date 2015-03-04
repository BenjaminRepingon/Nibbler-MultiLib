/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MlxLib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:25:10 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 16:26:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LIB_HPP
# define MLX_LIB_HPP
# include "../../ILib.hpp"

class MlxLib : public ILib
{
public:
	MlxLib( void );
	~MlxLib( void );

	bool		isCloseRequest( void );

};

#endif
