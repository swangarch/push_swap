/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:27 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:56:32 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	all_digits(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_double(int *num, int count)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (num[i] == num[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	lst_print(t_list *lst)
{
	int	*value;

	while(lst)
	{
		value = (int *)(lst->content);
		ft_printf("%d ", *value);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	int_overflow(const char *nptr)
{
	size_t		i;
	int		sign;
	long		num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (sign > 0 && num > ((INT_MAX - (nptr[i] - '0')) / 10))
			return (1);
		if (sign < 0 && -num < ((INT_MIN + (nptr[i] - '0')) / 10))
			return (1);
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (i < ft_strlen(nptr))
		return (1);
	return (0);
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
/*
int	main(void)
{
	int	of;

	of = int_overflow("1234890");
	if (of == 1)
		ft_putnbr_fd(of, 1);
	else
		ft_putstr_fd("Not overflow", 1);
}*/
