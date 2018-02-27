/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:37:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/27 14:37:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_words(char **files)
{
	int i;

	i = 0;
	if (files)
	{
		while (files[i] != NULL)
		{
			free(files[i]);
			files[i] = NULL;
			i++;
		}
		free(files);
	}
}