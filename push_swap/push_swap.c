/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:55:16 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:55:26 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*current;

	c = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		c++;
	}
	return (c);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void    s(t_list **lst)
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
    s(lsta);
    ft_printf("sa\n");
}

void    sb(t_list **lsta, t_list **lstb)
{
    s(lstb);
    ft_printf("sb\n");
}

void    ss(t_list **lsta, t_list **lstb)
{
    s(lsta);
    s(lstb);
    ft_printf("ss\n");
}

void    p(t_list **lst1, t_list **lst2)
{
    t_list  *temp;

    if (ft_lstsize(*lst1) == 0)
    {
        return ;
    }
    temp = *lst1;
    *lst1 = (*lst1)->next;
    ft_lstadd_front(lst2, temp);
}

void    pa(t_list **lsta, t_list **lstb)
{
    p(lstb, lsta);
    ft_printf("pa\n");
}

void    pb(t_list **lsta, t_list **lstb)
{
    p(lsta, lstb);
    ft_printf("pb\n");
}

void    r(t_list **lst)
{
    t_list *temp;

    temp = *lst;
    *lst = (*lst)->next;
    temp->next = NULL;
    ft_lstadd_back(lst, temp);
}

void    ra(t_list **lsta, t_list **lstb)
{
    r(lsta);
    ft_printf("ra\n");
}

void    rb(t_list **lsta, t_list **lstb)
{
    r(lstb);
    ft_printf("rb\n");
}

void    rr(t_list **lsta, t_list **lstb)
{
    r(lsta);
    r(lstb);
    ft_printf("rr\n");
}

void    rv(t_list **lst)
{
    t_list  *last;
    t_list  *beforelast;
    t_list  *curr;

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

void    rra(t_list **lsta, t_list **lstb)
{
    rv(lsta);
    ft_printf("rra\n");
}

void    rrb(t_list **lsta, t_list **lstb)
{
    rv(lstb);
    ft_printf("rrb\n");
}

void    rrr(t_list **lsta, t_list **lstb)
{
    rv(lsta);
    rv(lstb);
    ft_printf("rrr\n");
}

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
