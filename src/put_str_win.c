/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_str_win.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 02:07:26 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 21:50:07 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	affiche_help_bot(t_tab *tab)
{
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 10, 1300, WHITE,
			"Scale 3D    :");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 10, 1350, WHITE,
			"Scale Moove :");
}

void	affiche_help(t_tab *tab)
{
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 10, 50, WHITE,
			"Press (p) for up scale");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 10, 100, WHITE,
			"Press (l) for down scale");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 50, WHITE,
			"zoom with mouse wheel");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 100, WHITE,
			"Use arrow for moove");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 150, WHITE,
			"(-) : down 3D");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 200, WHITE,
			"(+) : up 3D");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 250, WHITE,
			"(w) : down cam");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 300, WHITE,
			"(s) : up cam");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 350, WHITE,
			"(z) : change color 0");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 400, WHITE,
			"(x) : degraded 0");
	mlx_string_put(tab->mlx_ptr, tab->win_ptr, 2300, 450, WHITE,
			"TRY TO PRESS SPACE");
	affiche_help_bot(tab);
}
