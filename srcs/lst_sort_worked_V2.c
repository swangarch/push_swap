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



void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);
    
	int	i = 0;
    int count = 0;
    int average = 50; //中位数
	
	//ft_printf("list a size is %d\n", size);
	if (size < 2)
		return ;
	else
	{
        /*
        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.2)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.4)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }
        
        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.6)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.8)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 1)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 1.2)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }*/

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.3)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.6)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 0.9)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 1.2)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 1.5)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        i = 0;
        while (i < size)
        {
            if (lst_value(lsta) > average * 1.8)
                ra(lsta, lstb);
            else
            {
                pb(lsta, lstb);
                count++;
            }
            i++;
        }

        while (count > 0)
        {
            pa(lsta, lstb);
            count--;
        }
        
        
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

        /*push a to b——————————————————————————————————————————————————————*/
        i = 0;
        while (i < size - 2)
        {
            if (lst_value(lsta) < average)
            {
                count = 0;
                while (lst_value(lsta) < lst_value(lstb) && count < ft_lstsize(*lstb))
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
            else if (lst_value(lsta) >= average)
            {
                count = 0;
                while (lst_value(lsta) < lst_value(lstb) && count < ft_lstsize(*lstb))
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
            i++;
        }
        /*push a to b——————————————————————————————————————————————————————*/

        /*push b to a——————————————————————————————————————————————————————*/
        int j = 0;
        while (j < size)
        {
            pa(lsta, lstb);
            j++;
        }
        /*push b to a——————————————————————————————————————————————————————*/
        print_stack(*lsta, *lstb);
    }    
    ft_printf("________stack sorted: %s\n", ((lst_sorted(*lsta) && size == ft_lstsize(*lsta)) ? "Yes" : "No"));
	//ft_printf("________stack a size is %d\n", ft_lstsize(*lsta));
}
