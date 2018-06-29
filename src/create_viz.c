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

void	create_viz(SDL_Window **window, SDL_Renderer **rend, t_info *colonie)
{
	int result = 0;
    int flags = MIX_INIT_MP3;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		exit_with_erro("Init", *rend, *window, colonie);
	if (!(*window = SDL_CreateWindow("LEM_IN", SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED, 640, 480,
										SDL_WINDOW_FULLSCREEN_DESKTOP)))
		exit_with_erro("Create window", *rend, *window, colonie);
	if (!(*rend = SDL_CreateRenderer(*window, -1,
										SDL_RENDERER_ACCELERATED)))
		exit_with_erro("Create rend", *rend, *window, colonie);
	SDL_SetWindowTitle(*window, "LEM_IN");
	SDL_GetRendererOutputSize(*rend, &w, &h);
	set_background_and_text_style(colonie, *window, *rend);
	set_text(colonie, *window, *rend);
	set_options_menu(colonie, *window, *rend);
	w -= (w / 4);
	h -= (h / 4);
	get_lines(colonie, *window, *rend);
	get_rooms(colonie, *window, *rend);
	get_ants(colonie, *window, *rend);
	refresh(colonie, *window, *rend);
}
