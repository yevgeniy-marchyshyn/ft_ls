/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:19:39 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 08:19:44 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*free_for_secure(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
	return (NULL);
}

static int		word_count(char const *s, char c)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (count);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int		word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	while (i < word_count(s, c))
	{
		while (s[k] == c)
			k++;
		if (!(res[i] = ft_strsub(s, k, word_len(s + k, c))))
			return (free_for_secure(res));
		k += word_len(s + k, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
