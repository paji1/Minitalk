/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 04:09:40 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/17 19:01:17 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(const char *s, char c)
{
	int	i;
	int	t;

	i = -1;
	t = 0;
	while (s[++i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1]))
			t++;
		if (!i && s[i] != c)
			t++;
	}
	return (t);
}

static	int	nex(const char *s, char c, int i)
{
	int	t;

	t = 0;
	while (s[i] && s[i] != c)
	{
		t++;
		i++;
	}
	return (t);
}

static	int	freetable(char **tab, char *s, int i)
{
	if (!s)
	{
		while (i > 0)
			free(tab[--i]);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		t;
	char	**tab;

	i = -1;
	t = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && t < countwords(s, c))
		{
			tab[t] = ft_substr(s, i, nex(s, c, i));
			if (freetable(tab, tab[t], t))
				return (free(tab), (NULL));
			tab[t++][nex(s, c, i)] = 0;
			i += nex(s, c, i);
		}
	}
	tab[t] = NULL;
	return (tab);
}
