/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_room.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:34 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:53:52 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

extern int g_w;
extern int g_h;
extern int g_max_x;
extern int g_max_y;
extern SDL_Color g_white;

int		check_room_index(t_room **room, int index, t_info *colonie,
		SDL_Renderer *renderer)
{
	t_room *new;

	new = *room;
	if (index == colonie->end->index)
	{
		new->room = IMG_LoadTexture(renderer, "img/end.png");
		new->room_color = set_color(255, 255, 255, 0);
		if (!new->room)
			return (1);
	}
	else
	{
		if (index == colonie->start->index)
			new->room_color = set_color(220, 20, 60, 0);
		else
			new->room_color = set_color(255, 255, 255, 0);
	}
	return (0);
}

int		set_text_room(t_room *new, char *name, t_info *colonie,
		SDL_Renderer *renderer)
{
	SDL_Surface *surface;

	surface = TTF_RenderText_Solid(colonie->style, name, g_white);
	if (!surface)
		return (1);
	new->room_text_t = SDL_CreateTextureFromSurface(renderer, surface);
	if (!new->room_text_t)
		return (1);
	SDL_FreeSurface(surface);
	return (0);
}

t_room	*create_room(t_info *colonie, t_salle **salle, SDL_Renderer *renderer,
		SDL_Window *window)
{
	t_room	*new;
	t_room	*tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = colonie->room;
	(*salle)->x = ((*salle)->x * g_w) / g_max_x;
	(*salle)->y = ((*salle)->y * g_h) / g_max_y;
	new->room_rect = set_rec((*salle)->x, (*salle)->y, 50, 50);
	new->room_text_r = set_rec((*salle)->x - 25, (*salle)->y - 80, 100, 80);
	new->room = NULL;
	new->next = NULL;
	if (check_room_index(&new, (*salle)->index, colonie, renderer))
		exit_with_erro("Image room end", renderer, window, colonie);
	if (set_text_room(new, (*salle)->name, colonie, renderer))
		exit_with_erro("Text room", renderer, window, colonie);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		colonie->room = new;
	return (colonie->room);
}

void	get_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	t_salle	*salle;

	salle = colonie->salle;
	while (salle)
	{
		colonie->room = create_room(colonie, &salle, renderer, window);
		salle = salle->next;
	}
}
