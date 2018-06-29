/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:45 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 20:47:49 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7f)
		write(fd, &c, 1);
	else if (c <= 0x7ff)
	{
		ft_putchar_fd((char)(0xC0 | (c >> 6)), fd);
		ft_putchar_fd((char)((0x3f & c) | 0x80), fd);
	}
	else if (c <= 0xffff)
	{
		ft_putchar_fd((char)(0xE0 | (c >> 12)), fd);
		ft_putchar_fd((char)(((0x3f & (c >> 6))) | 0x80), fd);
		ft_putchar_fd((char)((0x3f & c) | 0x80), fd);
	}
	else
	{
		ft_putchar_fd((char)0xF0 | (c >> 18), fd);
		ft_putchar_fd((char)(((0x3f & (c >> 12))) | 0x80), fd);
		ft_putchar_fd((char)(((0x3f & (c >> 6))) | 0x80), fd);
		ft_putchar_fd((char)((0x3f & c) | 0x80), fd);
	}
}
