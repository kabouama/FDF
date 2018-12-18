/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstend.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 17:54:51 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 18:03:15 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list *alst, t_list *neww)
{
	t_list *list;

	if (alst && neww)
	{
		list = alst;
		while (list->next)
			list = list->next;
		list->next = neww;
	}
}
