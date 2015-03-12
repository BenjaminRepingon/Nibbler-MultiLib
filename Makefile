# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 16:05:59 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/12 11:24:12 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#DEV, BUID
MODE			=	DEV

ifeq ($(MODE), DEV)
	CPPFLAGS	=	-Wall -Wextra -ansi -O3 -DDEBUG
else
	CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi -O3
endif

CC				=	g++

NAME			=	nibbler

SRCS_DIR		=	srcs

FILES			=	$(NAME).cpp						\
					core/CoreEngine.cpp				\
					core/GameObject.cpp				\
					core/AGame.cpp					\
					core/AComponent.cpp				\
					\
					game/Nibbler.cpp				\
					game/components/SnakePart.cpp	\
					game/objects/Snake.cpp			\
					game/components/FoodElement.cpp	\
					game/objects/Food.cpp			\
					game/components/LimitSide.cpp	\
					game/objects/Limit.cpp			\
					game/components/Wall.cpp		\
					game/objects/Labyrinthe.cpp		\


SRCS			=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			=	$(SRCS:.cpp=.o)

HEADS			=	$(SRCS:.cpp=.hpp)

all:			$(NAME)

$(NAME):		$(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@printf "\033[33mCompilation of %-40s \033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

$(OBJS):		$(HEADS)

%.o:			%.cpp
	@printf "\t\033[36m-> %-45s\033[34m[\033[32m✔\033[34m]\033[0m\n" $<
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

lib:
	@make -C ./libs/ncurses_lib/
	@make -C ./libs/opengl_lib/

re-libs:
	@make re -C ./libs/ncurses_lib/
	@make re -C ./libs/opengl_lib/

re:				fclean all

.PHONY: all, clean, fclean, re

