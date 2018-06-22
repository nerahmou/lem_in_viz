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
#include <lem_in.h>

typedef enum Bool
{
	false,
	true
} Bool;

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
}

void	exit_viz(SDL_Renderer *rend, SDL_Window *win, int signal)
{
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	exit(signal);
}

void	exit_with_erro(const char *str, SDL_Renderer *rend, SDL_Window *win)
{
	SDL_Log("Error : %s > %s\n", str, SDL_GetError());
	exit_viz(rend, win, 1);
}


void	get_events()
{
	Bool			quit = false;
	while (!quit)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			switch(e.type) 
			{ 
				case SDL_QUIT:
					quit = true;
					break;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	SDL_Window		*window = NULL;
	SDL_Renderer	*renderer = NULL;
	t_info colonie;

	init_colonie(&colonie);
	while (get_next_line(0, &colonie.line) && ft_strcmp("", colonie.line))
	{
		ft_check_and_add(&colonie);
		ft_strdel(&colonie.line);
	}
	create_viz(&window, &renderer, &colonie);
	get_events();

	exit_viz(renderer, window, 0);
	nettoyage_colonie(&colonie);
	return 0;
}
