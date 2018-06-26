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

int w, h;

int max_x = 1;
int max_y = 1;

SDL_Color Color;
SDL_Color BackgroundC = {139,69,19, 0};

SDL_Color Black = {0,0,0};
SDL_Color White = {255,250,250};
SDL_Color Red = {220,20,60};
SDL_Color Green = {0, 255, 0};


void	create_viz(SDL_Window **window, SDL_Renderer **renderer, t_info *colonie)
{

/*---------------------Init window---------------------------------------------*/

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_with_erro("Init", *renderer, *window);
	*window = SDL_CreateWindow("LEM_IN",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowTitle(*window, "LEM_IN");
	SDL_GetRendererOutputSize(*renderer, &w, &h);
	SDL_Surface * image = IMG_Load("sol.jpg");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(*renderer, image);
	SDL_Rect rect = {0, 0, w, h};
	SDL_RenderCopy(*renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);

/*---------------------Init text---------------------------------------------*/

	if (TTF_Init() == -1)
		exit(ft_printf("sss"));
	TTF_Font *Sans = TTF_OpenFont("style/arial.ttf", 250);
	if (Sans == NULL)
		exit_with_erro("Style", *renderer, *window);

/*---------------------Number of moves----------------------------------------*/

	SDL_Surface *coups;
	SDL_Texture *coupsT;
	coups = TTF_RenderText_Solid(Sans, "Nombre de coups :", White);
	coupsT = SDL_CreateTextureFromSurface(*renderer, coups);
	SDL_Rect coup = {50, h - 100, 500, 50};

	SDL_RenderCopy(*renderer, coupsT, NULL, &coup);
	SDL_FreeSurface(coups);
	SDL_DestroyTexture(coupsT);
	
	SDL_Surface *coups2;
	SDL_Texture *coupsT2;
	coups2 = TTF_RenderText_Solid(Sans, ft_itoa(colonie->nb_moves), White);
	coupsT2 = SDL_CreateTextureFromSurface(*renderer, coups2);

	SDL_Rect coup2 = {coup.x+ coup.w + 10, coup.y , 50, 50};
	SDL_RenderCopy(*renderer, coupsT2, NULL, &coup2);
	SDL_FreeSurface(coups2);
	SDL_DestroyTexture(coupsT2);

	SDL_Surface *options;
	SDL_Texture *optionsT;

	options = TTF_RenderText_Solid(Sans, "[Esc : EXIT | Space : MOVE]", White);
	optionsT = SDL_CreateTextureFromSurface(*renderer, options);
	SDL_Rect option = {w / 4, 10 , 800, 50};
	SDL_RenderCopy(*renderer, optionsT, NULL, &option);
	SDL_FreeSurface(options);
	SDL_DestroyTexture(optionsT);


	w -= 250;
	h -= 200;



	get_liaisons(colonie, *window, *renderer);
	get_rooms(colonie, *window, *renderer, Sans);
	get_ants(colonie, *window, *renderer);

	SDL_RenderPresent(*renderer);
}

t_ants	*create_ant(int x, int y, t_ants *ants, int i, SDL_Renderer *renderer, SDL_Window *window)
{
	SDL_Rect rect = {(x * w) / max_x, (y * h) / max_y, 50, 50};
	t_ants	*new;
	t_ants	*tmp;
	char	*nb_tmp;

	tmp = ants;
	if (!(new = malloc(sizeof(*new))))
		exit(1);
	nb_tmp = ft_itoa(i);
	new->name = (ft_strjoin("L", nb_tmp));
	new->x = x;
	new->y = y;
	new->texture = IMG_LoadTexture(renderer, "ant.png");
	new->next = NULL;
	if (ants)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		ants = new;
	ft_strdel(&nb_tmp);
	SDL_RenderCopy(renderer, new->texture, NULL, &rect);
	return (ants);
}

void	get_ants(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	int	i;

	i = -1;
		while (++i < colonie->nb)
			colonie->ants = create_ant(colonie->start->x, 
			colonie->start->y, 
			colonie->ants, 
			i, renderer, window);
}

void	create_room(int x, int y, char *name, SDL_Renderer *renderer, SDL_Window *window, TTF_Font *Style, SDL_Color Color, int end)
{
	SDL_Surface* surface_room = NULL;
	SDL_Surface* surface_name = NULL;
	SDL_Texture* texture_room = NULL;
	SDL_Texture* texture_name = NULL;
	SDL_Rect rect_name = {(x * w) / max_x - 25, (y * h) / max_y - 100, 100, 80};
	SDL_Rect rect = {(x * w) / max_x, (y * h) / max_y, 50, 50};

	if (end)
	{
		SDL_Texture *texture = IMG_LoadTexture(renderer, "end.png");
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_DestroyTexture(texture);
	}
	else
	{
		//surface_room = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);
		//SDL_RenderDrawRect(surface_room, NULL, SDL_MapRGB(surface_room->format, Color.r, Color.g, Color.b));
		SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b ,255);
		SDL_RenderFillRect(renderer, &rect);
		texture_room = SDL_CreateTextureFromSurface(renderer, surface_room);
		SDL_RenderCopy(renderer, texture_room, NULL, &rect);
		SDL_FreeSurface(surface_room);
		SDL_DestroyTexture(texture_room);
	}
	surface_name = TTF_RenderText_Solid(Style, name, White);
	texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);

	SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);
	SDL_FreeSurface(surface_name);
	SDL_DestroyTexture(texture_name);
}

void	create_liaison(int x1, int y1, int x2, int y2, SDL_Renderer *renderer, SDL_Window *window)
{
	SDL_SetRenderDrawColor(renderer, White.r, White.g, White.b, 0);
	SDL_RenderDrawLine(renderer,
			((x1 * w) / max_x) + 25,
			((y1 * h) / max_y) + 25,
			((x2 * w) / max_x) + 25,
			((y2 * h) / max_y) + 25);
}

void	get_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer, TTF_Font *Style)
{
	t_salle	*salle;
	int		end;

	salle = colonie->salle;
	while (salle)
	{
		end = 0;
		if (salle->index == colonie->start->index)
			Color = Red;
		else if (salle->index == colonie->end->index)
			end = 1;
		else
			Color = White;
		create_room(salle->x, salle->y, salle->name, renderer, window, Style, Color, end);
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
