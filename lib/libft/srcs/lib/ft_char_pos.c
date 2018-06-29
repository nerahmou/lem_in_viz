/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char_in_str.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:48:50 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 09:07:12 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_pos(char *str, char c)
{
	size_t length;

	length = 0;
	while (str[length] && str[length] != c)
		length++;
	return (length);
}
