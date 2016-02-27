/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whowin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:03:53 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/27 14:30:54 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4a.h"

int		ft_winline(char **tab, int a, int b)
{
	if (b < g_l - 3)
	{
		if (tab[a][b] == tab[a][b + 1] && tab[a][b] == tab[a][b + 2]
				&& tab[a][b] == tab[a][b + 3])
			return (1);
	}
	if (a < g_h - 3)
	{
		if (tab[a][b] == tab[a + 1][b] && tab[a][b] == tab[a + 2][b]
				&& tab[a][b] == tab[a + 3][b])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_diagwin(char **tab, int a, int b)
{
	if (a < g_h - 3 && b < g_l - 3)
	{
		if (tab[a][b] == tab[a + 1][b + 1] &&
				tab[a][b] == tab[a + 2][b + 2] &&
					tab[a][b] == tab[a + 3][b + 3])
			return (1);
	}
	if (a > 3 && b > 3)
	{
		if (tab[a][b] == tab[a - 1][b - 1] &&
				tab[a][b] == tab[a - 2][b - 2] &&
					tab[a][b] == tab[a - 3][b - 3])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	ft_whowin(char c)
{
	if (c == 'X')
		ft_putstr("*YOU WIN !!*\n");
	if (c == 'O')
		ft_putstr("COMPUTER WIN\n");
}

int		ft_win(char **tab, int l, int h)
{
	int a;
	int b;

	a = -1;
	b = -1;
	while (++a < h)
	{
		b = -1;
		while (++b < l)
		{
			if (ft_isalpha(tab[a][b]) == 1)
			{
				if (ft_winline(tab, a, b) == 1 ||
						ft_diagwin(tab, a, b) == 1)
				{
					ft_whowin(tab[a][b]);
					return (0);
				}
			}
		}
	}
	return (1);
}
