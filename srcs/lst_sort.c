/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:44:25 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 19:41:01 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_back(t_list **lsta, t_list **lstb)
{
	int	i;
	int	min_index;
	int	size;

	i = 0;
	size = ft_lstsize(*lsta);
	min_index = lst_min_index(*lsta);
	if (min_index > size / 2)
	{
		while (i < size - min_index)
		{
			rra(lsta, lstb);
			i++;
		}
	}
	else
	{
		while (i < min_index)
		{
			ra(lsta, lstb);
			i++;
		}
	}
}

void	lst_stream1(t_list **lsta, t_list **lstb, t_spliter *spl, int rest)
{
	int	num_left_ina;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = spl->spliter_1;
	x2 = spl->spliter_2;
	y1 = spl->spliter_2;
	y2 = spl->spliter_3;
	num_left_ina = ft_lstsize(*lsta);
	while (num_left_ina > rest)
	{
		if (in_range(x1, x2, lsta))
		{
			pb(lsta, lstb);
			if (!in_range(x1, x2, lsta) && !in_range(y1, y2, lsta))
				rr(lsta, lstb);
			else
				rb(lsta, lstb);
		}
		else if (in_range(y1, y2, lsta))
			pb(lsta, lstb);
		else
			ra(lsta, lstb);
		num_left_ina--;
	}
}

void	lst_stream2(t_list **lsta, t_list **lstb, t_spliter *spl, int rest)
{
	int	num_left_ina;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = spl->spliter_0;
	x2 = spl->spliter_1;
	y1 = spl->spliter_3;
	y2 = spl->spliter_4;
	num_left_ina = ft_lstsize(*lsta);
	while (num_left_ina > rest)
	{
		if (in_range(x1, x2, lsta))
		{
			pb(lsta, lstb);
			if (!in_range(x1, x2, lsta) && !in_range(y1, y2, lsta))
				rr(lsta, lstb);
			else
				rb(lsta, lstb);
		}
		else if (in_range(y1, y2, lsta))
			pb(lsta, lstb);
		else
			ra(lsta, lstb);
		num_left_ina--;
	}
}

void	push_start_atob(t_list **lsta, t_list **lstb, t_spliter *spl, int size)
{
	int	i;

	i = 0;
	if (size < 100)
	{
		while (size - i > 3)
		{
			pb(lsta, lstb);
			i++;
		}
	}
	else
	{
		lst_stream1(lsta, lstb, spl, 0);
		lst_stream2(lsta, lstb, spl, 2);
	}
}

void	lst_sort(t_list **lsta, t_list **lstb, t_spliter *spl)
{
	int	size;
	int	i;

	if (lst_sorted(*lsta))
		return ;
	size = ft_lstsize(*lsta);
	if (size <= 3)
		lst_sort_small(lsta, lstb);
	else
	{
		push_start_atob(lsta, lstb, spl, size);
		lst_sort_small(lsta, lstb);
		i = 0;
		while (ft_lstsize(*lstb) > 0)
		{
			push_low_cost_btoa(lsta, lstb);
			i++;
		}
		rotate_back(lsta, lstb);
	}
}
