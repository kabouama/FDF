/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 17:21:02 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 19:44:23 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t cpt;

	cpt = 0;
	while (s[cpt])
	{
		if (s[cpt + 1] == 0)
			return (cpt + 1);
		if (s[cpt + 2] == 0)
			return (cpt + 2);
		if (s[cpt + 3] == 0)
			return (cpt + 3);
		if (s[cpt + 4] == 0)
			return (cpt + 4);
		if (s[cpt + 4] == 0)
			return (cpt + 4);
		if (s[cpt + 5] == 0)
			return (cpt + 5);
		if (s[cpt + 6] == 0)
			return (cpt + 6);
		if (s[cpt + 7] == 0)
			return (cpt + 7);
		cpt += 8;
	}
	return (cpt);
}
