/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   getters_salles.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:51:52 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 12:25:50 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		*get_next_salle2(void *lst)
{
	return (((t_salle_2*)lst)->next);
}

void		*get_next_salle(void *lst)
{
	return (((t_salle*)lst)->next);
}

t_chemins	*get_last_chemin(t_chemins *chemin)
{
	t_chemins *tmp;

	tmp = chemin;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_salle_2	*get_last_salle2(t_salle_2 *salle)
{
	t_salle_2 *tmp;

	tmp = salle;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_salle		*get_room_by_name(t_salle *salle, char *name)
{
	t_salle *tmp;

	tmp = salle;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
