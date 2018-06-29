/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/07 19:18:16 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 20:04:26 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(const wchar_t *wstr)
{
	int	length;

	length = 0;
	while (*wstr)
		if (!(length += ft_wcharlen(*wstr++)))
			return (-1);
	return (length);
}
