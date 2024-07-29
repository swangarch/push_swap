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

int	*save_inputs(int *inputs, int argc, char **argv, int i)
{
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			inputs[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(inputs);
			return (NULL);
		}
		i++;
	}
	if (check_double(inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(inputs);
		return (NULL);
	}
	return (inputs);
}

void	push_swap(t_list *lsta, t_list *lstb)
{
	//ft_printf("________START_sort_stack________________________________________\n");
	lst_sort(&lsta, &lstb);
	//ft_printf("________STOP_sort_stack_________________________________________\n");
}

int	input_error(int argc, char **argv, int *inputs)
{
	int	i;

	i = 1;
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			inputs[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(inputs);
			return (1);
		}
		i++;
	}
	if (check_double(inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(inputs);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (input_error(argc, argv, inputs))
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&lsta, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak
		i++;
	}
	push_swap(lsta, lstb);
	ft_lstclear_nfunc(&lsta);
	free(inputs);
	return (0);
}
