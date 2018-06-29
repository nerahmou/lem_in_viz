#include "lem_in.h"

void	init_colonie(t_info *colonie)
{
	colonie->nb = 0;
	colonie->index = 0;
	colonie->line = NULL;
	colonie->line_split = NULL;
	colonie->start = NULL;
	colonie->end = NULL;
	colonie->salle = NULL;
	colonie->ants = NULL;
	colonie->nb_moves = 0;
	colonie->room = NULL;
	colonie->ants = NULL;
	colonie->ant_image = NULL;
	colonie->lines = NULL;
	colonie->style = NULL;
	colonie->background = NULL;
	colonie->bg_rect = NULL;
	colonie->nb_moves_text = NULL;
	colonie->nb_moves_rect = NULL;
	colonie->options_menu_text = NULL;
	colonie->options_menu_rect = NULL;
	colonie->fd = open("moves", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (colonie->fd == -1)
		exit_with_erro("FD open", NULL, NULL, NULL);
}

void	init_sound(t_info *colonie, SDL_Window *window, SDL_Renderer *renderer)
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
		exit_with_erro("Init SOUND", renderer, window, colonie);
	Mix_AllocateChannels(2);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
		exit_with_erro("Init SOUND", renderer, window, colonie);
	colonie->sound = Mix_LoadWAV("audio/ryu.wav");
	if (!colonie->sound)
		exit_with_erro("Load WAV ", renderer, window, colonie);
}
