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

void    lst_stream(t_list **lsta, t_list **lstb, int factor)
{
    int size = ft_lstsize(*lsta);
    int average = 50; //中位数

    while (size > 0)
    {
        if (lst_value(lsta) < (average * factor / 100))
        {
            pb(lsta, lstb);
        }
        else
            ra(lsta, lstb);
        size--;
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
	int	size_total = ft_lstsize(*lsta);
	int	i = 0;
    int count = 0;
	
	if (size_total <= 3)
    {
        write(2, "Error\n", 6);
		return ;
    }
	else
	{
        int size;

        int spliter_1 = 25;
        int spliter_2 = 50;
        int spliter_3 = 75;
        /*
        int spliter_1 = 125;
        int spliter_2 = 250;
        int spliter_3 = 375;*/

        size = ft_lstsize(*lsta);
        while (size > 0)
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
            size--;
        }
        size = ft_lstsize(*lsta);
        while (size > 0)
        {
            if (in_range(0, spliter_1, lsta))
            {
                pb(lsta, lstb);
                
                if (!in_range(0, spliter_1, lsta) && !(in_range(spliter_3, 100, lsta)))
                    rr(lsta, lstb);
                else
                    rb(lsta, lstb);
            }
            else if (in_range(spliter_3, 100, lsta))
            {
                pb(lsta, lstb);
            }
            else
                ra(lsta, lstb);
            size--;
        }
        
        /*initialize——————————————————————————————————————————————————————*/
        if (lst_value(lstb) < lst_value(&((*lstb)->next)))
        {
            sb(lsta, lstb);
            pa(lsta, lstb);
            pa(lsta, lstb);
        }
        else
        {
            pa(lsta, lstb);
            pa(lsta, lstb);
        }
        /*initialize——————————————————————————————————————————————————————*/

        /*push b to a——————————————————————————————————————————————————————*/
        i = 0;
        while (i < size_total - 2)
        {
                count = 0;
                while (lst_value(lsta) < lst_value(lstb) && count < ft_lstsize(*lsta))
                {
                    ra(lsta, lstb);
                    count++;
                }
                pa(lsta, lstb);
                while (count > 0)
                {
                    rra(lsta, lstb);
                    count--;
                }
            i++;
        }
        /*push a to b——————————————————————————————————————————————————————*/

        /*push b to a——————————————————————————————————————————————————————*/
        print_stack(*lsta, *lstb);
    }    
    ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size_total == ft_lstsize(*lsta)) ? "Yes" : "No"));
	//ft_printf("________stack a size is %d\n", ft_lstsize(*lsta));
}
