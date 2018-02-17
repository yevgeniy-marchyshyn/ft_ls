/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:18:48 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 15:59:18 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] != '\0')
		j++;
	while (s[j] == '\0' || s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (j < i)
		return (ft_strdup(""));
	len = j - i + 1;
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (k < len)
		result[k++] = s[i++];
	return (result);
}
