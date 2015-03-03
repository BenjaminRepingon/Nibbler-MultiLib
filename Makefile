# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 16:05:59 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/03 18:33:06 by rbenjami         ###   ########.fr        #
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
					core/render/RenderLib.cpp	\
					game/Nibbler.cpp

SRCS			=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			=	$(SRCS:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@printf "\033[33m\nCompilation of %s: \033[32mSuccess \t\
			\033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

%.o:			%.cpp
	@printf "%-50s\t\033[34m[\033[32m✔\033[34m]\033[0m\n" $<
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "\033[31mRemove objects\033[0m\n"
	@rm -rf $(OBJS)

fclean:			clean
	@printf "\033[31mRemove binary\033[0m\n"
	@rm -rf $(NAME)

re:				fclean all


.PHONY: all, clean, fclean, re
