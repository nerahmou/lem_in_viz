/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nbrlen.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 14:29:45 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 22:16:55 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(intmax_t n, int base)
{
	int length;

	length = 0;
	if (n <= 0)
		length++;
	while (n)
	{
		length++;
		n = n / base;
	}
	return (length);
}
