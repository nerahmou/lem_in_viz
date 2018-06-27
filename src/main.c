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

#include <lem_in.h>

int w;
int h;
int max_x = 1;
int max_y = 1;

SDL_Color White = {255,250,250};
SDL_Color Red = {220,20,60};
SDL_Color Green = {0, 255, 0};


void	init_colonie(t_info *colonie)
{
	colonie->nb = 0;
	colonie->index = 0;
	colonie->line = NULL;
	colonie->line_split = NULL;
	colonie->start = NULL;
	colonie->end = NULL;
	colonie->salle = NULL;
	colonie->ants = NULL;
	colonie->nb_moves = 0;
	colonie->room = NULL;
	colonie->ants = NULL;
	colonie->ant_image = NULL;
	colonie->lines = NULL;
	colonie->style = NULL;
	colonie->background = NULL;
	colonie->bg_rect = NULL;
	colonie->nb_moves_text = NULL;
	colonie->nb_moves_rect = NULL;
	colonie->options_menu_text = NULL;
	colonie->options_menu_rect = NULL;
	colonie->fd = open("moves", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (colonie->fd == -1)
		exit_with_erro("FD open", NULL, NULL, NULL);
}

int	get_colonie(t_info *colonie)
{
	while (get_next_line(0, &colonie->line) && ft_strcmp("", colonie->line))
	{
		ft_check_and_add(colonie);
		ft_strdel(&colonie->line);
	}
	return (colonie->nb);
}

void	file_puts(t_info *colonie)
{
	char	*line_tmp;

	while (get_next_line(0, &colonie->line))
	{
		colonie->nb_moves++;
		write(colonie->fd, colonie->line, ft_strlen(colonie->line));
		write(colonie->fd, "\n", 1);
		ft_strdel(&colonie->line);
	}
}

int main(int argc, char *argv[])
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_info			colonie;

	window = NULL;
	renderer = NULL;
	init_colonie(&colonie);
	if (!get_colonie(&colonie))
		ft_error(&colonie);
	file_puts(&colonie);
	renderer = create_viz(window, renderer, &colonie);
	lseek(colonie.fd, 0, SEEK_SET);
	get_events(colonie, window, renderer);
	nettoyage_colonie(&colonie);
	exit_viz(&colonie, renderer, window, 0);
	return 0;
}
