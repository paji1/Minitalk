/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/18 08:55:37 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	lent;

	if (!s)
		return (NULL);
	lent = ft_strlen(s);
	if (lent <= len)
		len = lent;
	if (lent <= start)
	{
		p = ft_strdup("");
		if(!p)
			return (NULL);
		return (p);
	}
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
