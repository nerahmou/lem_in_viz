/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_x.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 22:02:41 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:05:58 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_x_nomin_prec(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	if (s_c->prec && nbr && s_c->is_sharp)
	{
		s_c->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		s_c->ret += 2;
		s_c->width -= 2;
	}
	while (s_c->width > nbr_len && s_c->width > s_c->prec)
		(s_c->ret += ft_putchar(' ')) && s_c->width--;
	while (s_c->prec > nbr_len)
		(s_c->ret += ft_putchar('0')) && s_c->prec-- && s_c->width--;
	if (nbr || s_c->prec > 0)
	{
		ft_putnbr_base(nbr, s_c->type == 'x' ? XLOW : XUPP, 16);
		s_c->ret += ft_uintlen(nbr, 16);
		s_c->width -= nbr_len;
	}
	while (s_c->width-- > 0)
		s_c->ret += ft_putchar(' ');
}

static	void	print_x_nominus(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	if (s_c->is_precision)
		print_x_nomin_prec(nbr, nbr_len, s_c);
	else
	{
		if (s_c->is_zero && s_c->is_sharp && nbr)
		{
			s_c->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
			s_c->ret += 2;
			s_c->width -= 2;
			s_c->is_sharp = 0;
		}
		while (s_c->width-- > nbr_len + (s_c->is_sharp && nbr ? 2 : 0))
			s_c->ret += s_c->is_zero ? ft_putchar('0') : ft_putchar(' ');
		if (s_c->is_sharp && nbr != 0)
		{
			s_c->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
			s_c->ret += 2;
			s_c->width--;
		}
		ft_putnbr_base(nbr, s_c->type == 'x' ? XLOW : XUPP, 16);
		s_c->ret += ft_uintlen(nbr, 16);
	}
}

static	void	print_x_minus(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	if (s_c->is_sharp)
	{
		s_c->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		s_c->ret += 2;
		s_c->width -= 2;
	}
	while (s_c->prec > nbr_len)
		(s_c->ret += ft_putchar('0')) && s_c->width-- && s_c->prec--;
	if (!s_c->prec && !nbr)
		s_c->width++;
	else
	{
		ft_putnbr_base(nbr, s_c->type == 'x' ? XLOW : XUPP, 16);
		s_c->ret += ft_uintlen(nbr, 16);
	}
	s_c->width -= nbr_len;
	while (s_c->width-- > 0)
		s_c->ret += ft_putchar(' ');
}

void			print_x(va_list *ap, t_suitcase *s_c)
{
	uintmax_t	nbr;
	int			nbr_length;

	nbr = u_size(ap, s_c);
	nbr_length = ft_uintlen(nbr, 16);
	if (s_c->is_minus)
		print_x_minus(nbr, nbr_length, s_c);
	else
		print_x_nominus(nbr, nbr_length, s_c);
}
