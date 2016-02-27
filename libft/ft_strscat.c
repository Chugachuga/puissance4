/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 23:07:17 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/17 03:43:50 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strscat(char *s1, char *s2)
{
	char	*new;
	size_t	index;

	index = 0;
	if (!(new = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[index])
	{
		new[index] = s1[index];
		index++;
	}
	while (*s2)
	{
		new[index] = *s2;
		index++;
		s2 += 1;
	}
	new[index] = '\0';
	free(s1);
	return (new);
}
