/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_c.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 22:03:16 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 20:06:32 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_char(va_list ap, t_suitcase *s_c)
{
	va_list	ap2;
	int		length;

	va_copy(ap2, ap);
	if (s_c->size == 'l')
		length = ft_wcharlen(va_arg(ap2, wint_t));
	else
		length = 1;
	va_end(ap2);
	return (length);
}

static int		print_c_size(va_list *ap, t_suitcase *s_c)
{
	if (s_c->size == 'l')
	{
		if (!(s_c->ret += ft_putwchar(va_arg(*ap, wint_t))))
			return (0);
	}
	else
		s_c->ret += ft_putchar(va_arg(*ap, int));
	return (1);
}

int				print_c(va_list *ap, t_suitcase *s_c)
{
	int length;

	if ((length = get_char(*ap, s_c)) == -1)
		return (0);
	if (s_c->width)
	{
		if (s_c->is_minus)
		{
			if (!print_c_size(ap, s_c))
				return (0);
			while (s_c->width-- > length)
				s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
		}
		else
		{
			while (s_c->width-- > length)
				s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
			if (!print_c_size(ap, s_c))
				return (0);
		}
	}
	else if (!print_c_size(ap, s_c))
		return (0);
	return (1);
}
