/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwords.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/30 21:31:01 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/30 21:44:24 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char *str, char c)
{
	int words;

	words = 0;
	while (*str)
	{
		while (*str && ft_ischar(*str, c))
			str++;
		if (*str && !ft_ischar(*str, c))
			words++;
		while (*str && !ft_ischar(*str, c))
			str++;
	}
	return (words);
}
