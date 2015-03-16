/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:04:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/03/13 16:39:10 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/CoreEngine.hpp"
#include "game/Nibbler.hpp"

int checkParams(int ac, char const *av[])
{
	int x;
	int y;
	if (ac == 3)
	{
		x = atoi(av[1]);
		y = atoi(av[2]);
		if (x <= 60 && y <= 60 && x > 14 && y > 14)
		{
			return 1;
		}
	}
	printf("Game Size must be betwwen x/y 15 and x/y 60\n");
	return 0;
}

int		main(int argc, char const *argv[])
{
	CoreEngine *	core;
	Nibbler *		nibbler;

	srand(time(NULL));
	if (!checkParams(argc, argv))
		return 0;

	core = new CoreEngine( 8, 1 );

	nibbler = new Nibbler( atoi(argv[1]), atoi(argv[2]) );

	core->setGame( nibbler );
	core->start();
	return ( 0 );
}
