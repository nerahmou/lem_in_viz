/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 23:43:32 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/31 16:20:39 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int				length;
	unsigned int	abs;
	char			*output;

	if (base == 10)
		return (ft_itoa(value));
	abs = ft_abs(value);
	length = ft_intlen(abs, base);
	if (!(output = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	output[length] = 0;
	while (--length >= 0)
	{
		output[length] = abs % base > 9 ? abs % base + 55 : abs % base + 48;
		abs /= base;
	}
	return (output);
}
