/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 15:06:19 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:07:25 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *liste;
	t_list *nextlist;

	liste = (*alst);
	while (liste)
	{
		nextlist = liste->next;
		(*del)(liste->content, liste->content_size);
		free(liste);
		liste = nextlist;
	}
	(*alst) = NULL;
}
