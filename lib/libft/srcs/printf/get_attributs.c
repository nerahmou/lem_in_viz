/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_attributs.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 14:02:33 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:55:49 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	check_sizetype(t_suitcase *s_c)
{
	if (s_c->type != 0 && ft_strchr("SCDOU", s_c->type))
		s_c->type += 32;
	else
		return ;
	s_c->size = 'l';
}

int				get_attributs(va_list *ap, t_suitcase *s_c, const char *str)
{
	if (ft_strchr(str, 'n'))
		s_c->type = 'n';
	while (*str && !ft_strchr(TYPE, *str))
	{
		if (ft_strchr(FLAGS, *str))
			get_flag(s_c, *str);
		else if (ft_strchr(WIDTH, *str))
			get_width(ap, s_c, str);
		else if (ft_strchr(SIZE, *str))
			get_size(s_c, str);
		else if (ft_strchr(PREC, *str))
			get_prec(ap, s_c, str);
		else
		{
			s_c->type = *str;
			return (1);
		}
		s_c->length += s_c->position;
		str += s_c->position;
		s_c->position = 0;
	}
	get_type(s_c, *str);
	check_sizetype(s_c);
	return (0);
}
