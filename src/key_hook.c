/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 03:07:25 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 22:14:48 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	boucle_affiche(t_tab *tab)
{
	mlx_clear_window(tab->mlx_ptr, tab->win_ptr);
	affiche_help(tab);
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 150, 1300, WHITE,
			ft_itoa((int)tab->jump->speed_p));
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 150, 1350, WHITE,
			ft_itoa((int)tab->jump->speed_m / 100));
	if (ft_nbrlen((int)tab->jump->speed_m) >= 2)
	{
		mlx_string_put(tab->mlx_ptr, tab->win_ptr, 160, 1350, WHITE, ".");
		mlx_string_put(tab->mlx_ptr, tab->win_ptr, 170, 1350, WHITE,
				ft_itoa((int)tab->jump->speed_m % 100));
	}
	put_pix(tab);
	if (tab->change_proj % 2 == 0)
		algo_obli(tab);
	else
		algo_iso(tab);
	put_line(tab);
}

int		zoom_mouse(int keycode, int x, int y, void *tmp)
{
	t_tab	*tab;

	(void)x;
	(void)y;
	tab = (t_tab*)tmp;
	if (keycode == 4)
		tab->vect->zuum.x *= 1.1;
	if (keycode == 5)
		tab->vect->zuum.x *= 0.9;
	boucle_affiche(tab);
	return (0);
}

int		space_color(int keycode, void *tmp)
{
	t_tab	*tab;

	tab = (t_tab*)tmp;
	if (keycode == SPACE)
		tab->pos->cpt_space++;
	if (tab->pos->cpt_space == 3)
		tab->pos->cpt_space = 0;
	if (keycode == 6)
		tab->pos->color_zero = 1;
	if (keycode == 7)
		tab->pos->color_zero = 0;
	boucle_affiche(tab);
	return (tab->pos->cpt_space);
}

int		moove_arrow(int keycode, t_tab *tab)
{
	if (keycode == LEFT)
		tab->vect->mrg.x -= 10 + tab->jump->speed_m;
	if (keycode == RIGHT)
		tab->vect->mrg.x += 10 + tab->jump->speed_m;
	if (keycode == BOT)
		tab->vect->mrg.y += 10 + tab->jump->speed_m;
	if (keycode == TOP)
		tab->vect->mrg.y -= 10 + tab->jump->speed_m;
	return (0);
}

int		zoom_win(int keycode, t_tab *tab)
{
	if (keycode == P)
	{
		tab->jump->speed_p += 0.1;
		tab->jump->speed_m += 2;
	}
	if (keycode == L && tab->jump->speed_p >= 0.1)
	{
		tab->jump->speed_p -= 0.1;
		tab->jump->speed_m -= 2;
	}
	if (keycode == PLUS)
		tab->vect->vect_k.y -= 0.3 + tab->jump->speed_p;
	if (keycode == MOINS)
		tab->vect->vect_k.y += 0.3 + tab->jump->speed_p;
	moove_arrow(keycode, tab);
	if (keycode == W_ROTATE && tab->vect->vect_ii.y > 0)
		tab->vect->vect_ii.y -= 0.3;
	if (keycode == S_ROTATE && tab->vect->vect_ii.y < 10)
		tab->vect->vect_ii.y += 0.3;
	if (keycode == 36)
		tab->change_proj++;
	if (keycode == 53)
		exit(0);
	boucle_affiche(tab);
	return (0);
}
