/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 20:06:46 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:06:09 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		print(va_list *ap, t_suitcase *s_c)
{
	if (s_c->type == 'd')
		print_d(ap, s_c);
	else if (s_c->type == 'c')
		return (print_c(ap, s_c));
	else if (s_c->type == 's')
		return (print_s(ap, s_c));
	else if (s_c->type == 'b')
		print_b(ap, s_c);
	else if (s_c->type == 'o')
		print_o(ap, s_c);
	else if (s_c->type == 'u')
		print_u(ap, s_c);
	else if (s_c->type == 'x' || s_c->type == 'X')
		print_x(ap, s_c);
	else if (s_c->type == 'p')
		print_p(ap, s_c);
	else
		print_m(s_c);
	return (1);
}
