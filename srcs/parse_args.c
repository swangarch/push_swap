/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:30:52 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:44:32 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_save_multiargv(int argc, char **argv, int **inputs, int *num)
{
	int	i;

	*num = argc - 1;
	*inputs = malloc(sizeof(int) * (argc - 1));
	if (*inputs == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i], 0, 1, 0))
			(*inputs)[i - 1] = ft_atoi(argv[i]);
		else
			in_fail_multiargv(inputs);
		i++;
	}
	if (check_double(*inputs, i - 1))
		in_fail_multiargv(inputs);
}

char	**split_args_inquote(char **argv, int **inputs, int *count)
{
	char	**args_inquote;

	args_inquote = ft_split(argv[1], ' ');
	if (args_inquote == NULL)
	{	
		free(inputs);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (args_inquote[(*count)])
			(*count)++;
		*inputs = malloc(sizeof(int) * (*count));
		if (*inputs == NULL)
			in_fail_argvinquote(inputs, args_inquote);
	}
	return (args_inquote);
}

void	input_save_argvinquote(char **argv, int **inputs, int *num_elements)
{
	char	**args_inquote;
	int		count;
	int		j;

	count = 0;
	j = 0;
	args_inquote = split_args_inquote(argv, inputs, &count);
	while (args_inquote[j])
	{
		if (all_digits(args_inquote[j]) && \
				!int_overflow(args_inquote[j], 0, 1, 0))
		{
			(*inputs)[j] = ft_atoi(args_inquote[j]);
			j++;
		}
		else
			in_fail_argvinquote(inputs, args_inquote);
	}
	if (check_double(*inputs, count))
		in_fail_argvinquote(inputs, args_inquote);
	free_tab(args_inquote);
	*num_elements = count;
}

void	copy_tab_tolst(t_list **lst, int *inputs, int num_elements)
{
	int		i;
	t_list	*newnode;

	i = 0;
	while (i < num_elements)
	{
		newnode = ft_lstnew((void *)(&inputs[i]));
		if (newnode == NULL)
		{
			ft_lstclear_nfunc(lst);
			free(inputs);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(lst, newnode);
		i++;
	}
}
