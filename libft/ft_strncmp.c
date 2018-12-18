/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:23:22 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:30:44 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = n;
	while (s1[i] && s2[i] && i != j - 1)
	{
		if (s1[i] != s2[i])
			return (n > 0 ? (unsigned char)s1[i] - s2[i] : 0);
		i++;
	}
	return (n > 0 ? (unsigned char)s1[i] - s2[i] : 0);
}
