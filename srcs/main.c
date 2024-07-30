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
	if (lst_sorted(lsta))
		return ;
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

int	main(int argc, char **argv)///检查输入是“包裹起来的情况”
{
	int	i;
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	/*if argv == 2检查输入是“包裹起来的情况”_____________________________________________
	char **args_inquote;
	int	j = 0;
	if (argc == 2)
	{
		args_inquote = ft_split(argv[1], " ");
		while (args_inquote[j])
		{
			if (all_digits(args_inquote[j]) && !int_overflow(argv[i]))/////////////////
				inputs[i - 1] = ft_atoi(argv[i]);//////////////////////
			j++;////////////////////////////////
		}

	}
	if argv == 2检查输入是“包裹起来的情况”______________________________________________*/
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

	int num_elements = argc - 1; ////////////////Not consider the case where not arguments are in quote


	if (num_elements < 2)
		return (0);
	else if (num_elements == 2)
	{
		if (inputs[0] > inputs[1])
		{
			ft_putstr_fd("sa\n", 1);
			free(inputs);
			return(0);
		}
		else
		{
			free(inputs);
			return(0);
		}
	}
	else if (num_elements == 3)
	{
		if (inputs[0] < inputs[1] && inputs[1] < inputs[2])///0 1 2
		{
			free(inputs);
			return(0);
		}
		else if (inputs[0] < inputs[1] && inputs[1] > inputs[2] && inputs[2] > inputs[0])/// 0 2 1
		{
			ft_putstr_fd("sa\nra\n", 1);
			free(inputs);
			return(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] < inputs[2] && inputs[2] > inputs[0])/// 1 0 2
		{
			ft_putstr_fd("sa\n", 1);
			free(inputs);
			return(0);
		}
		else if (inputs[0] < inputs[1] && inputs[1] > inputs[2] && inputs[2] < inputs[0])///1 2 0
		{
			ft_putstr_fd("rra\n", 1);
			free(inputs);
			return(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] < inputs[2] && inputs[2] < inputs[0])///2 0 1
		{
			ft_putstr_fd("ra\n", 1);
			free(inputs);
			return(0);
		}
		else if (inputs[0] > inputs[1] && inputs[1] > inputs[2])///2 1 0
		{
			ft_putstr_fd("sa\nrra\n", 1);
			free(inputs);
			return(0);
		}
		else
		{
			ft_putstr_fd("error\n", 1);
			return(0);
		}
	}

	
	push_swap(lsta, lstb);
	ft_lstclear_nfunc(&lsta);
	free(inputs);
	return (0);
}
