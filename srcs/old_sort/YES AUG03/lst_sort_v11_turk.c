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

int     lst_value(t_list **lst)
{   
    if (lst)
        return (*((int *)((*lst)->content)));
    else
    {
        ft_putstr_fd("Error\nTry to get value of a int from NULL struct", 2);
        exit(EXIT_FAILURE);
    }
}

int     lst_index_value(t_list *lst, int index)
{
    int i = 0;
    t_list  *curr;

    curr = lst;
    if (!lst)
    {
        ft_putstr_fd("Error\nlst not exist\n", 2);
        exit(EXIT_FAILURE);
    }
    if (index > ft_lstsize(lst))
    {
        ft_putstr_fd("Error\nindex out of range\n", 2);
        exit(EXIT_FAILURE);
    }
    while (i < index)
    {
        curr = curr->next;
        i++;
    }
    return (lst_value(&curr));
}

int     target_index(t_list **lsta, t_list **lstb, int indexa)
{
    int i;
    int target_index = 0;
    long smallest_diff;
    long curr_diff;
    int max_value;
    int max_index;
    int find_target = 0;

    smallest_diff = (long)INT_MAX * 2 + 1;
    i = 0;

    if (ft_lstsize(*lstb) == 0)
    {
        ft_putstr_fd("Error\nvoid lstb\n", 2);
        exit(EXIT_FAILURE);
    }
    max_value = lst_index_value(*lstb, i);
    max_index = 0;
    while (i < ft_lstsize(*lstb))
    {
        if (lst_index_value(*lstb, i) > max_value)
        {
            max_value = lst_index_value(*lstb, i);
            max_index = i;
        }
        curr_diff = lst_index_value(*lsta, indexa) - lst_index_value(*lstb, i);
        if (curr_diff < 0)
        {
            i++;
            continue;
        }
        else if (curr_diff < smallest_diff)
        {
            smallest_diff = curr_diff;
            target_index = i;
            find_target = 1;
        }
        i++;
    }
    if (find_target == 0)
        return (max_index);
    else
        return ((int)target_index);
}

int    step_move_top(t_list *lst, int index)
{
    int size = ft_lstsize(lst);

    if (index > (size - index))
        return (index - size);
    else
        return (index);
}

int     ft_abs(int num)
{
    if (num < 0)
        return (-num);
    else
        return (num);
}

int     total_cost(t_list **lsta, t_list **lstb, int indexa)
{
    int stepa;
    int stepb;

    stepa = step_move_top(*lsta, indexa);
    stepb = step_move_top(*lstb, target_index(lsta, lstb, indexa));

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

int     min_cost_index(t_list **lsta, t_list **lstb)
{
    int i;
    long curr_min = (long)INT_MAX;
    int cost;
    int min_index = 0;
    int size = ft_lstsize(*lsta);

    i = 0;
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

void    push_index(t_list **lsta, t_list **lstb)
{
    int stepa;
    int stepb;
    int indexa_topush = 0;

    indexa_topush = min_cost_index(lsta, lstb);
    stepa = step_move_top(*lsta, indexa_topush);
    stepb = step_move_top(*lstb, target_index(lsta, lstb, indexa_topush));

    /////
    while (stepa > 0 && stepb > 0)
    {
        rr(lsta, lstb);
        stepa--;
        stepb--;
    }
    while (stepa < 0 && stepb < 0)
    {
        rrr(lsta, lstb);
        stepa++;
        stepb++;
    }///////

    while (stepa > 0)
    {
        ra(lsta, lstb);
        stepa--;
    }
    while (stepa < 0)
    {
        rra(lsta, lstb);
        stepa++;
    }
    while (stepb > 0)
    {
        rb(lsta, lstb);
        stepb--;
    }
    while (stepb < 0)
    {
        rrb(lsta, lstb);
        stepb++;
    }
    pb(lsta, lstb);
}


void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);

	if (size <= 3)
		return ;
	else
	{

        if (lst_value(lsta) > lst_value(&((*lsta)->next)))
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

        int count = 0;
        while (count < size - 2)
        {
            push_index(lsta, lstb);
            count++;
        }

        int j = 0;
        while (j < size)
        {
            pa(lsta, lstb);
            j++;
        }
        print_stack(*lsta, *lstb);
    }    
    ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
}

/*
void	lst_sort(t_list **lsta, t_list **lstb)
{
    print_stack(*lsta, *lstb);
    
    int i = 0;
    while (i < 2)
    {
        pb(lsta, lstb);
        i++;
    }
    print_stack(*lsta, *lstb);
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 0)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 1)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 2)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 3)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 5)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 6)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 7)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 8)));
    ft_printf("%d\n", lst_index_value(*lstb, target_index(lsta, lstb, 9)));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 0));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 1));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 2));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 3));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 4));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 5));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 6));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 7));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 8));
    ft_printf("step to move top %d\n", step_move_top(*lsta, 9));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 0));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 1));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 2));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 3));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 4));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 5));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 6));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 7));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 8));
    ft_printf("Total cost %d\n", total_cost(lsta, lstb, 9));

    push_index(lsta, lstb);
    push_index(lsta, lstb);
    push_index(lsta, lstb);

    print_stack(*lsta, *lstb);
}*/
