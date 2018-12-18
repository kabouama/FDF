/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/21 18:31:09 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:49:18 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		size_maloc(long int n)
{
	int malok;

	malok = 0;
	if (n <= 0)
	{
		n = -n;
		malok++;
	}
	while (n > 0)
	{
		n /= 10;
		malok++;
	}
	return (malok);
}

char			*ft_itoa(int n)
{
	long int	nb;
	int			malok;
	char		*str;

	nb = n;
	malok = size_maloc(n);
	if (!(str = (char*)malloc(malok + 1)))
		return (0);
	str[malok] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[malok - 1] = 48 + nb % 10;
		nb /= 10;
		malok--;
	}
	return (str);
}
