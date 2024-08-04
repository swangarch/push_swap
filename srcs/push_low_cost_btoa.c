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

int     target_index_btoa(t_list *lsta, t_list *lstb, int indexb)
{
    int i;
    int target_index = 0;
    long smallest_diff;
    int find_target = 0;
    int b_value;
    int a_size;
    t_list *curr_a;

    b_value = lst_index_value(lstb, indexb);
    a_size = ft_lstsize(lsta);
    smallest_diff = (long)INT_MAX * 2 + 1;///?????/
    i = 0;
    curr_a = lsta;
    while (i < a_size)
    {
        if (i != 0 && curr_a->next)
            curr_a = curr_a->next;
        if (lst_value(&curr_a) - b_value < smallest_diff && lst_value(&curr_a) > b_value)
        {
            smallest_diff = lst_value(&curr_a) - b_value;
            target_index = i;
            find_target = 1;
        }
        i++;
    }
    if (find_target == 0)
        return (lst_min_index(lsta));
    else
        return (target_index);
}

int     total_cost_btoa(t_list *lsta, t_list *lstb, int indexb)
{
    int stepa;
    int stepb;

    stepa = step_move_top(lsta, target_index_btoa(lsta, lstb, indexb));
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

int     min_cost_index_btoa(t_list *lsta, t_list *lstb)
{
    int i;
    int curr_min;
    int cost;
    int min_index = 0;
    int size;

    i = 0;
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

void    push_low_cost_btoa(t_list **lsta, t_list **lstb)
{
    int stepa;
    int stepb;
    int indexb_topush;

    indexb_topush = min_cost_index_btoa(*lsta, *lstb);
    stepa = step_move_top(*lsta, target_index_btoa(*lsta, *lstb, indexb_topush));
    stepb = step_move_top(*lstb, indexb_topush);
    push_move_tog(lsta, lstb, &stepa, &stepb);
    push_move_sep(lsta, lstb, &stepa, &stepb);
    pa(lsta, lstb);
}
