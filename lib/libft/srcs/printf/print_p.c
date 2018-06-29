/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_p.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 22:03:36 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 09:14:54 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_p_minus(void *ptr, t_suitcase *s_c)
{
	int length;

	length = ft_uintlen((long)ptr, 16);
	s_c->ret += ft_putstr("0x");
	while (s_c->prec-- > length)
	{
		s_c->ret += ft_putchar('0');
		s_c->width--;
	}
	ft_putnbr_base((long)ptr, "0123456789abcdef", 16);
	s_c->ret += ft_uintlen((long)ptr, 16);
	while (s_c->width-- > length + 2)
		s_c->ret += ft_putchar(' ');
}

static	void	print_p_nominus(void *ptr, t_suitcase *s_c)
{
	int length;
	int print_ox;

	print_ox = 1;
	length = ft_uintlen((long)ptr, 16);
	if (s_c->is_zero)
	{
		s_c->ret += ft_putstr("0x");
		print_ox = 0;
	}
	while (s_c->width > s_c->prec + 2 && s_c->width-- > length + 2)
		s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
	if (print_ox)
		s_c->ret += ft_putstr("0x");
	while (s_c->prec-- > length)
		s_c->ret += ft_putchar('0');
	if (!ptr && s_c->prec < 0 && s_c->is_precision)
		return ;
	ft_putnbr_base((long)ptr, "0123456789abcdef", 16);
	s_c->ret += ft_uintlen((long)ptr, 16);
}

void			print_p(va_list *ap, t_suitcase *s_c)
{
	if (s_c->is_minus)
		print_p_minus(va_arg(*ap, void *), s_c);
	else
		print_p_nominus(va_arg(*ap, void *), s_c);
}
