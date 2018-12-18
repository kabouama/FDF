/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:21:39 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 16:41:56 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		gestion(const char *str, int i)
{
	long var;

	var = 0;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		var = 1;
	return (var);
}

static int		gestion2(const char *str, int i)
{
	long var2;

	var2 = 0;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		var2 = 1;
	return (var2);
}

int				ft_atoi(const char *str)
{
	long i;
	long result;
	long var;
	long var2;

	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	var = gestion(str, i);
	var2 = gestion2(str, i);
	if (var == 1 || var2 == 1)
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (var == 1)
		result = result * -1;
	return (result);
}
