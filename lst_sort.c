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
#include "libft/libft.h"

void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);
	int	i = 0;
	
	ft_printf("list a size is %d\n", size);

	if (size < 2)
		return ;

	else
	{
        /*
		while (i < size / 2)先随机等分成两组
		{
            pb(lsta, lstb);
            print_stack(*lsta, *lstb);
			i++;
		}
        */
        i = 0;
		
        while (i < ft_lstsize(*lsta) * ft_lstsize(*lsta) * ft_lstsize(*lsta))
        {
            if (*((int *)((*lsta)->content)) > *((int *)((*lsta)->next->content)))
	        {
                sa(lsta, lstb);
		        rra(lsta, lstb);
            }
            else
	        {
		        rra(lsta, lstb);
            }
            print_stack(*lsta, *lstb);
            if (lst_sorted(*lsta))
            {
                ft_printf("Sorted\n");
                print_stack(*lsta, *lstb);
                return;
            }
            i++;
        }
		/*
		while (i < ft_lstsize(*lsta) * ft_lstsize(*lsta))
        {
            if (*((int *)((*lsta)->content)) > *((int *)((*lstb)->content)))
	        {
                pa(lsta, lstb);
		        ra(lsta, lstb);
            }
            else
	        {
				pb(lsta, lstb);
		        ra(lsta, lstb);
            }
            print_stack(*lsta, *lstb);
            if (lst_sorted(*lsta))
            {
                ft_printf("Sorted\n");
                print_stack(*lsta, *lstb);
                return;
            }
            i++;
        }*/
    }    
    ft_printf("\nstack sorted: %s\n", (lst_sorted(*lsta) ? "Yes" : "No"));
	ft_printf("stack a size is %d\n", ft_lstsize(*lsta));
}

