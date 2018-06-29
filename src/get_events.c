/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_events.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:23 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:51:30 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

bool	which_event(t_info *colonie, SDL_Window *window, SDL_Renderer *rend)
{
	char		*str;
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			else if (e.key.keysym.sym == SDLK_SPACE)
			{
				if (!get_next_line(colonie->fd, &str))
					return (1);
				move_ants(colonie, str, window, rend);
				ft_strdel(&str);
			}
		}
	}
	return (0);
}

void	get_events(t_info colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	bool		quit;

	quit = false;
	while (!quit)
		quit = which_event(&colonie, window, renderer);
}
