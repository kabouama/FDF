/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 18:00:25 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 00:17:54 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_tab		*maloc_struct(t_tab *tab)
{
	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (NULL);
	if (!(tab->jump = (t_jump*)malloc(sizeof(t_jump))))
		return (NULL);
	if (!(tab->vect = (t_vect*)malloc(sizeof(t_vect))))
		return (NULL);
	if (!(tab->pos = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	return (tab);
}

void		init_base(t_tab *tab)
{
	tab->jump->speed_p = 0;
	tab->jump->speed_m = 0;
	tab->pos->cpt_space = 0;
	tab->vect->zuum.x = 1;
	tab->change_proj = 0;
	tab->pos->color_zero = 0;
	init_vect(tab);
}

int			main(int argc, char *argv[])
{
	void		*win_ptr;
	char		**map;
	t_tab		*tab;

	tab = NULL;
	tab = maloc_struct(tab);
	map = NULL;
	if (argc != 2)
		return (0);
	tab->mlx_ptr = NULL;
	win_ptr = NULL;
	map = fdf_parsing(argv, tab);
	init_base(tab);
	fdf(tab, map);
	free(tab);
	free(tab->jump);
	free(tab->vect);
	free(tab->pos);
	return (0);
}
