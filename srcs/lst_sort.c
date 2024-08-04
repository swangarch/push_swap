/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:44:25 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/15 15:44:26 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_start_atob(t_list **lsta, t_list **lstb)
{
    if (ft_lstsize(*lsta) == 4)
    {
        pb(lsta, lstb);
    }
    else if (lst_value(lsta) > lst_value(&((*lsta)->next)))
    {
        sa(lsta, lstb);
        pb(lsta, lstb);
        pb(lsta, lstb);
    }
    else
    {
        pb(lsta, lstb);
        pb(lsta, lstb);
    }
}

void    rotate_back(t_list **lsta, t_list **lstb)
{
    int    i = 0;
        int min_index;
        int	size = ft_lstsize(*lsta);

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

void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size;
    int i;

    size = ft_lstsize(*lsta);
	if (size <= 3)
		lst_sort_small(lsta, lstb);
	else
	{
        push_start_atob(lsta, lstb);
        i = 0;
        while (i < size - 2)
        {
            if (ft_lstsize(*lsta) <= 3)
                break;
            push_low_cost_atob(lsta, lstb);
            i++;
        }
        lst_sort_small(lsta, lstb);
        i = 0;
        while (i < size - 3)
        {
            push_low_cost_btoa(lsta, lstb);
            i++;
        }
        rotate_back(lsta, lstb);
    }
    //print_stack(*lsta, *lstb);
    //ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
}
