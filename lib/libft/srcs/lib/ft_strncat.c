/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:49 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/30 20:16:44 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	while (*src && n--)
	{
		dest[i++] = *src;
		src++;
	}
	dest[i] = 0;
	return (dest);
}
