/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 23:43:32 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/30 17:00:06 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_low(int value, int base)
{
	int				length;
	unsigned int	val_abs;
	char			*output;
	char			*tab;

	if (base == 10)
		return (ft_itoa(value));
	if (!(tab = ft_strdup("0123456789abcdef")))
		return (NULL);
	val_abs = ft_abs(value);
	length = ft_intlen(val_abs, base);
	if (!(output = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	output[length] = 0;
	while (--length >= 0)
	{
		output[length] = tab[val_abs % base];
		val_abs /= base;
	}
	free(tab);
	return (output);
}
