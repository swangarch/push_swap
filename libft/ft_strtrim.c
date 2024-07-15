/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:31:21 by shuwang           #+#    #+#             */
/*   Updated: 2024/05/29 21:31:38 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	slen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	int	cins(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	calsize(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = slen(s1) - 1;
	while (i <= j && (cins(set, s1[i]) || cins(set, s1[j])))
	{
		if (cins(set, s1[i]))
			i++ ;
		if (cins(set, s1[j]))
			j-- ;
	}
	size = j - i + 1;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s = malloc(calsize(s1, set) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = slen(s1) - 1;
	c = 0;
	while (i <= j && (cins(set, s1[i]) || cins(set, s1[j])))
	{
		if (cins(set, s1[i]))
			i++ ;
		if (cins(set, s1[j]))
			j-- ;
	}
	while (c < calsize(s1, set))
		s[c++] = s1[i++];
	s[c] = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s\n", ft_strtrim(argv[1],argv[2]));
	else if (ft_strtrim(NULL, NULL) == NULL)
		printf("NULL\n");
	return (0);
}*/
