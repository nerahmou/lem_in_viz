#include "lem_in.h"

void		refresh_ants(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_ants *ants;

	ants = colonie->ants;
	while (ants)
	{
		SDL_RenderCopy(rend, ants->ant_texture, NULL, ants->ant_rect);
		ants = ants->next;
	}
}

void		refresh_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_room	*rooms;

	rooms = colonie->room;
	while (rooms)
	{
		if (rooms->room != NULL)
			SDL_RenderCopy(rend, rooms->room, NULL, rooms->room_rect);
		else
		{
			SDL_SetRenderDrawColor(rend, rooms->room_color->r,
											rooms->room_color->g,
												rooms->room_color->b,
													rooms->room_color->a);
			SDL_RenderFillRect(rend, rooms->room_rect);
		}
		SDL_RenderCopy(rend, rooms->room_text_t, NULL, rooms->room_text_r);
		rooms = rooms->next;
	}
}

void		refresh(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	t_line	*line;

	line = colonie->lines;
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, colonie->background, NULL, colonie->bg_rect);
	SDL_RenderCopy(rend, colonie->nb_moves_text, NULL, colonie->nb_moves_rect);
	SDL_RenderCopy(rend, colonie->options_menu_text, NULL, 
												colonie->options_menu_rect);
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
	while (line)
	{
		SDL_RenderDrawLine(rend, line->src_x, line->src_y,
									line->dst_x, line->dst_y);
		line = line->next;
	}
	refresh_rooms(colonie, window, rend);
	refresh_ants(colonie, window, rend);
	SDL_RenderPresent(rend);
}
