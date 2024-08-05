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

int     in_range(int start, int end, t_list **lst)
{
    if (lst_value(lst) >= start && lst_value(lst) < end)
        return (1);
    return (0);
}

void    lst_stream(t_list **lsta, t_list **lstb, int spliter_x1, int spliter_x2, int spliter_y1, int spliter_y2, int rest)
{
    int num_left_ina;

    num_left_ina = ft_lstsize(*lsta);
    while (num_left_ina > rest)
    {
        if (in_range(spliter_x1, spliter_x2, lsta))
        {
            pb(lsta, lstb);
            if (!in_range(spliter_x1, spliter_x2, lsta) && !in_range(spliter_y1, spliter_y2, lsta))
                rr(lsta, lstb);
            else
                rb(lsta, lstb);
        }
        else if (in_range(spliter_y1, spliter_y2, lsta))
            pb(lsta, lstb);
        else
            ra(lsta, lstb);
        num_left_ina--;
    }
}

void	lst_sort(t_list **lsta, t_list **lstb, t_spliter *spl)
{
	int	size;
    int i;

    int spliter_0 = spl->spliter_0;
    int spliter_1 = spl->spliter_1;
    int spliter_2 = spl->spliter_2;
    int spliter_3 = spl->spliter_3;
    int spliter_4 = spl->spliter_4;

    size = ft_lstsize(*lsta);
	if (size <= 3)
		lst_sort_small(lsta, lstb);   /////如果过太小没必要推过去就不推
	else
	{
        i = 0;
        if (size < 1001)
        { 
            while (size - i > 3)
            {
                 pb(lsta, lstb);
                 i++;
            }
        }
        else
        {
            lst_stream(lsta, lstb, spliter_1, spliter_2, spliter_2, spliter_3, 0);
            lst_stream(lsta, lstb, spliter_0, spliter_1, spliter_3, spliter_4, 2);
        }
        lst_sort_small(lsta, lstb);
        i = 0;
        while (ft_lstsize(*lstb) > 0)
        {
            push_low_cost_btoa(lsta, lstb);
            i++;
        }
        rotate_back(lsta, lstb);
    }
    //print_stack(*lsta, *lstb);
    //ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
}
