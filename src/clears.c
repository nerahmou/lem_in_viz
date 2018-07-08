/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clears.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 14:36:19 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:48:53 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_ants			*nettoyage_ants(t_ants *ants)
{
	t_ants *tmp;

	while (ants)
	{
		tmp = ants->next;
		ft_strdel(&ants->name);
		SDL_DestroyTexture(ants->ant_texture);
		free(ants->ant_rect);
		ants = tmp;
	}
	return (NULL);
}

t_room			*nettoyage_trooms(t_room *rooms)
{
	t_room	*tmp;

	while (rooms)
	{
		tmp = rooms->next;
		SDL_DestroyTexture(rooms->room);
		SDL_DestroyTexture(rooms->room_text_t);
		free(rooms->room_rect);
		free(rooms->room_color);
		free(rooms->room_text_r);
		rooms = tmp;
	}
	return (NULL);
}

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

void			*nettoyage_colonie(t_info *colonie)
{
	t_line	*tmp;

	ft_strdel(&colonie->line);
	colonie->salle = nettoyage_salles(colonie->salle);
	close(colonie->fd);
	TTF_CloseFont(colonie->style);
	TTF_Quit();
	SDL_DestroyTexture(colonie->background);
	SDL_DestroyTexture(colonie->nb_moves_text);
	SDL_DestroyTexture(colonie->options_menu_text);
	SDL_DestroyTexture(colonie->ant_image);
	free(colonie->bg_rect);
	free(colonie->options_menu_rect);
	while (colonie->lines)
	{
		tmp = colonie->lines->next;
		free(colonie->lines);
		colonie->lines = tmp;
	}
	return (NULL);
}
