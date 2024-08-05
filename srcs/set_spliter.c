/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spliter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:49:08 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 14:49:10 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*inputs_dup(int *inputs, int num)
{
	int	i;
	int *inputs_copy;

	i = 0;
	inputs_copy = malloc(sizeof(int) * num);
	if (inputs_copy == NULL)
	{
		free(inputs);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (i < num)
	{
		inputs_copy[i] = inputs[i];
		i++;
	}
	return (inputs_copy);
}

void	ft_b_sort(int *inputs, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (inputs[i] < inputs[j] && i != j)
				ft_swap(&inputs[i], &inputs[j]);
			j++;
		}
		i++;
	}
}

void	set_spliter(t_spliter *spl, int *inputs, int num)
{
	spl->spliter_0 = inputs[0];
	spl->spliter_1 = inputs[num / 4];
	spl->spliter_2 = inputs[num / 4 * 2];
	spl->spliter_3 = inputs[num / 4 * 3];
	spl->spliter_4 = inputs[num -1];
	free(inputs);
}	

