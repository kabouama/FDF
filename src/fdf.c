/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 20:38:02 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 00:18:50 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		put_pix(t_tab *tab)
{
	int x;
	int y;
	int i;
	int j;

	x = tab->vect->mrg.x;
	y = tab->vect->mrg.y;
	i = 0;
	j = 0;
	while (j < tab->pos->nb_ord)
	{
		x = MARGE;
		i = 0;
		while (i < tab->pos->nb_abs)
		{
			tab->coord[j][i].x = x;
			tab->coord[j][i].y = y;
			x += tab->jump->jump_right;
			i++;
		}
		y += tab->jump->jump_bot;
		j++;
	}
}

void		set_color(t_tab *tab, int x, int y)
{
	int cpt;
	int tmp;

	cpt = 0;
	tmp = 0;
	tmp = 255 * tab->coord[y][x].z / tab->jump->cpt;
	if (tab->coord[y][x].z >= tab->pos->color_zero)
	{
		if (tab->pos->cpt_space == 0)
			tab->jump->color = ((0) << 16) + ((0 + tmp) << 8) + 130;
		else if (tab->pos->cpt_space == 1)
			tab->jump->color = ((0 + tmp) << 16) + ((0) << 8) + 60;
		else if (tab->pos->cpt_space == 2)
			tab->jump->color = ((198) << 16) + ((0 + tmp) << 8) + 114;
	}
	else
	{
		if (tab->pos->cpt_space == 0)
			tab->jump->color = ((0) << 16) + ((255 - tmp) << 8) + 130;
		if (tab->pos->cpt_space == 1)
			tab->jump->color = ((255 - tmp) << 16) + ((0) << 8) + 60;
		if (tab->pos->cpt_space == 2)
			tab->jump->color = ((255 - tmp) << 16) + ((155) << 8) + 0 + tmp;
	}
}

void		put_line(t_tab *tab)
{
	int x;
	int y;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (y < tab->pos->nb_ord)
	{
		x = 0;
		i = 0;
		while (x < tab->pos->nb_abs)
		{
			set_color(tab, x, y);
			if (x + 1 < tab->pos->nb_abs)
				draw_line(tab->coord[y][x], tab->coord[y][x + 1],
						tab, tab->jump->color);
			if (y + 1 < tab->pos->nb_ord)
				draw_line(tab->coord[y][x], tab->coord[y + 1][x],
						tab, tab->jump->color);
			x++;
		}
		y++;
	}
}

t_tab		*init_all(t_tab *tab, char **map)
{
	tab->pos->nb_abs = cpt_col(map) + 1;
	tab->jump->jump_right = (2560 - 400) / (tab->pos->nb_abs - 1);
	tab->jump->jump_bot = (1400 - 400) / (tab->pos->nb_ord - 1);
	tab->vect->mrg.x = MARGE + MARGE_X;
	tab->vect->mrg.y = MARGE;
	return (tab);
}

void		fdf(t_tab *tab, char **map)
{
	tab->mlx_ptr = mlx_init();
	tab->win_ptr = mlx_new_window(tab->mlx_ptr, 2560, 1400, TITLE);
	init_all(tab, map);
	stock_point(tab);
	init_z(tab, map);
	put_pix(tab);
	algo_obli(tab);
	put_line(tab);
	affiche_help(tab);
	mlx_key_hook(tab->win_ptr, space_color, (void*)tab);
	mlx_hook(tab->win_ptr, 2, (1L << 0), zoom_win, tab);
	mlx_mouse_hook(tab->win_ptr, zoom_mouse, (void*)tab);
	mlx_loop(tab->mlx_ptr);
}
