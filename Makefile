# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 16:05:59 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/04 16:39:39 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#DEV, BUID
MODE			=	DEV

ifeq ($(MODE), DEV)
	CPPFLAGS	=	-Wall -Wextra -ansi -O3
else
	CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi -O3
endif

CC				=	g++

NAME			=	nibbler

SRCS_DIR		=	srcs

FILES			=	$(NAME).cpp					\
					core/CoreEngine.cpp			\
					game/Nibbler.cpp

SRCS			=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			=	$(SRCS:.cpp=.o)


all:			$(NAME) libmlx.dylib libncurses.dylib libopengl.dylib

$(NAME):		$(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@printf "\033[33mCompilation of %-40s \033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

%.o:			%.cpp
	@printf "\t%-54s\033[34m[\033[32m✔\033[34m]\033[0m\n" $<
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "\033[31mRemove %s objects\033[0m\n" $(NAME)
	@rm -rf $(OBJS)
	@(cd ./libs/mlx_lib && $(MAKE) $@)
	@(cd ./libs/ncurses_lib && $(MAKE) $@)
	@(cd ./libs/opengl_lib && $(MAKE) $@)

fclean:			clean
	@printf "\033[31mRemove binary\033[0m\n"
	@rm -rf $(NAME)

re:				fclean all

libmlx.dylib:
	@make -C libs/mlx_lib

libncurses.dylib:
	@make -C libs/ncurses_lib

libopengl.dylib:
	@make -C libs/opengl_lib

.PHONY: all, clean, fclean, re

