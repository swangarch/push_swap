/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:41 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 19:20:39 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	ra(t_list **lsta, t_list **lstb)
{
	(void)lstb;
	r(lsta);
	ft_printf("ra\n");
}

void	rb(t_list **lsta, t_list **lstb)
{
	(void)lsta;
	r(lstb);
	ft_printf("rb\n");
}

void	rr(t_list **lsta, t_list **lstb)
{
	r(lsta);
	r(lstb);
	ft_printf("rr\n");
}
