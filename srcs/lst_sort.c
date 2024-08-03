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

int     target_index(t_list *lsta, t_list *lstb, int indexa)
{
    int i;
    int target_index = 0;
    long smallest_diff;
    long curr_diff;
    int max_value;
    int max_index;
    int find_target = 0;
    int a_value;
    int b_size;
    int curr_b_value;

    a_value = lst_index_value(lsta, indexa);
    b_size = ft_lstsize(lstb);
    smallest_diff = (long)INT_MAX * 2 + 1;
    
    if (b_size == 0)
    {
        ft_putstr_fd("Error\nvoid lstb\n", 2);
        exit(EXIT_FAILURE);
    }
    max_value = lst_index_value(lstb, 0);
    max_index = 0;

    i = 0;
    t_list *curr_nodeb;
    curr_nodeb = lstb;

    while (i < b_size)
    {
        if (i != 0 && curr_nodeb->next)
            curr_nodeb = curr_nodeb->next;
        curr_b_value = lst_value(&curr_nodeb);
        if (curr_b_value > max_value)
        {
            max_value = curr_b_value;
            max_index = i;
        }
        curr_diff = a_value - curr_b_value;
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
        return (target_index);
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

int     find_max(t_list *lst)
{
    int i;
    int max_value;
    int curr_value;
    int max_index;
    int size = ft_lstsize(lst);
    t_list *curr_node;

    i = 0;
    if (size == 0)
    {
        ft_putstr_fd("Error\nvoid lst\n", 2);
        exit(EXIT_FAILURE);
    }
    curr_node = lst;
    max_value = lst_value(&curr_node);
    max_index = 0;
    while (i < size)
    {
        if (curr_node->next)
        {
            curr_node = curr_node->next;
            curr_value = lst_value(&curr_node);
        }
        if (curr_value > max_value)
        {
            max_value = curr_value;
            max_index = i;
        }
        i++;
    }
    return (max_index);
}

void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);

	if (size <= 3)
		lst_sort_small(lsta, lstb);
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
        ///////////////////////push a to b
        int count = 0;
        while (count < size - 2)
        {
            push_low_cost(lsta, lstb);
            count++;
        }
        ///////////////////////push back b to a
        int j = 0;
        int max_index = find_max(*lstb);
        while (j < size)
        {
            pa(lsta, lstb);
            j++;
        }
        j = 0;
        if (max_index < size / 2)
        {
            while (j < max_index)
            {
                rra(lsta, lstb);
                j++;
            }
        }
        else
        {
            while (j < size - max_index)
            {
                ra(lsta, lstb);
                j++;
            }
        }
        rra(lsta, lstb);
        //ft_printf("max index is %d\n", max_index);
    }
    //print_stack(*lsta, *lstb);
    //ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
}
