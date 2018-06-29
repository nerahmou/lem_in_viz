/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/29 20:11:13 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		abs;
	int		length;
	char	*tab;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	abs = ft_abs(n);
	length = ft_intlen(n, 10);
	if (!(tab = ft_strnew(length)))
		return (NULL);
	while (--length > 0)
	{
		tab[length] = (abs % 10) + '0';
		abs = abs / 10;
	}
	if (n < 0)
		tab[0] = '-';
	else
		tab[0] = abs + '0';
	tab[-1] = 0;
	return (tab);
}
