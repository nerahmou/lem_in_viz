/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_ws.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 16:41:59 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:31:28 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_error(wchar_t *wstr, t_suitcase *s_c)
{
	int i;

	i = 0;
	if (s_c->is_precision)
	{
		while (i++ < s_c->prec)
			if (ft_wcharlen(*wstr++) < 0)
				return (0);
		return (1);
	}
	else
	{
		while (*wstr)
			if (ft_wcharlen(*wstr++) < 0)
				return (0);
	}
	return (1);
}

static void	print_ws_nominus_width(wchar_t *wstr, t_suitcase *s_c, int length)
{
	if (s_c->width < length && !s_c->is_precision)
		s_c->width = length;
	if (s_c->is_precision)
		while (s_c->width-- > s_c->prec)
			s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
	else
		while (s_c->width-- > length)
			s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
	while (s_c->prec > ft_wcharlen(*wstr))
	{
		s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
		s_c->prec--;
	}
	while (s_c->prec >= ft_wcharlen(*wstr) || s_c->width > 0)
	{
		s_c->ret += ft_putwchar(*wstr);
		s_c->prec -= ft_wcharlen(*wstr);
		s_c->width -= ft_wcharlen(*wstr++);
	}
	while (s_c->prec-- > 0)
		s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
}

int			print_ws_nominus(wchar_t *wstr, t_suitcase *s_c)
{
	int length;

	if (!wstr)
		print_s_nominus(NUL, s_c);
	else
	{
		if ((length = ft_wstrlen(wstr)) == -1 && !check_error(wstr, s_c))
			return (0);
		if (s_c->width > s_c->prec)
			print_ws_nominus_width(wstr, s_c, length);
		else if (s_c->is_precision)
			while (*wstr && s_c->prec >= ft_wcharlen(*wstr) && s_c->prec > 0)
			{
				s_c->ret += ft_putwchar(*wstr);
				s_c->prec -= ft_wcharlen(*wstr++);
			}
		else
		{
			while (s_c->width-- > length)
				s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
			while (*wstr)
				s_c->ret += ft_putwchar(*wstr++);
		}
	}
	return (1);
}

int			print_ws_minus(wchar_t *wstr, t_suitcase *s_c)
{
	if (!wstr)
		print_s_minus(NUL, s_c);
	else if (ft_wstrlen(wstr) == -1)
		return (0);
	if (s_c->is_precision)
	{
		while (*wstr && s_c->prec-- > ft_wcharlen(*wstr))
		{
			(s_c->ret += ft_putwchar(*wstr));
			s_c->width -= ft_wcharlen(*wstr++);
		}
		while (s_c->width-- > 0)
			s_c->ret += ft_putchar(' ');
	}
	else
	{
		s_c->width -= ft_wstrlen(wstr);
		while (*wstr)
			s_c->ret += ft_putwchar(*wstr++);
		while (s_c->width-- > 0)
			s_c->ret += ft_putchar(' ');
	}
	return (1);
}
