/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_b.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 08:19:18 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 13:12:24 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_b_nomin_prec(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	while (s_c->width > nbr_len && s_c->width > s_c->prec)
		(s_c->ret += ft_putchar(' ')) && s_c->width--;
	while (s_c->prec > nbr_len)
		(s_c->ret += ft_putchar('0')) && (s_c->prec-- || s_c->width--);
	if (nbr || s_c->prec > 0)
	{
		ft_putnbr_base(nbr, BI, 2);
		s_c->ret += nbr_len;
		s_c->width -= nbr_len;
	}
	while (s_c->width-- > 0)
		s_c->ret += ft_putchar(' ');
}

static	void	print_b_nominus(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	if (s_c->is_precision)
		print_b_nomin_prec(nbr, nbr_len, s_c);
	else
	{
		while (s_c->width-- > nbr_len)
		{
			if (s_c->is_zero)
				s_c->ret += ft_putchar('0');
			else
				s_c->ret += ft_putchar(' ');
		}
		ft_putnbr_base(nbr, BI, 2);
		s_c->ret += nbr_len;
	}
}

static	void	print_b_minus(uintmax_t nbr, int nbr_len, t_suitcase *s_c)
{
	while (s_c->prec > nbr_len)
		(s_c->ret += ft_putchar('0')) && (s_c->prec-- || s_c->width--);
	if (!s_c->prec && !nbr)
		s_c->width++;
	else
	{
		ft_putnbr_base(nbr, BI, 2);
		s_c->ret += nbr_len;
	}
	s_c->width -= nbr_len;
	while (s_c->width-- > 0)
		s_c->ret += ft_putchar(' ');
}

void			print_b(va_list *ap, t_suitcase *s_c)
{
	uintmax_t	nbr;
	int			nbr_length;

	nbr = u_size(ap, s_c);
	nbr_length = ft_uintlen(nbr, 2);
	if (s_c->is_minus)
		print_b_minus(nbr, nbr_length, s_c);
	else
		print_b_nominus(nbr, nbr_length, s_c);
}
