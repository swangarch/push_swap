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

int     lst_max_index(t_list *lst)
{
    int i;
    int max;
    int max_index;
    t_list *curr;

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

int     target_index_atob(t_list *lsta, t_list *lstb, int indexa)
{
    int i;
    int target_index = 0;
    long smallest_diff;
    long curr_diff;
    int find_target = 0;
    int a_value;
    int b_size;
    int curr_b_value;
    t_list *curr_nodeb;

    a_value = lst_index_value(lsta, indexa);
    b_size = ft_lstsize(lstb);
    smallest_diff = (long)INT_MAX * 2 + 1;
    if (b_size == 0)  /////can be removed
    {
        ft_putstr_fd("Error\nvoid lstb\n", 2);
        exit(EXIT_FAILURE);
    }
    i = 0;
    curr_nodeb = lstb;
    while (i < b_size)
    {
        if (i != 0 && curr_nodeb->next)
            curr_nodeb = curr_nodeb->next;
        curr_b_value = lst_value(&curr_nodeb);
        curr_diff = a_value - curr_b_value;
        if (curr_diff < smallest_diff && curr_diff >= 0)
        {
            smallest_diff = curr_diff;
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

int     total_cost(t_list *lsta, t_list *lstb, int indexa)
{
    int stepa;
    int stepb;

    stepa = step_move_top(lsta, indexa);
    stepb = step_move_top(lstb, target_index_atob(lsta, lstb, indexa));
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

int     min_cost_index(t_list *lsta, t_list *lstb)
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
        cost = total_cost(lsta, lstb, i);
        if (cost < curr_min)
        {
            min_index = i;
            curr_min = cost;
        }
        i++;
    }
    return (min_index);
}

void    push_move_tog(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
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

void    push_move_sep(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
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

void    push_low_cost_atob(t_list **lsta, t_list **lstb)
{
    int stepa;
    int stepb;
    int indexa_topush;

    indexa_topush = min_cost_index(*lsta, *lstb);
    stepa = step_move_top(*lsta, indexa_topush);
    stepb = step_move_top(*lstb, target_index_atob(*lsta, *lstb, indexa_topush));
    push_move_tog(lsta, lstb, &stepa, &stepb);
    push_move_sep(lsta, lstb, &stepa, &stepb);
    pb(lsta, lstb);
}
