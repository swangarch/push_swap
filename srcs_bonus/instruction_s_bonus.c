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

#include "push_swap_bonus.h"

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

void    sa_bonus(t_list **lsta, t_list **lstb)
{
    (void)lstb;
    s(lsta);
}

void    sb_bonus(t_list **lsta, t_list **lstb)
{
    (void)lsta;
    s(lstb);
}

void    ss_bonus(t_list **lsta, t_list **lstb)
{
    s(lsta);
    s(lstb);
}