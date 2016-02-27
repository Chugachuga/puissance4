/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:24:25 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/27 12:15:09 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4a.h"

char	**ft_initmap(int l, int h)
{
	int		a;
	char	**tab;

	a = -1;
	tab = (char**)malloc(sizeof(char*) * (h + 1));
	while (++a < h)
		tab[a] = ft_memset(ft_strnew(l), 46, l);
	return (tab);
}

void	ft_printtab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}
