/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4a.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:32:13 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/27 13:31:46 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4A_H
# define PUISSANCE4A_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

long	g_l;
long	g_h;

char	**ft_initmap(int l, int h);
void	ft_printtab(char **tab);
char	**ft_filltab(char **tab, int l, int h);
int		ft_win(char **tab, int l, int h);

#endif
