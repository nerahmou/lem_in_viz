#include "lem_in.h"

extern int w;
extern int h;
extern int max_x;
extern int max_y;

t_ants	*create_ant(t_info *colonie, int i, SDL_Renderer *renderer, SDL_Window *window)
{
	t_ants	*new;
	t_ants	*tmp;
	char	*nb_tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = colonie->ants;
	nb_tmp = ft_itoa(i);
	new->name = (ft_strjoin("L", nb_tmp));
	new->ant_texture = colonie->ant_image;
	new->ant_rect = set_rectangle((colonie->start->x * w) / max_x,
			(colonie->start->y * h) / max_y, 50, 50);
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		colonie->ants = new;
	ft_strdel(&nb_tmp);
	return (colonie->ants);
}

void	get_ants(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	int	i;

	i = -1;
	colonie->ant_image = IMG_LoadTexture(renderer, "img/antr.png");
	while (++i < colonie->nb)
		colonie->ants = create_ant(colonie, i, renderer, window);
}
