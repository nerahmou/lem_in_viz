/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 22:04:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 18:50:04 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_suitcase(t_suitcase *s_c)
{
	s_c->is_sharp = 0;
	s_c->is_zero = 0;
	s_c->is_minus = 0;
	s_c->is_plus = 0;
	s_c->is_space = 0;
	s_c->width = 0;
	s_c->is_precision = 0;
	s_c->prec = 0;
	s_c->size = 0;
	s_c->type = 0;
	s_c->length = 0;
	s_c->position = 0;
	s_c->ret = 0;
	s_c->ret_nul = 0;
}

static int	check_and_print(va_list *ap, const char **str, int *ret)
{
	t_suitcase	s_c;

	init_suitcase(&s_c);
	*str += get_attributs(ap, &s_c, ++*str);
	if (s_c.type == 'n')
		get_ret_value(ap, &s_c, ret);
	else if (!print(ap, &s_c))
		return (0);
	*str += s_c.length;
	*ret += s_c.ret;
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%' && *str != '{')
			ret += ft_putchar(*str++);
		else if (*str == '%')
		{
			if (!check_and_print(&ap, &str, &ret))
				return (-1);
		}
		else
			str += check_color_style(str, &ret);
	}
	va_end(ap);
	return (ret);
}
