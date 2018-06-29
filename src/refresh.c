/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:04 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:57:43 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	refresh_ants(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_ants *ants;

	ants = colonie->ants;
	while (ants)
	{
		if (SDL_RenderCopy(rend, ants->ant_texture, NULL, ants->ant_rect) < 0)
			exit_with_erro("Render copy6", rend, window, colonie);
		ants = ants->next;
	}
}

void	refresh_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_room	*rooms;

	rooms = colonie->room;
	while (rooms)
	{
		if (rooms->room != NULL)
		{
			if (SDL_RenderCopy(rend, rooms->room, NULL, rooms->room_rect) < 0)
				exit_with_erro("Render copy4", rend, window, colonie);
		}
		else
		{
			SDL_SetRenderDrawColor(rend, rooms->room_color->r,
					rooms->room_color->g,
					rooms->room_color->b,
					rooms->room_color->a);
			if (SDL_RenderFillRect(rend, rooms->room_rect) < 0)
				exit_with_erro("Fill Rect", rend, window, colonie);
		}
		if (SDL_RenderCopy(rend, rooms->room_text_t, NULL,
					rooms->room_text_r) < 0)
			exit_with_erro("Render copy5", rend, window, colonie);
		rooms = rooms->next;
	}
}

void	refresh(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_line	*line;

	line = colonie->lines;
	if (SDL_RenderClear(rend) < 0)
		exit_with_erro("Render clear", rend, window, colonie);
	if (SDL_RenderCopy(rend, colonie->background, NULL, colonie->bg_rect) < 0)
		exit_with_erro("Render copy1", rend, window, colonie);
	if (SDL_RenderCopy(rend, colonie->nb_moves_text, NULL,
				colonie->nb_moves_rect) < 0)
		exit_with_erro("Render copy2", rend, window, colonie);
	if (SDL_RenderCopy(rend, colonie->options_menu_text, NULL,
				colonie->options_menu_rect) < 0)
		exit_with_erro("Render copy3", rend, window, colonie);
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
	while (line)
	{
		if (SDL_RenderDrawLine(rend, line->src_x, line->src_y,
					line->dst_x, line->dst_y) < 0)
			exit_with_erro("Render DrawLine", rend, window, colonie);
		line = line->next;
	}
	refresh_rooms(colonie, window, rend);
	refresh_ants(colonie, window, rend);
	SDL_RenderPresent(rend);
}
