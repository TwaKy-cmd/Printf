# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khebert <khebert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 18:48:29 by khebert           #+#    #+#              #
#    Updated: 2025/11/22 23:52:00 by khebert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
rm		= rm -f

SRC		=	ft_basic_function.c 	\
			ft_hexa_function.c 		\
			ft_printf.c 			\
	
OBJ 	= $(SRC:.c=.o)

all: $(NAME)

GREEN_COLOR = \033[0;32m

RED_COLOR = \033[0;31m

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo -e '$(GREEN_COLOR)The$(RED_COLOR) $(NAME)$(GREEN_COLOR) as been built !'
	
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:: fclean all

.PHONY: all clean fclean re
