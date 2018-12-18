/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:25:34 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 17:30:40 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (s[0] != c && s[0])
		s++;
	if ((char)c == '\0' || (char)c == s[0])
		return ((char*)s);
	else
		return (NULL);
	return ((char*)s);
}
