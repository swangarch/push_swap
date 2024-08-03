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

int     total_cost(t_list *lsta, t_list *lstb, int indexa)
{
    int stepa;
    int stepb;

    stepa = step_move_top(lsta, indexa);
    stepb = step_move_top(lstb, target_index(lsta, lstb, indexa));
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

void    push_low_cost(t_list **lsta, t_list **lstb)
{
    int stepa;
    int stepb;
    int indexa_topush;

    indexa_topush = min_cost_index(*lsta, *lstb);
    stepa = step_move_top(*lsta, indexa_topush);
    stepb = step_move_top(*lstb, target_index(*lsta, *lstb, indexa_topush));
    push_move_tog(lsta, lstb, &stepa, &stepb);
    push_move_sep(lsta, lstb, &stepa, &stepb);
    pb(lsta, lstb);
}
