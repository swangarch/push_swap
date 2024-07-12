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
#include "libft.h"

void	print_stack(t_list *lsta, t_list *lstb)
{
	ft_printf("stack a: ");
	lst_print(lsta);
	ft_printf("stack b: ");
	lst_print(lstb);
}

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

int	main(int argc, char **argv)
{
	int	i;
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	inputs = save_inputs(inputs, argc, argv, 1);
	if (inputs == NULL)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&lsta, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak并且数据错误，因此应该报错并且释放
		i++;
	}

	ft_printf("START\n");
	print_stack(lsta, lstb);
	ft_printf("_________________________________________\n");
	sa(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	rrb(&lsta, &lstb);
	print_stack(lsta, lstb);
	rra(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	ra(&lsta, &lstb);
	print_stack(lsta, lstb);
	rb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	
	ft_printf("List sorted: %s\n", (lst_sorted(lsta) ? "Yes" : "No"));
	ft_lstclear_nfunc(&lsta);
	free(inputs);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	i;
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	i = 1;
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
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
	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&lsta, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak
		i++;
	}
	ft_printf("START\n");
	print_stack(lsta, lstb);
	ft_printf("_________________________________________\n");
	sa(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pb(&lsta, &lstb);
	print_stack(lsta, lstb);
	rrb(&lsta, &lstb);
	print_stack(lsta, lstb);
	rra(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	ra(&lsta, &lstb);
	print_stack(lsta, lstb);
	rb(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	pa(&lsta, &lstb);
	print_stack(lsta, lstb);
	ft_lstclear_free(&lsta);
	free(inputs);
	return (0);
}*/
