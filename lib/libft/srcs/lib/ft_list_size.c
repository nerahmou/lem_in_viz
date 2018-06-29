/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_size.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:41 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *list)
{
	size_t	length;

	length = 0;
	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}
