/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:51 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 18:48:50 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fill_tab(char **tab, int index, char *str, char c)
{
	int	i;
	int length;

	i = 0;
	length = 0;
	while (str[i] && !ft_ischar(str[i++], c))
		length++;
	if (!(tab[index] = (char *)malloc(sizeof(char) * length + 1)))
		return (0);
	i = -1;
	while (++i < length)
		tab[index][i] = str[i];
	tab[index][i] = 0;
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		index;
	int		length;

	if (!s)
		return (NULL);
	index = 0;
	length = ft_countwords((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * length + 1)))
		return ((char**)ft_memalloc(sizeof(char*)));
	while (index < length)
	{
		while (*s && ft_ischar(*s, c))
			s++;
		s += ft_fill_tab(tab, index, (char *)s, c);
		index++;
	}
	tab[length] = 0;
	return (tab);
}
