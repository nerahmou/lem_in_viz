/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:49 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:49 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	if (s)
	{
		i = -1;
		tab = malloc(ft_strlen((char*)s) + 1);
		if (!tab)
			return (NULL);
		while (s[++i])
			tab[i] = (*f)(i, s[i]);
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}
