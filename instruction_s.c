/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:15 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/15 15:38:16 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void    s(t_list **lst)
{
    t_list *temp;

    if (ft_lstsize(*lst) == 1)
        return ;
    
    temp = (*lst)->next;
    (*lst)->next = (*lst)->next->next;
    temp->next = *lst;
    *lst = temp;
}

void    sa(t_list **lsta, t_list **lstb)
{
    (void)lstb;
    s(lsta);
    ft_printf("sa\n");
}

void    sb(t_list **lsta, t_list **lstb)
{
    (void)lsta;
    s(lstb);
    ft_printf("sb\n");
}

void    ss(t_list **lsta, t_list **lstb)
{
    s(lsta);
    s(lstb);
    ft_printf("ss\n");
}