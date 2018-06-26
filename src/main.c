/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 16:04:05 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 20:43:42 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <lem_in.h>

extern int w, h, max_x, max_y;
typedef enum Bool
{
	false,
	true
} Bool;

void	exit_viz(SDL_Renderer *rend, SDL_Window *win, int signal)
{
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	exit(signal);
}


void	init_colonie(t_info *colonie)
{
	colonie->nb = 0;
	colonie->index = 0;
	colonie->text = NULL;
	colonie->line = NULL;
	colonie->line_split = NULL;
	colonie->start = NULL;
	colonie->end = NULL;
	colonie->salle = NULL;
	colonie->chemins = NULL;
	colonie->chemins_un = NULL;
	colonie->ants = NULL;
	colonie->nb_moves = 0;
	colonie->fd = open("moves", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (colonie->fd == -1)
		exit_with_erro("FD open", NULL, NULL);
}

void	exit_with_erro(const char *str, SDL_Renderer *rend, SDL_Window *win)
{
	SDL_Log("Error : %s > %s\n", str, SDL_GetError());
	exit_viz(rend, win, 1);
}

t_ants	*get_ant_from_name(t_ants *ants, char *name)
{
	t_ants *tmp;

	tmp = ants;
	while (ft_strcmp(tmp->name, name))
		tmp = tmp->next;
	return (tmp);
}

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

void	get_events(t_info colonie, SDL_Renderer *renderer)
{
	Bool	quit;
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
							move_ants(colonie, str, &renderer);
							ft_strdel(&str);
							break;
					}
			}
		}
		SDL_Delay(1000 / 60);
	}
}

void	file_puts(t_info colonie)
{
	char			*line_tmp;

	line_tmp = colonie.line;
	colonie.line = ft_strtrim(colonie.line);
	ft_strdel(&line_tmp);
	write(colonie.fd, colonie.line, ft_strlen(colonie.line));
	write(colonie.fd, "\n", 1);
}


int main(int argc, char *argv[])
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_info			colonie;

	init_colonie(&colonie);
	while (get_next_line(0, &colonie.line) && ft_strcmp("", colonie.line))
	{
		ft_check_and_add(&colonie);
		ft_strdel(&colonie.line);
	}
	while (get_next_line(0, &colonie.line))
	{
		colonie.nb_moves++;
		file_puts(colonie);
		ft_strdel(&colonie.line);
	}
	create_viz(&window, &renderer, &colonie);
	lseek(colonie.fd, 0, SEEK_SET);
	get_events(colonie, renderer);
	nettoyage_colonie(&colonie);
	exit_viz(renderer, window, 0);
	return 0;
}
