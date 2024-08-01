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

int     lst_find_index(t_list *lst, int index)
{
    int count = 0;
    t_list *curr = lst;

    if (index > ft_lstsize(lst))
    {
        ft_putstr_fd("Error1\n", 2);
        exit(EXIT_FAILURE);
    }

    while(count < index)
    {
        curr = curr->next;
        count++;
    }
    return (lst_value(&curr));
}

int     lst_middle_value(t_list *lst)
{
    int size = ft_lstsize(lst);
    int average;

    if (size % 2 == 0)
    {
        return(lst_find_index(lst, (ft_lstsize(lst) / 2)));
    }

    average = (lst_find_index(lst, (ft_lstsize(lst) / 2)) + lst_find_index(lst, (ft_lstsize(lst) / 2) + 1)) / 2;
    return (average);
}

void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);
    
	int	i = 0;
    int count = 0;
	
	//ft_printf("list a size is %d\n", size);
	if (size < 2)
		return ;
	else
	{
        /*initialize——————————————————————————————————————————————————————*/
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
       
        /*initialize——————————————————————————————————————————————————————*/
        if (lst_value(lsta) < lst_value(lstb))
            pb(lsta, lstb);
        else if (lst_value(lsta) > lst_value(lstb) && lst_value(lsta) > lst_value(&((*lstb)->next)))
        {
            pb(lsta, lstb);
            rb(lsta, lstb);
        }
        else if (lst_value(lsta) > lst_value(lstb) && lst_value(lsta) < lst_value(&((*lstb)->next)))
        {
            rb(lsta, lstb);
            pb(lsta, lstb);
        }
        
        ft_printf("first done\n");

        /*initialize——————third————————————————————————————————————————————————*/
        
        while (i < size - 3)
        {
            ft_printf("half is %d\n", lst_middle_value(*lstb));
            if (lst_value(lsta) > lst_middle_value(*lstb))
            {
                ft_printf("case 1\n");
                
                count = 0;
                while (lst_value(lsta) < lst_value(lstb) && count < (ft_lstsize(*lstb) / 2))
                {
                    rb(lsta, lstb);
                    count++;
                }
                pb(lsta, lstb);
                while (count > 0)
                {
                    rrb(lsta, lstb);
                    count--;
                }
            }
            if (lst_value(lsta) < lst_middle_value(*lstb))
            {
                ft_printf("case 2\n");
                
                count = 0;
                rrb(lsta, lstb);
                while (lst_value(lsta) > lst_value(lstb) && count < (ft_lstsize(*lstb) / 2))
                {
                    rrb(lsta, lstb);
                    count++;
                }
                rb(lsta, lstb);
                pb(lsta, lstb);
                while (count > 0)
                {
                    rb(lsta, lstb);
                    count--;
                }
                if (ft_lstsize(*lstb) % 2 == 1)
                {
                    rb(lsta, lstb);
                    rb(lsta, lstb);
                }
                else
                {
                    rb(lsta, lstb);
                }
            }
            i++;
        }
        ft_printf("test\n");
        int j = 0;
        while (j < size)
        {
            pa(lsta, lstb);
            j++;
        }
        print_stack(*lsta, *lstb);
    }    
    ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
	//ft_printf("________stack a size is %d\n", ft_lstsize(*lsta));
}
