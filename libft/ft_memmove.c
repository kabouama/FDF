/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 15:07:37 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:39:06 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*srcc;
	char	*destt;

	i = len - 1;
	srcc = (char *)src;
	destt = (char *)dst;
	if (srcc >= destt)
		ft_memcpy(destt, srcc, len);
	else
	{
		while (i >= 0)
		{
			destt[i] = srcc[i];
			i--;
		}
	}
	return (dst);
}
