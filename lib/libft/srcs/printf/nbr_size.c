/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nbr_size.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 15:43:39 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 13:28:04 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	d_size(va_list *ap, t_suitcase *s_c)
{
	intmax_t nbr;

	nbr = 0;
	if (s_c->size == 'H')
		nbr = (char)va_arg(*ap, int);
	else if (s_c->size == 'h')
		nbr = (short)va_arg(*ap, int);
	else if (s_c->size == 'l')
		nbr = va_arg(*ap, long);
	else if (s_c->size == 'L')
		nbr = va_arg(*ap, long long);
	else if (s_c->size == 'j')
		nbr = va_arg(*ap, intmax_t);
	else if (s_c->size == 'z')
		nbr = va_arg(*ap, size_t);
	else
		nbr = va_arg(*ap, int);
	return (nbr);
}

uintmax_t	u_size(va_list *ap, t_suitcase *s_c)
{
	uintmax_t nbr;

	nbr = 0;
	if (s_c->size == 'H')
		nbr = (unsigned char)va_arg(*ap, int);
	else if (s_c->size == 'h')
		nbr = (unsigned short)va_arg(*ap, int);
	else if (s_c->size == 'l')
		nbr = va_arg(*ap, unsigned long);
	else if (s_c->size == 'L')
		nbr = va_arg(*ap, unsigned long long);
	else if (s_c->size == 'j')
		nbr = va_arg(*ap, uintmax_t);
	else if (s_c->size == 'z')
		nbr = va_arg(*ap, size_t);
	else
		nbr = va_arg(*ap, unsigned int);
	return (nbr);
}
