/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   adds.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:27:01 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:30:03 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

extern int g_max_x;
extern int g_max_y;

t_salle	*add_salle(t_salle *salle_co, char **salle, int index)
{
	t_salle *ptr;
	t_salle *link;

	ptr = salle_co;
	link = malloc(sizeof(t_salle));
	link->name = ft_strdup(salle[0]);
	link->index = index;
	link->x = ft_atoi(salle[1]) + 2;
	link->y = ft_atoi(salle[2]) + 2;
	if (link->x > g_max_x)
		g_max_x = link->x;
	if (link->y > g_max_y)
		g_max_y = link->y;
	link->is_full = 0;
	link->next = NULL;
	link->co = NULL;
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = link;
	}
	else
		salle_co = link;
	return (salle_co);
}

void	add_liaison(t_salle *salle, char **tab, int first_liaison)
{
	t_salle			*tmp;
	t_connection	*new;
	t_connection	*tmp_co;

	new = malloc(sizeof(t_connection));
	if (new == NULL)
		return ;
	new->salle = get_room_by_name(salle, tab[first_liaison == 1]);
	new->next = NULL;
	tmp = salle;
	while (ft_strcmp(tmp->name, tab[first_liaison == 0]) != 0)
		tmp = tmp->next;
	tmp_co = tmp->co;
	if (tmp->co == NULL)
		tmp->co = new;
	else
	{
		while (tmp_co->next != NULL)
			tmp_co = tmp_co->next;
		tmp_co->next = new;
	}
}
