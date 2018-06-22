/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clears.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 14:36:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 14:30:43 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_connection	*nettoyage_connections(t_connection *connection)
{
	t_connection *tmp;

	while (connection)
	{
		tmp = connection->next;
		free(connection);
		connection = NULL;
		connection = tmp;
	}
	return (NULL);
}

t_salle			*nettoyage_salles(t_salle *salle)
{
	t_salle *tmp;

	while (salle)
	{
		ft_strdel(&salle->name);
		salle->co = nettoyage_connections(salle->co);
		tmp = salle->next;
		free(salle);
		salle = NULL;
		salle = tmp;
	}
	return (NULL);
}

t_chemins		*nettoyage_chemin(t_chemins *chemin)
{
	t_chemins *tmp;

	while (chemin)
	{
		chemin->salle = nettoyage_salle2(chemin->salle);
		tmp = chemin->next;
		free(chemin);
		chemin = NULL;
		chemin = tmp;
	}
	return (NULL);
}

void			*nettoyage_colonie(t_info *colonie)
{
	ft_strdel(&colonie->text);
	ft_strdel(&colonie->line);
	free_tab(colonie->line_split);
	colonie->salle = nettoyage_salles(colonie->salle);
	colonie->chemins = nettoyage_chemin(colonie->chemins);
	return (NULL);
}

void			free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			ft_strdel(&tab[i++]);
		free(tab);
	}
}
