/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/24 11:18:08 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 10:41:43 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

typedef struct s_salle	t_salle;

typedef struct			s_connection
{
	t_salle				*salle;
	struct s_connection	*next;
}						t_connection;

struct					s_salle
{
	int					index;
	char				*name;
	int					x;
	int					y;
	int					is_full;
	t_connection		*co;
	struct s_salle		*next;
};

typedef struct			s_chemins
{
	size_t				length;
	size_t				nb_connections;
	size_t				nb_tosend;
	struct s_chemins	*next;
}						t_chemins;

typedef struct			s_room
{
	SDL_Texture			*room;
	SDL_Rect			*room_rect;
	SDL_Color			*room_color;

	SDL_Texture			*room_text_t;
	SDL_Rect			*room_text_r;
	struct s_room		*next;
}						t_room;

typedef struct			s_ants
{
	char				*name;
	SDL_Rect			*ant_rect;
	SDL_Texture			*ant_texture;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_ant_move
{
	t_ants				*ant;
	t_salle				*dest;
	bool				to_move;
	struct s_ant_move	*next;
}						t_ant_move;

typedef struct			s_line
{
	int					src_x;
	int					src_y;
	int					dst_x;
	int					dst_y;
	struct s_line		*next;
}						t_line;

typedef struct			s_info
{
	int					nb;
	int					index;
	char				*line;
	char				**line_split;
	t_salle				*start;
	t_salle				*end;
	t_salle				*salle;

	int					nb_moves;
	int					nb_moves_total;
	int					fd;

	TTF_Font			*style;

	SDL_Texture			*background;
	SDL_Rect			*bg_rect;

	SDL_Texture			*nb_moves_text;
	SDL_Rect			*nb_moves_rect;

	SDL_Texture			*options_menu_text;
	SDL_Rect			*options_menu_rect;

	t_room				*room;

	t_ants				*ants;
	SDL_Texture			*ant_image;

	t_line				*lines;
}						t_info;

void					ft_add_text(t_info *tab);
void					add_liaison(t_salle *salle, char **tab,
		int first_liaison);
t_salle					*add_salle(t_salle *colonie, char **salle,
		int index);

int						check_min(t_info *colonie);
int						check_digit(char *line);
int						duplicate_room(t_info *colonie);
int						room_exist(t_salle *salle, char *tab);
int						duplicate_liaison(t_salle *salle, char **tab);
int						ft_check_line(t_info *colonie);
void					ft_check_and_add(t_info *colonie);

int						get_room(t_info *colonie);
int						get_tubes(t_info *colonie, char *tubes);
int						get_other(t_info *colonie, char *other,
		int tab_len);
t_salle					*get_other_next(t_info *colonie);
void					*get_next_salle(void *lst);
void					*get_next_salle2(void *lst);
void					*get_next_chemin(void *lst);
t_chemins				*get_last_chemin(t_chemins *chemin);
t_salle					*get_room_by_name(t_salle *salle, char *name);
t_chemins				*get_paths(t_info *colonie);
void					select_path(t_info *colonie);

void					ft_print_liaisons(t_salle *salle);
void					ft_print_list(t_info *colonie);
void					ft_print_chemins(t_chemins *chemin);
void					ft_print_chemins_rev(t_chemins *chemin);

void					free_tab(char **tab);
void					free_multi_str(const char *str, ...);
t_connection			*nettoyage_connections(t_connection *connection);
t_salle					*nettoyage_salles(t_salle *salle);
void					*nettoyage_colonie(t_info *colonie);
void					exit_error(t_info *colonie);
void					ft_error(t_info *colonie);

void					init_colonie(t_info *colonie);
void					init_sound(t_info *colonie, SDL_Window *window,
		SDL_Renderer *rend);

void					create_viz(SDL_Window **window, SDL_Renderer **rend,
		t_info *colonie);
void					get_rooms(t_info *colonie, SDL_Window *window,
		SDL_Renderer *renderer);
void					get_lines(t_info *colonie, SDL_Window *window,
		SDL_Renderer *renderer);
void					get_ants(t_info *colonie, SDL_Window *window,
		SDL_Renderer *renderer);
t_ants					*get_ant_from_name(t_ants *ants, char *name);
void					exit_viz(t_info *colonie, SDL_Renderer *rend,
		SDL_Window *win, int sig);
void					exit_with_erro(const char *str, SDL_Renderer *rend,
		SDL_Window *win, t_info *colonie);

void					get_events(t_info colonie, SDL_Window *window,
		SDL_Renderer *renderer);
SDL_Rect				*set_rec(int x, int y, int w, int h);
void					set_text(t_info *colonie, SDL_Window *window,
		SDL_Renderer *renderer);
void					set_background_and_text_style(t_info *colonie,
		SDL_Window *window, SDL_Renderer *renderer);
void					set_options_menu(t_info *colonie, SDL_Window *window,
		SDL_Renderer *renderer);
SDL_Color				*set_color(int r, int g, int b, int a);

void					move_ants(t_info *colonie, char *str,
		SDL_Window *window, SDL_Renderer *renderer);
int						to_move(t_ant_move *ant_move);
int						check_go_over(int positive, int src, int dest,
		t_ant_move *ant_move);
t_ant_move				*init_ant_to_move(t_info *colonie,
		t_ant_move **ant_move, char *str);
t_ant_move				*push_ant_move(t_ant_move *ant_move,
		t_ants *ant, t_salle *room);
void					destroy_ant_to_move(t_ant_move **ant_move);

void					refresh(t_info *colonie, SDL_Window *window,
		SDL_Renderer *rend);
#endif
