/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rv_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:51 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/06 12:48:53 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rv(t_list **lst)
{
	t_list	*last;
	t_list	*beforelast;
	t_list	*curr;

	if (ft_lstsize(*lst) <= 1)
		return ;
	curr = *lst;
	while (curr->next->next != NULL)
		curr = curr->next;
	beforelast = curr;
	last = curr->next;
	beforelast->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra_bonus(t_list **lsta, t_list **lstb)
{
	(void)lstb;
	rv(lsta);
}

void	rrb_bonus(t_list **lsta, t_list **lstb)
{
	(void)lsta;
	rv(lstb);
}

void	rrr_bonus(t_list **lsta, t_list **lstb)
{
	rv(lsta);
	rv(lstb);
}
