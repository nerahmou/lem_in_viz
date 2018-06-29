#include "lem_in.h"

extern int w;
extern int h;
extern int max_x;
extern int max_y;
extern SDL_Color White;

SDL_Rect	*set_rec(int x, int y, int w, int h)
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

void	set_text(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	char		*text;
	char		*tmp;
	char		*tmp2;

	tmp = ft_itoa(colonie->nb_moves);
	text = ft_strjoin("Nombre de coups : ", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(colonie->nb);
	tmp2 = ft_strjoin(" | Nombre de fourmis : ", tmp);
	ft_strdel(&tmp);
	tmp = text;
	text = ft_strjoin(text, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	surface = TTF_RenderText_Solid(colonie->style, text , White);
	if (!surface)
		exit_with_erro("Text surface", renderer, window, colonie);
	colonie->nb_moves_rect = set_rec(30, h - 70, 600, 50);
	colonie->nb_moves_text = SDL_CreateTextureFromSurface(renderer, surface);
	if (!colonie->nb_moves_text)
		exit_with_erro("Text texture", renderer, window, colonie);
	SDL_FreeSurface(surface);
	ft_strdel(&text);
}

void	set_background_and_text_style(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	colonie->background = IMG_LoadTexture(renderer, "img/sol.jpg");
	if (!colonie->background)
		exit_with_erro("Background image", renderer, window, colonie);
	colonie->bg_rect = set_rec(0, 0, w, h);
	if (TTF_Init() == -1)
		exit_with_erro("Init style", renderer, window, colonie);
	colonie->style = TTF_OpenFont("style/arial.ttf", 250);
	if (!colonie->style)
		exit_with_erro("Open style", renderer, window, colonie);
}

void	set_options_menu(t_info *colonie, SDL_Window *window,  SDL_Renderer *renderer)
{
	SDL_Surface *surface;

	surface = TTF_RenderText_Solid(colonie->style, "[Esc : EXIT | Space : MOVE]", White);
	if (!surface)
		exit_with_erro("Options surface", renderer, window, colonie);
	colonie->options_menu_text = SDL_CreateTextureFromSurface(renderer, surface);
	if (!colonie->options_menu_text)
		exit_with_erro("Options texture", renderer, window, colonie);
	colonie->options_menu_rect = set_rec(w / 4, 10, 800, 50);
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


