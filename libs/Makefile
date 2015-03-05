# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 16:47:25 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/04 17:23:51 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi -O3

CC				=	g++

NAME			=	tests

all:
	@printf "\033[31musage: mlx_tests, ncurses_tests, opengl_tests\033[0n\n"

mlx_tests:
	@(cd ./mlx_lib && $(MAKE) re)
	@g++ -DLIB='"./mlx_lib/libmlx.dylib"' tests.cpp -o mlx$(NAME)
	@printf "\n\033[31m_______________________\033[32m \
	MLX TESTS \033[31m_______________________\033[0m\n"
	@./mlx$(NAME)

ncurses_tests:
	@(cd ./ncurses_lib && $(MAKE) re)
	@g++ -lncurses -DLIB='"./ncurses_lib/libncurses.dylib"' tests.cpp -o ncurses$(NAME)
	@printf "\n\033[31m_____________________\033[32m \
	NCURSES TESTS \033[31m_____________________\033[0m\n"
	@./ncurses$(NAME)

opengl_tests:
	@(cd ./opengl_lib && $(MAKE) re)
	@g++ -DLIB='"./opengl_lib/libopengl.dylib"' tests.cpp -o opengl$(NAME)
	@printf "\n\033[31m_____________________\033[32m \
	OPENGL TESTS \033[31m______________________\033[0m\n"
	@./opengl$(NAME)

all_tests: mlx_tests ncurses_tests opengl_tests

