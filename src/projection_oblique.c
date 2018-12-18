/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection_oblique.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 22:06:10 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 21:57:51 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_vect(t_tab *tab)
{
	tab->vect->vect_ii.x = 10;
	tab->vect->vect_ii.y = 10;
	tab->vect->vect_jj.x = -10;
	tab->vect->vect_jj.y = 7;
	tab->vect->vect_kk.x = 0;
	tab->vect->vect_kk.y = 0;
}

void	actu_vect(t_tab *tab)
{
	tab->vect->vect_i.x = tab->vect->vect_ii.x * tab->vect->zuum.x;
	tab->vect->vect_i.y = tab->vect->vect_ii.y * tab->vect->zuum.x;
	tab->vect->vect_j.x = tab->vect->vect_jj.x * tab->vect->zuum.x;
	tab->vect->vect_j.x = tab->vect->vect_jj.y * tab->vect->zuum.x;
	tab->vect->vect_k.x = tab->vect->vect_kk.x * tab->vect->zuum.x;
}

void	algo_obli(t_tab *tab)
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
			tab->coord[y][x].x = x * tab->vect->vect_i.x + ((1 / 2) *
					tab->coord[y][x].z * sin(M_PI)) +
				(tab->vect->vect_k.x * tab->coord[y][x].z) + tab->vect->mrg.x;
			tab->coord[y][x].y = y * tab->vect->vect_i.y + ((1 / 2) *
					tab->coord[y][x].z * cos(M_PI)) +
				(tab->vect->vect_k.y * tab->coord[y][x].z) + tab->vect->mrg.y;
			x++;
		}
		y++;
	}
}
