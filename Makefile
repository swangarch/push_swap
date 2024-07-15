# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shuwang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:44:35 by shuwang           #+#    #+#              #
#    Updated: 2024/07/15 16:12:32 by shuwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS = main.c lst_sort.c instruction_p.c instruction_r.c instruction_rv.c \
       instruction_s.c push_swap_utils.c check_input.c

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
