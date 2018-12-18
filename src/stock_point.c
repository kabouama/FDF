/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_point.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 01:53:50 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 00:20:14 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	stock_point(t_tab *tab)
{
	int tmp_x;
	int tmp_y;

	tmp_y = 0;
	if (!(tab->coord = (t_point **)malloc(sizeof(t_point *) *
					tab->pos->nb_ord)))
		return ;
	while (tmp_y < tab->pos->nb_ord)
	{
		if (!(tab->coord[tmp_y] = (t_point *)malloc(sizeof(t_point) *
						tab->pos->nb_abs)))
			return ;
		tmp_x = 0;
		while (tmp_x < tab->pos->nb_abs)
		{
			tab->coord[tmp_y][tmp_x].x = 0;
			tab->coord[tmp_y][tmp_x].y = 0;
			tab->coord[tmp_y][tmp_x].z = 0;
			tmp_x++;
		}
		tmp_y++;
	}
}

void	free_tab(t_tab *tab)
{
	int y;

	y = 0;
	while (y < tab->pos->nb_ord)
	{
		free(tab->coord[y]);
		y++;
	}
}
