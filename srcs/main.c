/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:55 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:57:04 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*inputs;
	int			*inputs_copy;
	t_list		*lsta;
	t_list		*lstb;
	int 		num_elements;
	t_spliter	spl;

	inputs = NULL;
	lsta = NULL;
	lstb = NULL;
	num_elements = 0;
	if (argc == 2)
		input_save_argvinquote(argv, &inputs, &num_elements);
	else
		input_save_multiargv(argc, argv, &inputs, &num_elements);
	copy_tab_tolst(&lsta, inputs, num_elements);
	inputs_copy = inputs_dup(inputs, num_elements);
	ft_b_sort(inputs_copy, num_elements);
	set_spliter(&spl, inputs_copy, num_elements);
	lst_sort(&lsta, &lstb, &spl);
	delete_stack(&lsta, &lstb, inputs);
	return (0);
}
