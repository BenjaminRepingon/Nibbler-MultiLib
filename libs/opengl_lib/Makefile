# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 13:58:28 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/04 17:02:38 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libopengl

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror -pedantic -ansi -O3

SRC_LIB		=	$(NAME).cpp		\
				OpenglLib.cpp

OBJ_LIB		=	$(SRC_LIB:.cpp=.o)

HEAD		=	$(NAME).hpp


all:		$(NAME).dylib

$(NAME).dylib:	$(OBJ_LIB)
	@g++ -shared -o $(NAME).dylib $(OBJ_LIB)
	@printf "\033[33mCompilation of %-40s \033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

%.o:		%.cpp $(HEAD)
	@$(CC) $(CFLAGS) -fpic -c $< -o $@
	@printf "\t%-54s\033[34m[\033[32m✔\033[34m]\033[0m\n" $<

clean:
	@printf "\033[31mRemove %s objects\033[0m\n" $(NAME)
	@rm -rf $(OBJ_LIB)

fclean:			clean
	@printf "\033[31mRemove binary\033[0m\n"
	@rm -rf $(NAME).dylib

re:			fclean all

.PHONY:		all re fclean clean