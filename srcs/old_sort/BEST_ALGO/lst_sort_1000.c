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



void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size;
    int i;

    int num_left_ina;
    /*
    int spliter_1 = 25;
    int spliter_2 = 50;
    int spliter_3 = 75;
    int spliter_4 = 100;*/
    /*
        int spliter_1 = 125;
        int spliter_2 = 250;
        int spliter_3 = 375;
        int spliter_4 = 500;*/

        int spliter_1 = 250;
        int spliter_2 = 500;
        int spliter_3 = 750;
        int spliter_4 = 1000;

    size = ft_lstsize(*lsta);
	if (size <= 3)
		lst_sort_small(lsta, lstb);
	else
	{
        num_left_ina = ft_lstsize(*lsta);
        while (num_left_ina > 0)
        {
            if (in_range(spliter_1, spliter_2, lsta))
            {
                pb(lsta, lstb);
                if (!in_range(spliter_1, spliter_2, lsta) && !in_range(spliter_2, spliter_3, lsta))
                    rr(lsta, lstb);
                else
                    rb(lsta, lstb);
            }
            else if (in_range(spliter_2, spliter_3, lsta))
            {
                pb(lsta, lstb);
            }
            else
                ra(lsta, lstb);
            num_left_ina--;
        }
        num_left_ina = ft_lstsize(*lsta);
        while (num_left_ina > 2)
        {
            if (in_range(0, spliter_1, lsta))
            {
                pb(lsta, lstb);
                
                if (!in_range(0, spliter_1, lsta) && !(in_range(spliter_3, spliter_4, lsta)))
                    rr(lsta, lstb);
                else
                    rb(lsta, lstb);
            }
            else if (in_range(spliter_3, spliter_4, lsta))
            {
                pb(lsta, lstb);
            }
            else
                ra(lsta, lstb);
            num_left_ina--;
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
