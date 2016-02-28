/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linethreat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 13:55:14 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 21:44:17 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

int		ft_linethreat(char **tab, int a, int b)
{
	while (--b >= 0)
	{
		if (tab[a][b] == '.' && a == g_h - 1)
		{
			tab[a][b] = 79;
			break ;
		}
		if (tab[a][b] == '.' && tab[a + 1][b] != '.')
		{
			tab[a][b] = 79;
			break ;
		}
	}
	return (0);
}

int		ft_takecarethreat(char **tab, int a, int b)
{
	if (tab[a][b - 1] == '.' || tab[a][b - 2] == '.' ||
				tab[a][b - 3] == '.' || tab[a][b + 1] == '.')
		return (1);
	else
		return (0);
}

int		ft_checkthreat(char **tab, int a, int b, int k)
{
	while (--a >= 0)
	{
		b = g_le;
		while (--b >= 0)
		{
			k = 0;
			if (tab[a][b] == 'X')
			{
				if (tab[a][b] == tab[a][b - 1])
					k++;
				if (tab[a][b] == tab[a][b - 2])
					k++;
				if (tab[a][b] == tab[a][b - 3])
					k++;
				if (k >= 1 && ft_takecarethreat(tab, a, b) &&
							a == g_h - 1)
					return (ft_linethreat(tab, a, b + 2));
				if (k == 2 && ft_takecarethreat(tab, a, b))
					return (ft_linethreat(tab, a, b + 2));
			}
		}
	}
	return (1);
}
