/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   segment_algo.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 21:51:08 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 22:10:07 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		new_point(t_point *pos, t_point src, int i, t_point step)
{
	(*pos).x = src.x + i * step.x;
	(*pos).y = src.y + i * step.y;
}

t_point		div_step_x(t_point step)
{
	step.y /= ABS(step.x);
	step.x /= ABS(step.x);
	return (step);
}

t_point		div_step_y(t_point step)
{
	step.x /= ABS(step.y);
	step.y /= ABS(step.y);
	return (step);
}

void		draw_line(t_point src, t_point dst, t_tab *tab, int color)
{
	t_point		step;
	int			n;
	int			i;
	t_point		pos;

	i = -1;
	step.x = dst.x - src.x;
	step.y = dst.y - src.y;
	if (ABS(step.x) > ABS(step.y))
	{
		n = ABS(step.x);
		step = div_step_x(step);
	}
	else
	{
		n = ABS(step.y);
		step = div_step_y(step);
	}
	while (++i < n)
	{
		new_point(&pos, src, i, step);
		if ((pos.x >= 0 && pos.x <= W) && (pos.y >= 0 && pos.y <= H))
			mlx_pixel_put(tab->mlx_ptr, tab->win_ptr, pos.x, pos.y, color);
	}
}
