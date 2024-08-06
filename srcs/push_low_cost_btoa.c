/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_low_cost_btoa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:05:26 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:25:12 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_target(int *target_index, int *find_target, int i)
{
	*target_index = i;
	*find_target = 1;
}

int	target_index_btoa(t_list *lsta, t_list *lstb, int indexb, int i)
{
	t_list	*curr_a;
	t_vars	vars;

	vars.target_index = 0;
	vars.find_target = 0;
	vars.b_value = lst_index_value(lstb, indexb);
	vars.smallest_diff = (long)INT_MAX * 2 + 1;
	vars.a_size = ft_lstsize(lsta);
	curr_a = lsta;
	while (i < vars.a_size)
	{
		if (i != 0 && curr_a->next)
			curr_a = curr_a->next;
		if (lst_value(&curr_a) - vars.b_value < vars.smallest_diff \
			&& lst_value(&curr_a) > vars.b_value)
		{
			vars.smallest_diff = lst_value(&curr_a) - vars.b_value;
			update_target(&vars.target_index, &vars.find_target, i);
		}
		i++;
	}
	if (vars.find_target == 0)
		return (lst_min_index(lsta));
	else
		return (vars.target_index);
}

int	total_cost_btoa(t_list *lsta, t_list *lstb, int indexb)
{
	int	stepa;
	int	stepb;

	stepa = step_move_top(lsta, target_index_btoa(lsta, lstb, indexb, 0));
	stepb = step_move_top(lstb, indexb);
	if (stepa * stepb > 0)
	{
		if (stepa > 0)
		{
			if (stepa > stepb)
				return (ft_abs(stepa));
			else
				return (ft_abs(stepb));
		}
		else
		{
			if (stepa > stepb)
				return (ft_abs(stepb));
			else
				return (ft_abs(stepa));
		}
	}
	return (ft_abs(stepa) + ft_abs(stepb));
}

int	min_cost_index_btoa(t_list *lsta, t_list *lstb)
{
	int	i;
	int	curr_min;
	int	cost;
	int	min_index;
	int	size;

	i = 0;
	min_index = 0;
	size = ft_lstsize(lstb);
	curr_min = INT_MAX;
	while (i < size)
	{
		cost = total_cost_btoa(lsta, lstb, i);
		if (cost < curr_min)
		{
			min_index = i;
			curr_min = cost;
		}
		i++;
	}
	return (min_index);
}

void	push_low_cost_btoa(t_list **lsta, t_list **lstb)
{
	int	stepa;
	int	stepb;
	int	indexb_topush;

	indexb_topush = min_cost_index_btoa(*lsta, *lstb);
	stepa = step_move_top(*lsta, target_index_btoa \
			(*lsta, *lstb, indexb_topush, 0));
	stepb = step_move_top(*lstb, indexb_topush);
	push_move_tog(lsta, lstb, &stepa, &stepb);
	push_move_sep(lsta, lstb, &stepa, &stepb);
	pa(lsta, lstb);
}
