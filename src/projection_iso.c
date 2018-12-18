/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection_iso.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 20:59:07 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 21:56:51 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	algo_iso(t_tab *tab)
{
	int x;
	int y;

	y = 0;
	actu_vect(tab);
	while (y < tab->pos->nb_ord)
	{
		x = 0;
		while (x < tab->pos->nb_abs)
		{
			tab->coord[y][x].x = ((ft_sqrt(2) / 2) * (x * tab->vect->vect_i.x -
						y * tab->vect->vect_i.y)) +
				(tab->vect->vect_k.x * tab->coord[y][x].z) + tab->vect->mrg.x;
			tab->coord[y][x].y = ((ft_sqrt(2 / 3) * tab->coord[y][x].z) -
					(1 / ft_sqrt(6)) +
					(tab->vect->vect_i.x * x + y * tab->vect->vect_i.y)) +
				(tab->vect->vect_k.y * tab->coord[y][x].z) + tab->vect->mrg.y;
			x++;
		}
		y++;
	}
}
