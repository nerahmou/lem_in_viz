/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/24 11:18:08 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 20:44:49 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef struct			s_salle t_salle;

typedef struct			s_connection
{
	t_salle				*salle;
	struct s_connection *next;
}						t_connection;

typedef struct 			s_salle
{
	int		 			index;
	char				*name;
	int					x;
	int					y;
	int					is_full;
	t_connection		*co;
	struct s_salle 		*next;
}						t_salle;

typedef struct 			s_salle_2
{
	int		 			index;
	char				*name;
	int					is_full;
	struct s_salle_2	*next;
	struct s_salle_2	*prev;
}						t_salle_2;

typedef struct			s_chemins
{
	t_salle_2			*salle;
	size_t				length;
	size_t				nb_connections;
	size_t				nb_tosend;
	struct s_chemins 	*next;
}						t_chemins;

typedef struct			s_ants
{
	char				*name;
	int					x;
	int					y;
	SDL_Texture			*texture;
	struct s_ants				*next;
}						t_ants;
typedef struct			s_info
{
	int					nb;
	int					index;
	char				*line;
	char				**line_split;
	char				*text;
	t_salle				*start;
	t_salle				*end;
	t_salle				*salle;
	t_chemins			*chemins;
	t_chemins			*chemins_un;
	t_ants				*ants;
	int					nb_moves;
	int					fd;
	FILE				*graph_file;
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
int 					ft_check_line(t_info *colonie);
void					ft_check_and_add(t_info *colonie);

int						get_room(t_info *colonie);
int						get_tubes(t_info *colonie, char *tubes);
int						get_other(t_info *colonie, char *other,
		int tab_len);
t_salle					*get_other_next(t_info *colonie);
void					*get_next_salle(void *lst);
void					*get_next_salle2(void *lst);
t_salle_2				*get_last_salle2(t_salle_2 *salle);
void					*get_next_chemin(void *lst);
t_chemins				*get_last_chemin(t_chemins *chemin);
t_salle					*get_room_by_name(t_salle *salle, char *name);
t_chemins				*get_paths(t_info *colonie);
t_salle_2 				*add_salle2(t_salle_2 *salle2, t_salle *salle);
t_salle_2 				*pop(t_salle_2 *salle);
int						find_index_salle2(t_salle_2 *salle, int index,
		int end);

void					select_path(t_info *colonie);

t_salle_2 				*dupl(t_salle_2 *dest, t_salle_2 *src);
t_salle_2 				*lstdup(t_salle_2 *salle);

void					ft_print_liaisons(t_salle *salle);
void					ft_print_list(t_info *colonie);
void					ft_print_chemins(t_chemins *chemin);
void					ft_print_chemins_rev(t_chemins *chemin);

void					free_tab(char **tab);
t_salle_2				*nettoyage_salle2(t_salle_2 *salle);
t_connection			*nettoyage_connections(t_connection *connection);
t_salle					*nettoyage_salles(t_salle *salle);
void					*nettoyage_colonie(t_info *colonie);
void					exit_error(t_info *colonie);
void					ft_error(t_info *colonie);


void	create_viz(SDL_Window **window, SDL_Renderer **renderer, t_info *colonie);
void	get_rooms(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer, TTF_Font *Style);
void	get_liaisons(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer);
void	get_ants(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer);
void	exit_with_erro(const char *str, SDL_Renderer *rend, SDL_Window *win);
#endif
