/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columnthreat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:47:23 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 21:43:55 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

int		ft_columnthreat(char **tab, int a, int b)
{
	while (--a >= 0)
	{
		if (tab[a][b] == '.')
		{
			tab[a][b] = 79;
			break ;
		}
	}
	return (0);
}

int		ft_tkcolumnthreat(char **tab, int a, int b)
{
	if (tab[a - 1][b] == '.' || tab[a - 2][b] == '.' ||
				tab[a - 3][b] == '.')
		return (1);
	else
		return (0);
}

int		ft_iawinc(char **tab, int a, int b)
{
	int k;

	k = 0;
	while (--b)
	{
		a = g_h;
		while (--a > 2)
		{
			k = 0;
			if (tab[a][b] == 'O')
			{
				if (tab[a][b] == tab[a - 1][b])
					k++;
				if (tab[a][b] == tab[a - 2][b])
					k++;
				if (tab[a][b] == tab[a - 3][b])
					k++;
				if (k == 2)
					return (k);
			}
		}
	}
	return (0);
}

int		ft_checkcthreat(char **tab, int a, int b)
{
	int k;

	k = 0;
	while (--b >= 0)
	{
		a = g_h;
		while (--a > 2)
		{
			k = 0;
			if (tab[a][b] == 'X')
			{
				if (tab[a][b] == tab[a - 1][b])
					k++;
				if (tab[a][b] == tab[a - 2][b])
					k++;
				if (tab[a][b] == tab[a - 3][b])
					k++;
				if (k == 2 && ft_tkcolumnthreat(tab, a, b) &&
							!ft_iawinc(tab, g_h, g_le))
					return (ft_columnthreat(tab, a + 1, b));
			}
		}
	}
	return (1);
}
