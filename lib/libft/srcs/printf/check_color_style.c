/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_color_style.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 10:13:45 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 18:43:21 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_color_style(const char *str)
{
	int len;

	if (!ft_strncmp(BLUE, str, (len = 6)))
		ft_putstr(SET_BLUE);
	else if (!ft_strncmp(RED, str, (len = 5)))
		ft_putstr(SET_RED);
	else if (!ft_strncmp(GREEN, str, (len = 7)))
		ft_putstr(SET_GREEN);
	else if (!ft_strncmp(BBLUE, str, (len = 7)))
		ft_putstr(SET_BBLUE);
	else if (!ft_strncmp(BRED, str, (len = 6)))
		ft_putstr(SET_BRED);
	else if (!ft_strncmp(BGREEN, str, (len = 8)))
		ft_putstr(SET_BGREEN);
	else if (!ft_strncmp(ITALIC, str, (len = 8)))
		ft_putstr(SET_ITALIC);
	else if (!ft_strncmp(BOLD, str, (len = 6)))
		ft_putstr(SET_BOLD);
	else if (!ft_strncmp(UNDERLINE, str, (len = 11)))
		ft_putstr(SET_UNDERLINE);
	else if (!ft_strncmp(RES_COLOR, str, (len = 5)))
		ft_putstr(SET_RES);
	return (len);
}

int			check_color_style(const char *str, int *ret)
{
	if (!ft_strncmp(BBLUE, str, 7)
			|| !ft_strncmp(BRED, str, 6)
			|| !ft_strncmp(BGREEN, str, 8)
			|| !ft_strncmp(BLUE, str, 6)
			|| !ft_strncmp(RED, str, 5)
			|| !ft_strncmp(GREEN, str, 7)
			|| !ft_strncmp(ITALIC, str, 8)
			|| !ft_strncmp(BOLD, str, 6)
			|| !ft_strncmp(UNDERLINE, str, 11)
			|| !ft_strncmp(RES_COLOR, str, 5))
		return (get_color_style(str));
	else
		*ret += ft_putchar('{');
	return (1);
}
