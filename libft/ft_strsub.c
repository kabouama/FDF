/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:16:03 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 19:11:44 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tron;
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = start + len;
	tron = malloc(sizeof(char) * len + 1);
	if (!(tron))
		return (NULL);
	if (s)
	{
		while (start < tmp)
		{
			tron[i] = s[start];
			i++;
			start++;
		}
	}
	tron[i] = '\0';
	return (tron);
}
