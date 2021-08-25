/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:24:48 by gabriel           #+#    #+#             */
/*   Updated: 2021/08/25 14:24:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src [i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

static int	counterwords(const char *s, char c)
{
	unsigned int	i;
	int				cntr;

	cntr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != '\0')
			cntr++;
		i++;
	}
	return (cntr);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*str;

	str = (char *) malloc (sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		st;
	int		posc;
	int		n;
	char	**new_str;

	st = 0;
	posc = 0;
	n = 0;
	new_str = (char **) malloc(sizeof (char *) * ((counterwords(s, c) + 1)));
	if (new_str == NULL)
		return (NULL);
	while (s[st] != '\0')
	{
		while (s[st] == c)
			st++;
		posc = st;
		while (s[st] != '\0' && s[st] != c)
			st++;
		if (st > posc)
			new_str[n++] = ft_strndup(s + posc, st - posc);
	}
	new_str[n] = NULL;
	return (new_str);
}
