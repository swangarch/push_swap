/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:06:14 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 16:06:17 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	in_fail_multiargv(int **inputs)
{
	write(2, "Error\n", 6);
	free(*inputs);
	exit(EXIT_FAILURE);
}

void	in_fail_argvinquote(int **inputs, char **args_inquote)
{
	write(2, "Error\n", 6);
	free_tab(args_inquote);
	free(inputs);
	exit(EXIT_FAILURE);
}

void	ft_lstclear_nfunc(t_list **lst)
{
	t_list	*curr;
	t_list	*freenode;

	curr = *lst;
	if (*lst == NULL)
		return ;
	while (curr != NULL)
	{
		freenode = curr;
		curr = curr->next;
		free(freenode);
		freenode = NULL;
	}
	*lst = NULL;
}

void	delete_stack(t_list **lsta, t_list **lstb, int	*inputs)
{
	ft_lstclear_nfunc(lsta);
	ft_lstclear_nfunc(lstb);
	free(inputs);
}
