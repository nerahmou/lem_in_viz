/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 14:53:38 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 16:30:22 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <lem_in.h>

t_salle_2	*nettoyage_salle2(t_salle_2 *salle)
{
	t_salle_2 *tmp;

	while (salle)
	{
		ft_strdel(&salle->name);
		tmp = salle->next;
		free(salle);
		salle = NULL;
		salle = tmp;
	}
	return (NULL);
}

void		ft_error(t_info *colonie)
{
	ft_printf("Error\n");
	nettoyage_colonie(colonie);
	exit(1);
}
