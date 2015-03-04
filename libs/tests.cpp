/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:22:15 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/04 17:19:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <assert.h>
#include "../ILib.hpp"

int		main( void )
{
	ILib *			lib;
	void *			handle;
	ILib *			(*f)( void );

	handle = dlopen( LIB, RTLD_NOW );
	f = ( ILib *(*)() ) dlsym( handle, "getInstance" );
	lib = f();

	assert( lib->isCloseRequest() == 0 );

	return ( 0 );
}
