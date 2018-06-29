/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wcharlen.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 11:26:12 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:54 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t c)
{
	int length;

	length = 0;
	if (c < 0 || c > 0x10FFFF || ((c >= 0xD800) && (c <= 0xDFFF)))
		length = -1;
	else if (c < 0x80)
		length = 1;
	else if (c <= 255 && MB_CUR_MAX == 1)
		length = 1;
	else if (c > 127 && MB_CUR_MAX > 1)
	{
		if (c < 0x800)
			length = 2;
		else if (c < 0x10000)
			length = 3;
		else if (c < 0x110000)
			length = 4;
	}
	else
		length = -1;
	return (length);
}
