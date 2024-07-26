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

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS = main.c lst_sort.c instruction_p.c instruction_r.c instruction_rv.c \
    	instruction_s.c push_swap_utils.c check_input.c

BONUS_SRCS = srcs_bonus/instruction_p_bonus.c srcs_bonus/instruction_r_bonus.c \
		srcs_bonus/instruction_rv_bonus.c srcs_bonus/instruction_s_bonus.c \
		push_swap_utils.c check_input.c cheker_bonus.c

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(SRCS_BONUS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
