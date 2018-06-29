/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:51 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:51 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nospace(char s)
{
	return (!(s == ' ' || s == '\t' || s == '\n'));
}

static char		*ft_trim(const char *s, int length)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && !ft_nospace(s[i]))
		i++;
	while (s[i] && !ft_nospace(s[length - 1]))
		length--;
	if (!(tab = ft_strnew(length - i)))
		return (NULL);
	ft_strncpy(tab, &s[i], length - i);
	return (tab);
}

char			*ft_strtrim(const char *s)
{
	int		length;
	char	*tab;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (ft_nospace(s[0]) && ft_nospace(s[length - 1]))
	{
		if (!(tab = ft_strnew(length)))
			return (NULL);
		ft_strcpy(tab, s);
	}
	else
		tab = ft_trim(s, length);
	return (tab);
}
