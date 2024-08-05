/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:53:14 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:14:04 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	step_move_top(t_list *lst, int index)
{
	int	size;

	size = ft_lstsize(lst);
	if (index > (size - index))
		return (index - size);
	else
		return (index);
}

void	push_move_tog(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
{
	while ((*stepa) > 0 && (*stepb) > 0)
	{
		rr(lsta, lstb);
		(*stepa)--;
		(*stepb)--;
	}
	while ((*stepa) < 0 && (*stepb) < 0)
	{
		rrr(lsta, lstb);
		(*stepa)++;
		(*stepb)++;
	}
}

void	push_move_sep(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
{
	while ((*stepa) > 0)
	{
		ra(lsta, lstb);
		(*stepa)--;
	}
	while ((*stepa) < 0)
	{
		rra(lsta, lstb);
		(*stepa)++;
	}
	while ((*stepb) > 0)
	{
		rb(lsta, lstb);
		(*stepb)--;
	}
	while ((*stepb) < 0)
	{
		rrb(lsta, lstb);
		(*stepb)++;
	}
}
