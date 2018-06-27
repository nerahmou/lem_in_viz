#include "lem_in.h"

double d_abs(double d)
{
	if (d >= 0)
		return (d);
	return (-d);
}


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

t_ant_move	*init_ant_to_move(t_info *colonie, t_ant_move **ant_move, char *str)
{
	int			i;
	t_ants		*ant;
	t_salle		*room;
	char		**moves;
	char		**ant_and_room;

	i = -1;
	moves = ft_strsplit(str, ' ');
	while (moves[++i])
	{
		ant_and_room = ft_strsplit(moves[i], '-');
		ant = get_ant_from_name(colonie->ants, ant_and_room[0]);
		room = get_room_by_name(colonie->salle, ant_and_room[1]);
		*ant_move = push_ant_move(*ant_move, ant, room);
		free_tab(ant_and_room);
		ant_and_room = NULL;
	}
	free_tab(moves);
	moves = NULL;
	return (NULL);
}

int		to_move(t_ant_move *ant_move)
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

int	check_go_over(int positive, int src, int dest, t_ant_move *ant_move)
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
		if (src < dest)
		{
			ant_move->to_move = false;
			return (src + (dest - src));
		}
	return (src);
}

void move_ant(t_ant_move *ant_move)
{
	double step;
	double dx;
	double dy;
	SDL_Rect *tmp_rect;
	t_salle *dest;

	tmp_rect = ant_move->ant->ant_rect;
	dest = ant_move->dest;
	dx = dest->x - tmp_rect->x;
	dy = dest->y - tmp_rect->y;
	if (d_abs(dx) >= d_abs(dy))
		step = d_abs(dx);
	else
		step = d_abs(dy);
	dx /= step;
	dy /= step;
	tmp_rect->x += dx * 10;
	tmp_rect->x = check_go_over(dx > 0, tmp_rect->x, dest->x, ant_move);
	tmp_rect->y += dy * 10;
	tmp_rect->y = check_go_over(dy > 0, tmp_rect->y, dest->y, ant_move);
}


void	move(t_ant_move *ant_move)
{
	t_ant_move *tmp;

	tmp = ant_move;
	while (tmp)
	{
		if (tmp->to_move)
			move_ant(tmp);
		tmp = tmp->next;
	}

}

void	move_ants(t_info *colonie, char *str, SDL_Window *window, SDL_Renderer *renderer)
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
			SDL_Delay(30);
	}
	destroy_ant_to_move(&ant_move);
}


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
						Mix_PlayChannel(1, colonie->sound, 0);
						move_ants(colonie, str, window, renderer);
						ft_strdel(&str);
						break;
				}
		}
	}
	return (0);
}

void	init_sound(t_info *colonie)
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
		exit (1);
	Mix_AllocateChannels(2);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
		exit (1);
	colonie->music = Mix_LoadMUS("test.mp3");
	Mix_PlayMusic(colonie->music, -1);
	colonie->sound = Mix_LoadWAV("ryu.wav");
}

void	get_events(t_info colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	bool	quit;
	init_sound(&colonie);

	quit = false;
	while (!quit)
		quit = which_event(&colonie, window, renderer);
}
