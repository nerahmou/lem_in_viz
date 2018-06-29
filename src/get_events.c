#include "lem_in.h"

bool	which_event(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	char	*str;
	SDL_Event e;

	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym)
				{ 
					case SDLK_ESCAPE:
						return (1);
						break;
					case SDLK_SPACE:
						if (!get_next_line(colonie->fd, &str))
							return (1);
						move_ants(colonie, str, window, renderer);
						ft_strdel(&str);
						break;
				}
		}
	}
	return (0);
}

void	get_events(t_info colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	bool	quit;

	quit = false;
	while (!quit)
		quit = which_event(&colonie, window, renderer);
}
