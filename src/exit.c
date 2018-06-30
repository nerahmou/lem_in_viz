/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:29:27 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 12:13:17 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_viz(t_info *colonie, SDL_Renderer *rend, SDL_Window *win, int sig)
{
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	nettoyage_colonie(colonie);
	SDL_Quit();
	system("rm -f moves && rm -f ../moves 2> /dev/null");
	exit(sig);
}

void	exit_with_erro(const char *str, SDL_Renderer *rend, SDL_Window *win,
															t_info *colonie)
{
	SDL_Log("Error : %s > %s\n", str, SDL_GetError());
	exit_viz(colonie, rend, win, 1);
}

void	ft_error(t_info *colonie)
{
	ft_printf("Error\n");
	nettoyage_colonie(colonie);
	exit(1);
}
