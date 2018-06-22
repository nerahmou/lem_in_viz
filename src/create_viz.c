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

#define R 177
#define G 147
#define B 108

int max_x = 1;
int max_y = 1;

SDL_Color Color;
SDL_Color White = {255, 255, 255};
SDL_Color Black = {0, 0, 0};
SDL_Color Red = {255, 0, 0};
SDL_Color Green = {0, 255, 0};


void	create_viz(SDL_Window **window, SDL_Renderer **renderer, t_info *colonie)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_with_erro("Init", *renderer, *window);
	if (SDL_CreateWindowAndRenderer(0, 0, 0, window, renderer))
		exit_with_erro("Creation", *renderer, *window);
	if (0 != SDL_SetRenderDrawColor(*renderer, R, G, B, 0))
		exit_with_erro("color", *renderer, *window);
	if (0 != SDL_RenderClear(*renderer))
		exit_with_erro("clear", *renderer, *window);
	SDL_SetWindowTitle(*window, "LEM_IN");
	SDL_SetWindowFullscreen(*window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	
	TTF_Init();
	TTF_Font* Sans = TTF_OpenFont("../style/arial.ttf", 250);
	if (Sans == NULL)
		exit_with_erro("Style", *renderer, *window);

	get_rooms(colonie, *window, *renderer, Sans);
	get_liaisons(colonie, *window, *renderer);
}

void	create_room(int x, int y, char *name, SDL_Renderer *renderer, SDL_Window *window, TTF_Font *Style, SDL_Color Color)
{
	SDL_Surface* surface_name = TTF_RenderText_Solid(Style, name, Black);
	SDL_Surface *surface_room = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);

	SDL_FillRect(surface_room, NULL, SDL_MapRGB(surface_room->format, Color.r, Color.g, Color.b));

	SDL_Texture* texture_room = SDL_CreateTextureFromSurface(renderer, surface_room); 
	SDL_Texture* texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
	
	SDL_Rect rect_name = {
		(x * 2200) / max_x - 25,
		(y * 1000) / max_y - 100
			, 100
			, 80};
	
	SDL_Rect rect_room = {
		(x * 2200) / max_x,
		(y * 1000) / max_y,
		50,
		50};

	SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);
	SDL_RenderCopy(renderer, texture_room, NULL, &rect_room);

	SDL_DestroyTexture(texture_room);
	SDL_DestroyTexture(texture_name);
	SDL_FreeSurface(surface_room);
	SDL_FreeSurface(surface_name);
}

void	create_liaison(int x1, int y1, int x2, int y2, SDL_Renderer *renderer, SDL_Window *window)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawLine(renderer,
			((x1 * 2200) / max_x) + 25,
			((y1 * 1000) / max_y) + 25,
			((x2 * 2200) / max_x) + 25,
			((y2 * 1000) / max_y) + 25);
}

void	get_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer, TTF_Font *Style)
{
	t_salle	*salle;
	salle = colonie->salle;
	
	while (salle)
	{
		if (salle->index == colonie->start->index)
			Color = Red;
		else if (salle->index == colonie->end->index)
			Color = Green;
		else
			Color = White;
		create_room(salle->x, salle->y, salle->name, renderer, window, Style, Color);
		salle = salle->next;
	}
}

void	get_liaisons(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	t_salle	*salle;
	t_connection *co;

	salle = colonie->salle;
	while (salle)
	{
		co = salle->co;
		while (co)
		{
			create_liaison(salle->x, salle->y, co->salle->x, co->salle->y, renderer, window);
			co = co->next;
		}
		salle = salle->next;
	}
}
