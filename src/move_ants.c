/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:12 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:54:53 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	move_ant(t_ant_move *ant_move)
{
	double		step;
	double		dx;
	double		dy;
	SDL_Rect	*tmp_rect;
	t_salle		*dest;

	tmp_rect = ant_move->ant->ant_rect;
	dest = ant_move->dest;
	dx = dest->x - tmp_rect->x;
	dy = dest->y - tmp_rect->y;
	if (ft_double_abs(dx) >= ft_double_abs(dy))
		step = ft_double_abs(dx);
	else
		step = ft_double_abs(dy);
	dx /= step;
	dy /= step;
	tmp_rect->x += dx * 10;
	tmp_rect->x = check_go_over(dx > 0, tmp_rect->x, dest->x, ant_move);
	tmp_rect->y += dy * 10;
	tmp_rect->y = check_go_over(dy > 0, tmp_rect->y, dest->y, ant_move);
}

void	move(t_ant_move *ant_move)
{
	t_ant_move	*tmp;

	tmp = ant_move;
	while (tmp)
	{
		if (tmp->to_move)
			move_ant(tmp);
		tmp = tmp->next;
	}
}

void	move_ants(t_info *colonie, char *str, SDL_Window *window,
		SDL_Renderer *renderer)
{
	t_ants		*ant;
	t_salle		*room;
	t_ant_move	*ant_move;

	ant_move = NULL;
	init_ant_to_move(colonie, &ant_move, str);
	while (to_move(ant_move))
	{
		move(ant_move);
		refresh(colonie, window, renderer);
		SDL_Delay(10);
	}
	destroy_ant_to_move(&ant_move);
}
