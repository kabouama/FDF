/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 15:53:03 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 19:22:40 by sbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int racine;

	racine = 1;
	if (nb < 0)
		return (0);
	while (racine * racine != nb)
	{
		if (racine * racine > nb)
			return (racine);
		racine++;
	}
	return (racine);
}
