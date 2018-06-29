/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:50:46 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:50:46 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int racine;

	racine = 1;
	while (racine <= nb / 2)
	{
		if (racine * racine == nb)
			return (racine);
		racine++;
	}
	return (0);
}
