/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:42 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:42 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (alst)
	{
		while (*alst)
		{
			list = *alst;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
			*alst = list->next;
		}
	}
}
