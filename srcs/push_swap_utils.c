/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:55:16 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:55:26 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_sorted(t_list *lst)
{
	t_list *currnode;
	
	currnode = lst;
	if (ft_lstsize(lst) <= 1)
        return (1);
	while (currnode->next)
    {
        if (*((int *)(currnode->content)) > *((int *)(currnode->next->content)))
            return (0);
        currnode = currnode->next;
    }
    return (1);
}

void	print_stack(t_list *lsta, t_list *lstb)
{
	ft_printf("stack a: ");
	lst_print(lsta);
	ft_printf("stack b: ");
	lst_print(lstb);
}