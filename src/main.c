/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 16:04:05 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 18:57:09 by nerahmou    ###    #+. /#+    ###.fr     */
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
	create_viz(&window, &renderer, &colonie);
	lseek(colonie.fd, 0, SEEK_SET);
	get_events(colonie, window, renderer);
	exit_viz(&colonie, renderer, window, 0);
	return 0;
}
