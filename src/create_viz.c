/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_viz.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 20:18:52 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 20:43:51 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <lem_in.h>

#define W_SCREEN 1200
#define H_SCREEN 700

extern int w;
extern int h;
extern int max_x;
extern int max_y;
extern SDL_Color White;
extern SDL_Color Red;
extern SDL_Color Green;

void	create_viz(SDL_Window *window, SDL_Renderer *renderer, t_info *colonie)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_with_erro("Init", renderer, window, colonie);
	window = SDL_CreateWindow("LEM_IN", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowTitle(window, "LEM_IN");
	SDL_GetRendererOutputSize(renderer, &w, &h);
	set_background(colonie, renderer);
	set_style(colonie);
	set_nb_moves_text(colonie, renderer);
	set_options_menu(colonie, renderer);
	w -= 250;
	h -= 200;
	get_lines(colonie, window, renderer);
	get_rooms(colonie, window, renderer);
	get_ants(colonie, window, renderer);
	refresh(colonie, window, renderer);
	SDL_RenderPresent(renderer);
}
