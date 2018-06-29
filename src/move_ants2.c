/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_ants2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:07 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:56:28 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		destroy_ant_to_move(t_ant_move **ant_move)
{
	t_ant_move *tmp;
	t_ant_move *tmp_next;

	tmp = *ant_move;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmp_next;
	}
	ant_move = NULL;
}

t_ant_move	*push_ant_move(t_ant_move *ant_move, t_ants *ant, t_salle *room)
{
	t_ant_move *new;
	t_ant_move *tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = ant_move;
	new->ant = ant;
	new->dest = room;
	new->to_move = true;
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		ant_move = new;
	return (ant_move);
}

t_ant_move	*init_ant_to_move(t_info *colonie, t_ant_move **ant_move,
		char *str)
{
	int			i;
	t_ants		*ant;
	t_salle		*room;
	char		**moves;
	char		**ant_and_room;

	i = -1;
	if (!(moves = ft_strsplit(str, ' ')))
		exit(1);
	while (moves[++i])
	{
		if (!(ant_and_room = ft_strsplit(moves[i], '-')))
			exit(1);
		ant = get_ant_from_name(colonie->ants, ant_and_room[0]);
		room = get_room_by_name(colonie->salle, ant_and_room[1]);
		*ant_move = push_ant_move(*ant_move, ant, room);
		free_tab(ant_and_room);
		ant_and_room = NULL;
	}
	free_tab(moves);
	return (NULL);
}

int			to_move(t_ant_move *ant_move)
{
	t_ant_move *tmp;

	tmp = ant_move;
	while (tmp)
	{
		if (tmp->to_move == true)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			check_go_over(int positive, int src, int dest,
		t_ant_move *ant_move)
{
	if (positive)
	{
		if (src > dest)
		{
			ant_move->to_move = false;
			return (src - (src - dest));
		}
	}
	else
	{
		if (src < dest)
		{
			ant_move->to_move = false;
			return (src + (dest - src));
		}
	}
	return (src);
}
