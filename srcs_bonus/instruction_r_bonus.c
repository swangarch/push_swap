/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:41 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/06 12:46:51 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	r(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	ra_bonus(t_list **lsta, t_list **lstb)
{
	(void)lstb;
	r(lsta);
}

void	rb_bonus(t_list **lsta, t_list **lstb)
{
	(void)lsta;
	r(lstb);
}

void	rr_bonus(t_list **lsta, t_list **lstb)
{
	r(lsta);
	r(lstb);
}
