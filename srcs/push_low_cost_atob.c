/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_low_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:05:26 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/03 20:05:28 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     target_index_atob(t_list *lsta, t_list *lstb, int indexa, int i)
{

    int target_index;
    long smallest_diff;
    int find_target = 0;
    int a_value;
    int b_size;
    t_list  *curr_b;


    a_value = lst_index_value(lsta, indexa);
    b_size = ft_lstsize(lstb);
    smallest_diff = (long)INT_MAX * 2 + 1;
    curr_b = lstb;
    while (i < b_size)
    {
        if (i != 0 && lstb->next)
            curr_b = curr_b->next;
        if (a_value - lst_value(&curr_b) < smallest_diff && a_value >= lst_value(&curr_b))
        {
            smallest_diff = a_value - lst_value(&curr_b);
            target_index = i;
            find_target = 1;
        }
        i++;
    }
    if (find_target == 0)
        return (lst_max_index(lstb));
    else
        return (target_index);
}

int     total_cost_atob(t_list *lsta, t_list *lstb, int indexa)
{
    int stepa;
    int stepb;

    stepa = step_move_top(lsta, indexa);
    stepb = step_move_top(lstb, target_index_atob(lsta, lstb, indexa, 0));
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

int     min_cost_index_atob(t_list *lsta, t_list *lstb)
{
    int i;
    int curr_min;
    int cost;
    int min_index = 0;
    int size;

    i = 0;
    size = ft_lstsize(lsta);
    curr_min = INT_MAX;
    while (i < size)
    {
        cost = total_cost_atob(lsta, lstb, i);
        if (cost < curr_min)
        {
            min_index = i;
            curr_min = cost;
        }
        i++;
    }
    return (min_index);
}

void    push_low_cost_atob(t_list **lsta, t_list **lstb)
{
    int stepa;
    int stepb;
    int indexa_topush;

    indexa_topush = min_cost_index_atob(*lsta, *lstb);
    stepa = step_move_top(*lsta, indexa_topush);
    stepb = step_move_top(*lstb, target_index_atob(*lsta, *lstb, indexa_topush, 0));
    push_move_tog(lsta, lstb, &stepa, &stepb);
    push_move_sep(lsta, lstb, &stepa, &stepb);
    pb(lsta, lstb);
}
