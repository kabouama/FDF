/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 23:35:54 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 00:19:36 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	**fdf_parsing(char **av, t_tab *tab)
{
	int		fd;
	char	*line;
	char	**map;
	int		y;
	int		tmp;

	y = -1;
	tmp = 0;
	line = NULL;
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
		tmp++;
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(map = (char **)malloc(sizeof(char *) * tmp)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		map[++y] = ft_strdup(line);
		free(line);
	}
	map[y] = NULL;
	tab->pos->nb_ord = y;
	return (map);
}

int		cpt_col(char **map)
{
	int		cpt;
	int		x;

	x = 0;
	cpt = 0;
	while (map[1][x])
	{
		if (map[1][x] == ' ')
		{
			if (map[1][x + 1] == ' ')
				x++;
			cpt++;
		}
		x++;
	}
	return (cpt);
}

void	init_z(t_tab *tab, char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	**tst;

	x = 0;
	y = 0;
	j = 0;
	tab->jump->cpt = 0;
	while (map[j])
	{
		i = 0;
		x = 0;
		tst = ft_strsplit(map[j], ' ');
		while (tst[i])
		{
			tab->coord[y][x].z = ft_atoi(tst[i++]);
			if (tab->coord[y][x].z > tab->jump->cpt)
				tab->jump->cpt = tab->coord[y][x].z;
			x++;
		}
		y++;
		j++;
	}
}
