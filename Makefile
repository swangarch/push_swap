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

INCLUDE = -I./libft -I./header

SRCS = srcs/main.c srcs/lst_sort.c srcs/instruction_p.c srcs/instruction_r.c srcs/instruction_rv.c \
    	srcs/instruction_s.c srcs/push_swap_utils.c srcs/check_input.c srcs/lst_sort_small.c \
	    srcs/push_low_cost_btoa.c srcs/lst_utils.c srcs/rotate_to_top.c srcs/set_spliter.c \
		srcs/destroy_vars.c srcs/parse_args.c

SRCS_BONUS = srcs_bonus/instruction_p_bonus.c srcs_bonus/instruction_r_bonus.c \
		srcs_bonus/instruction_rv_bonus.c srcs_bonus/instruction_s_bonus.c \
		srcs/push_swap_utils.c srcs/check_input.c srcs_bonus/checker_bonus.c srcs/destroy_vars.c \
		srcs/parse_args.c srcs/lst_utils.c

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(LIBFT) -o $(NAME)

bonus: $(SRCS_BONUS)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(INCLUDE) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
