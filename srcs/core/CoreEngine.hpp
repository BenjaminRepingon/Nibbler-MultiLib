/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:03:16 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/03 17:54:19 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_HPP
# define CORE_ENGINE_HPP
# include "./render/RenderLib.hpp"

class CoreEngine
{
public:
	CoreEngine( RenderLib * renderLib );
	CoreEngine( CoreEngine const & src );
	~CoreEngine( void );

	CoreEngine &			operator=( CoreEngine const & rhs );

	bool					start( void );
	bool					stop( void );

	/*
	**	GETTER
	*/
	RenderLib *				getRenderLib( void ) const;

	/*
	**	SETTER
	*/
	void					setrenderLib( RenderLib * renderLib );

private:
	CoreEngine( void );

	RenderLib *				_renderLib;
	bool					_isRunning;
};

#endif
