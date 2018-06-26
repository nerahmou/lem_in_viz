/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   getters.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:16:35 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:54:31 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*get_ant_from_name(t_ants *ants, char *name)
{
	t_ants *tmp;

	tmp = ants;
	while (ft_strcmp(tmp->name, name))
		tmp = tmp->next;
	return (tmp);
}

int		get_room(t_info *colonie)
{
	t_salle *tmp;
	char	**salle;

	tmp = colonie->salle;
	salle = colonie->line_split;
	colonie->salle = add_salle(tmp, salle, colonie->index);
	colonie->index++;
	return (0);
}

int		get_tubes(t_info *colonie, char *tubes)
{
	char **tab;

	colonie->line_split = ft_strsplit(tubes, '-');
	tab = colonie->line_split;
	if (duplicate_liaison(colonie->salle, tab))
		;
	else
		add_liaison(colonie->salle, tab, 1);
	free_tab(tab);
	colonie->line_split = NULL;
	return (0);
}

t_salle	*get_other_next(t_info *colonie)
{
	char	**tab;
	t_salle	*tmp;

	ft_strdel(&colonie->line);
	get_next_line(0, &colonie->line);
	ft_check_line(colonie);
	tab = ft_strsplit(colonie->line, ' ');
	if (tab[0][0] == '#')
	{
		free_tab(tab);
		return (NULL);
	}
	tmp = get_room_by_name(colonie->salle, tab[0]);
	free_tab(tab);
	colonie->line_split = NULL;
	return (tmp);
}

int		get_other(t_info *colonie, char *other, int tab_len)
{
	if (ft_strcmp(other, "##start") == 0 && tab_len == 1)
		colonie->start = get_other_next(colonie);
	else if (strcmp(other, "##end") == 0 && tab_len == 1)
		colonie->end = get_other_next(colonie);
	else if (other[0] == '#')
		;
	else if (ft_strchr_occur(other, '-') == 1 && tab_len == 1)
		get_tubes(colonie, other);
	return (0);
}
