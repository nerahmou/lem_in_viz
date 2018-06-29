/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:15:51 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 20:09:16 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwchar(wchar_t c)
{
	int length;

	length = ft_wcharlen(c);
	if (length == 1)
		write(1, &c, 1);
	else if (length == 2)
	{
		ft_putchar((char)(0xC0 | (c >> 6)));
		ft_putchar((char)((0x3f & c) | 0x80));
	}
	else if (length == 3)
	{
		ft_putchar((char)(0xE0 | (c >> 12)));
		ft_putchar((char)(((0x3f & (c >> 6))) | 0x80));
		ft_putchar((char)((0x3f & c) | 0x80));
	}
	else if (length == 4)
	{
		ft_putchar((char)0xF0 | (c >> 18));
		ft_putchar((char)(((0x3f & (c >> 12))) | 0x80));
		ft_putchar((char)(((0x3f & (c >> 6))) | 0x80));
		ft_putchar((char)((0x3f & c) | 0x80));
	}
	return (length);
}
