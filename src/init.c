/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:17 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:29:19 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

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
	colonie->nb_moves_total = 0;
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
