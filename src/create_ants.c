/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_ants.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:40 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:34:59 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*create_ant(t_info *colonie, int i, SDL_Renderer *rend, SDL_Window *w)
{
	t_ants	*new;
	t_ants	*tmp;
	char	*nb_tmp;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	tmp = colonie->ants;
	nb_tmp = ft_itoa(i);
	new->name = ft_strjoin("L", nb_tmp);
	if (!nb_tmp || !new->name)
		exit_with_erro("Create ant", rend, w, colonie);
	new->ant_texture = colonie->ant_image;
	new->ant_rect = set_rec((colonie->start->x),
			colonie->start->y, 50, 50);
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

	i = 0;
	colonie->ant_image = IMG_LoadTexture(renderer, "img/ant.png");
	if (!colonie->ant_image)
		exit_with_erro("Image ant", renderer, window, colonie);
	while (++i <= colonie->nb)
		colonie->ants = create_ant(colonie, i, renderer, window);
}
