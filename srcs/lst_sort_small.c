/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:00:07 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/03 19:00:08 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     lst_index_cmp(t_list *lst, int indexa, int indexb)
{
    int	size = ft_lstsize(lst);

    if (size > 3)
    {
        ft_putstr_fd("Error\nThis function is not for more than 3 elements\n", 2);
        exit(EXIT_FAILURE);
    }

    if (lst_index_value(lst, indexa) > lst_index_value(lst, indexb))
        return (1);
    else
        return (0);
}

void	lst_sort_small(t_list **lsta, t_list **lstb)
{
    int	size = ft_lstsize(*lsta);

	if (size < 2)
		;
	else if (size == 2)
	{
		if (lst_index_cmp(*lsta, 0, 1))
		{
			sa(lsta, lstb);
		}
		else
		{
			;
		}
	}
	else if (size == 3)
	{
		if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 0)///0 1 2
		{
			;
		}
		else if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 1 && lst_index_cmp(*lsta, 2, 0) == 1)/// 0 2 1
		{
			sa(lsta, lstb);
            ra(lsta, lstb);
		}
		else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 0 && lst_index_cmp(*lsta, 2, 0) == 1)/// 1 0 2
		{
			sa(lsta, lstb);
		}
		else if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 1 && lst_index_cmp(*lsta, 2, 0) == 0)///1 2 0
		{
			rra(lsta, lstb);
		}
		else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 0 && lst_index_cmp(*lsta, 2, 0) == 0)///2 0 1
		{
			ra(lsta, lstb);
		}
		else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 1)///2 1 0
		{
			sa(lsta, lstb);
            rra(lsta, lstb);
		}
		else
		{
			ft_putstr_fd("error\n", 1);
			exit(0);
		}
	}
}
