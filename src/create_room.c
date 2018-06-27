#include "lem_in.h"

extern int w;
extern int h;
extern int max_x;
extern int max_y;
extern SDL_Color White;

void	check_room_index(t_room **room, int index, t_info *colonie,
		SDL_Renderer *renderer)
{
	t_room *new;

	new = *room;
	if (index == colonie->end->index)
	{
		new->room = IMG_LoadTexture(renderer, "img/end.png");
		new->room_color = set_color(255, 255, 255, 0);
	}
	else
	{
		if (index == colonie->start->index)
			new->room_color = set_color(220, 20, 60, 0);
		else
			new->room_color = set_color(255, 255, 255, 0);
	}
}

void	set_text_room(t_room *new, char *name, t_info *colonie,
		SDL_Renderer *renderer)
{
	SDL_Surface *surface;

	surface = TTF_RenderText_Solid(colonie->style, name, White);
	new->room_text_t = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

t_room	*create_room(t_info *colonie, t_salle **salle, SDL_Renderer *renderer,
		SDL_Window *window)
{
	t_room	*new;
	t_room	*tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = colonie->room;
	(*salle)->x = ((*salle)->x * w) / max_x;
	(*salle)->y = ((*salle)->y * h) / max_y;
	new->room_rect = set_rectangle((*salle)->x, (*salle)->y, 50, 50);
	new->room_text_r = set_rectangle((*salle)->x - 25, (*salle)->y - 80, 100, 80);
	new->room = NULL;
	new->next = NULL;
	check_room_index(&new, (*salle)->index, colonie, renderer);
	set_text_room(new, (*salle)->name, colonie, renderer);
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
