/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:30:08 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/27 15:04:30 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4a.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_getlenght(int fd)
{
	int		ret;
	char	*line;

	g_l = 0;
	while (g_l < 7 || g_l > 2147483646)
	{
		ft_putstr("lenght = ?\n");
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		g_l = ft_atoi(line);
		if (g_l < 7 || g_l > 2147483646)
			ft_putstr("ERROR, lenght must be >= 7 and < int_MAX\n");
	}
	return (g_l);
}

int		ft_getheight(int fd)
{
	int ret;
	char *line;

	g_h = 0;
	while (g_h < 6 || g_h > 2147483646)
	{
		ft_putstr("height = ?\n");
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		g_h = ft_atoi(line);
		if (g_h < 6 || g_h > 2147483646)
			ft_putstr("ERROR, height must be >= 6 and < int_MAX\n");
	}
	return (g_h);
}

int		ft_fulltab(char **tab, int l, int h)
{
	int a;
	int b;

	a = -1;
	b = -1;
	while (++a < h)
	{
		while (++b < l)
		{
			if (!ft_isalpha(tab[a][b]))
				return (0);
		}
	}
	return (1);
}

int		read_file(int fd)
{
	char **tab;
	int a;

	g_l = ft_getlenght(fd);
	g_h = ft_getheight(fd);
	tab = ft_initmap(g_l, g_h);
	ft_printtab(ft_initmap(g_l, g_h));
	while (ft_win(tab, g_l, g_h))
	{
		ft_printtab(ft_filltab(tab, g_l, g_h));
		if (ft_fulltab(tab, g_l, g_h))
			ft_putstr("END OF GAME\n");
	}
	free(tab);
	return (0);
}

int		main(int ac, char *av[])
{
	int	fd;

	if (ac > 1)
	{
		if ((fd = open(av[1], O_RDONLY)) == 1 || read_file(fd))
			ft_putstr("ERROR\n");
	}
	else
	{
		if (read_file(0))
			ft_putstr("ERROR\n");
	}
	return (0);
}
