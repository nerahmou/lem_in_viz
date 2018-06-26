#include "lem_in.h"

extern int w;
extern int h;
extern int max_x;
extern int max_y;
extern SDL_Color White;

SDL_Rect	*set_rectangle(int x, int y, int w, int h)
{
	SDL_Rect *new;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	new->x = x;
	new->y = y;
	new->w = w;
	new->h = h;
	return (new);
}

void	set_nb_moves_text(t_info *colonie, SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	char		*text;
	char		*tmp;

	tmp = ft_itoa(colonie->nb_moves);
	text = ft_strjoin("Nombre de coups : ", tmp);
	surface = TTF_RenderText_Solid(colonie->style, text , White);
	colonie->nb_moves_rect = set_rectangle(50, h - 100, 500, 50);
	colonie->nb_moves_text = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	ft_strdel(&tmp);
	ft_strdel(&text);
}

void	set_background(t_info *colonie, SDL_Renderer *renderer)
{
	colonie->background = IMG_LoadTexture(renderer, "img/sol.jpg");
	colonie->bg_rect = set_rectangle(0, 0, w, h);
}

void	set_style(t_info *colonie)
{
	if (TTF_Init() == -1)
		exit(ft_printf("sss"));
	colonie->style = TTF_OpenFont("style/arial.ttf", 250);
	if (colonie->style == NULL)
		exit(1);
}

void	set_options_menu(t_info *colonie, SDL_Renderer *renderer)
{
	SDL_Surface *surface;

	surface = TTF_RenderText_Solid(colonie->style, "[Esc : EXIT | Space : MOVE]", White);
	colonie->options_menu_text = SDL_CreateTextureFromSurface(renderer, surface);
	colonie->options_menu_rect = set_rectangle(w / 4, 10, 800, 50);
	SDL_FreeSurface(surface);
}

SDL_Color	*set_color(int r, int g, int b, int a)
{
	SDL_Color *new;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	new->r = r;
	new->g = g;
	new->b = b;
	new->a = a;
	return (new);
}


