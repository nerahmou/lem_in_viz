#include "lem_in.h"

void	exit_viz(t_info *colonie, SDL_Renderer *rend, SDL_Window *win, int signal)
{
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	nettoyage_colonie(colonie);
	SDL_Quit();
	exit(signal);
}

void	exit_with_erro(const char *str, SDL_Renderer *rend, SDL_Window *win, t_info *colonie)
{
	SDL_Log("Error : %s > %s\n", str, SDL_GetError());
	exit_viz(colonie, rend, win, 1);
}

void		ft_error(t_info *colonie)
{
	ft_printf("Error\n");
	nettoyage_colonie(colonie);
	exit(1);
}
