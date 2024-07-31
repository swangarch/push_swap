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

void	push_swap_small(int *inputs, int num_elements)
{
	if (num_elements < 2)
	{
		free(inputs);
		exit(0);
	}
	else if (num_elements == 2)
	{
		if (inputs[0] > inputs[1])
		{
			ft_putstr_fd("sa\n", 1);
			free(inputs);
			exit(0);
		}
		else
		{
			free(inputs);
			exit(0);
		}
	}
	else if (num_elements == 3)
	{
		if (inputs[0] < inputs[1] && inputs[1] < inputs[2])///0 1 2
		{
			free(inputs);
			exit(0);
		}
		else if (inputs[0] < inputs[1] && inputs[1] > inputs[2] && inputs[2] > inputs[0])/// 0 2 1
		{
			ft_putstr_fd("sa\nra\n", 1);
			free(inputs);
			exit(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] < inputs[2] && inputs[2] > inputs[0])/// 1 0 2
		{
			ft_putstr_fd("sa\n", 1);
			free(inputs);
			exit(0);
		}
		else if (inputs[0] < inputs[1] && inputs[1] > inputs[2] && inputs[2] < inputs[0])///1 2 0
		{
			ft_putstr_fd("rra\n", 1);
			free(inputs);
			exit(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] < inputs[2] && inputs[2] < inputs[0])///2 0 1
		{
			ft_putstr_fd("ra\n", 1);
			free(inputs);
			exit(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] > inputs[2])///2 1 0
		{
			ft_putstr_fd("sa\nrra\n", 1);
			free(inputs);
			exit(0);
		}
		else
		{
			ft_putstr_fd("error\n", 1);
			exit(0);
		}
	}
}

void	push_swap_big(t_list *lsta, t_list *lstb)
{
	//ft_printf("________START_sort_stack________________________________________\n");
	if (lst_sorted(lsta))
		return ;
	lst_sort(&lsta, &lstb);
	//ft_printf("________STOP_sort_stack_________________________________________\n");
}

void	input_save_multiargv(int argc, char **argv, int **inputs, int *num_elements)
{
	int	i;

	*num_elements = argc - 1;
	*inputs = malloc(sizeof(int) * (argc - 1));
	if (*inputs == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			(*inputs)[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(*inputs);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (check_double(*inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(*inputs);
		exit(EXIT_FAILURE);
	}
}

void	input_save_argvinquote(char **argv, int **inputs, int *num_elements)
{
		char **args_inquote;
		int	j = 0;
		int count = 0;

		args_inquote = ft_split(argv[1], ' ');
		if (args_inquote == NULL)
			exit(EXIT_FAILURE);
		else
		{
			while (args_inquote[count])
				count++;
			*inputs = malloc(sizeof(int) * (count));
			if (!inputs)
			{
				free_tab(args_inquote);
				exit(EXIT_FAILURE);
			}
		}
		while (args_inquote[j])
		{
			if (all_digits(args_inquote[j]) && !int_overflow(args_inquote[j]))
			{
				(*inputs)[j] = ft_atoi(args_inquote[j]);
				j++;
			}
			else
			{
				write(2, "Error\n", 6);
				free_tab(args_inquote);
				free(*inputs);
				exit(EXIT_FAILURE);
			}
		}
		if (check_double(*inputs, count))
		{
			write(2, "Error\n", 6);
			free_tab(args_inquote);
			free(*inputs);
			exit(EXIT_FAILURE);
		}
		free_tab(args_inquote);
		*num_elements = count;
}

void	copy_tab_tolst(t_list **lst, int *inputs, int num_elements)////maybe use int to return a value
{
	int	i;
	i = 0;
	while (i < num_elements)
	{
		ft_lstadd_back(lst, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak protect
		i++;
	}
}

int	main(int argc, char **argv)///检查输入是“包裹起来的情况”
{
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;
	int num_elements;

	inputs = NULL;
	lsta = NULL;
	lstb = NULL;
	num_elements = 0;

	if (argc == 2)
		input_save_argvinquote(argv, &inputs, &num_elements);
	else
		input_save_multiargv(argc, argv, &inputs, &num_elements);
	push_swap_small(inputs, num_elements);///the case where input is less than 3
	copy_tab_tolst(&lsta, inputs, num_elements);
	push_swap_big(lsta, lstb);///the case where input is bigger than 3
	ft_lstclear_nfunc(&lsta);
	free(inputs);
	return (0);
}
