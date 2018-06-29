/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_lines.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:44 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:35:42 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

extern int g_w;
extern int g_h;
extern int g_max_x;
extern int g_max_y;

t_line	*create_line(t_info *colonie, t_salle *src, t_salle *dest,
		SDL_Renderer *renderer)
{
	t_line	*new;
	t_line	*tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = colonie->lines;
	new->src_x = ((src->x * g_w) / g_max_x) + 25;
	new->src_y = ((src->y * g_h) / g_max_y) + 25;
	new->dst_x = ((dest->x * g_w) / g_max_x) + 25;
	new->dst_y = ((dest->y * g_h) / g_max_y) + 25;
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		colonie->lines = new;
	return (colonie->lines);
}

void	get_lines(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_salle			*salle;
	t_connection	*co;

	salle = colonie->salle;
	while (salle)
	{
		co = salle->co;
		while (co)
		{
			colonie->lines = create_line(colonie, salle, co->salle, rend);
			co = co->next;
		}
		salle = salle->next;
	}
}
