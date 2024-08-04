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

int     lst_min_index(t_list *lst)
{
    int i;
    int min;
    int min_index;
    t_list *curr;

    min = INT_MAX;
    min_index = 0;
    curr = lst;
    i = 0;
    while (curr)
    {
        if (lst_value(&curr) < min)
        {
            min = lst_value(&curr);
            min_index = i;
        }
        curr = curr->next;
        i++;
    }
    return (min_index);
}

int     target_index_btoa(t_list *lsta, t_list *lstb, int indexb)
{
    int i;
    int target_index = 0;
    long smallest_diff;
    long curr_diff;
    int find_target = 0;
    int b_value;
    int a_size;
    int curr_a_value;
    t_list *curr_nodea;

    b_value = lst_index_value(lstb, indexb);
    a_size = ft_lstsize(lsta);
    smallest_diff = (long)INT_MAX * 2 + 1;///?????/
    //if (a_size == 0)  /////can be removed
    //{
    //    ft_putstr_fd("Error\nvoid lsta\n", 2);
    //    exit(EXIT_FAILURE);
    //}
    i = 0;
    curr_nodea = lsta;
    while (i < a_size)
    {
        if (i != 0 && curr_nodea->next)
            curr_nodea = curr_nodea->next;
        curr_a_value = lst_value(&curr_nodea);
        curr_diff = curr_a_value - b_value;
        if (curr_diff < smallest_diff && curr_diff > 0)
        {
            smallest_diff = curr_diff;
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

static void    push_move_tog(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
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

static void    push_move_sep(t_list **lsta, t_list **lstb, int *stepa, int *stepb)
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
