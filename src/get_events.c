#include "lem_in.h"

/*
void	move_ants(t_info colonie, char *str, SDL_Renderer **renderer)
{

	SDL_Rect rect;
	t_ants	*ant;
	t_salle	*room;

	ant = get_ant_from_name(colonie.ants, "L0");
	room = get_room_by_name(colonie.salle, "end");
	ant->x = (ant->x * w) / max_x;
	ant->y = (ant->y * h) / max_y;
	room->x = (room->x * w) / max_x;
	room->y = (room->y * h) / max_y;

	while (ant->x < room->x || ant->y < room->y)
	{
		ant->x += 15;
		ant->y += 15;
		rect.x = ant->x;
		rect.y = ant->y;
		rect.w = 50;
		rect.h = 50;
		SDL_DestroyTexture(ant->texture);
		ant->texture = IMG_LoadTexture(*renderer, "ant.png");
		SDL_RenderCopy(*renderer, ant->texture, NULL, &rect);
		SDL_RenderPresent(*renderer);
	}
}
*/
void	get_events(t_info colonie, SDL_Renderer *renderer)
{
	bool	quit;
	char	*str;

	quit = false;
	while (!quit)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym)
					{ 
						case SDLK_ESCAPE:
							quit = true;
							break;
						case SDLK_SPACE:
							if (!get_next_line(colonie.fd, &str))
								return ;
					//		move_ants(colonie, str, &renderer);
							ft_strdel(&str);
							break;
					}
			}
		}
		SDL_Delay(1000 / 60);
	}
}
