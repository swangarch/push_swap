/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:42:18 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:05:52 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_value(t_list **lst)
{
	if (lst)
		return (*((int *)((*lst)->content)));
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	lst_index_value(t_list *lst, int index)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	if (!lst)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (index > ft_lstsize(lst))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	return (lst_value(&curr));
}

int	lst_max_index(t_list *lst)
{
	int		i;
	int		max;
	int		max_index;
	t_list	*curr;

	max = INT_MIN;
	max_index = 0;
	curr = lst;
	i = 0;
	while (curr)
	{
		if (lst_value(&curr) > max)
		{
			max = lst_value(&curr);
			max_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_index);
}

int	lst_min_index(t_list *lst)
{
	int		i;
	int		min;
	int		min_index;
	t_list	*curr;

	min = INT_MAX;
	min_index = 0;
	curr = lst;
	i = 0;
	while (curr)
	{
		if (lst_value(&curr) < min)
		{
			min = lst_value(&curr);
			min_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}

int	lst_sorted(t_list *lst)
{
	t_list	*currnode;

	currnode = lst;
	if (ft_lstsize(lst) <= 1)
		return (1);
	while (currnode->next)
	{
		if (*((int *)(currnode->content)) > *((int *)(currnode->next->content)))
			return (0);
		currnode = currnode->next;
	}
	return (1);
}
