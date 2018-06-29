/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:51 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/30 20:22:27 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcmp_bis(char *s1, char *s2, int length)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && i < length)
		i++;
	if ((s1[i] - s2[i]) != 0 && i != length)
		return (0);
	return (1);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int	length;

	if (!(ft_strlen(needle)))
		return ((char *)haystack);
	length = ft_strlen((char*)needle);
	while (*haystack)
	{
		if (ft_strcmp_bis((char *)haystack, (char *)needle, length))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
