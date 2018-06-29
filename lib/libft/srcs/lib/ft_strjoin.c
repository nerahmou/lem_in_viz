/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:48 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:48 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		length;
	char	*tab;

	if (s1 && s2)
	{
		i = 0;
		length = ft_strlen(s1) + ft_strlen(s2);
		if (!(tab = (char*)malloc(length + 1)))
			return (NULL);
		while (*s1)
			tab[i++] = *s1++;
		while (*s2)
			tab[i++] = *s2++;
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}
