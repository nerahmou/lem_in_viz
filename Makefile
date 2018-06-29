# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/30 13:54:18 by befuhro      #+#   ##    ##    #+#        #
#    Updated: 2018/06/22 20:31:08 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_ICYAN=$'\x1b[46m
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m

LEM_PATH = src/

SRC_LEM =	main.c\
			checkers.c\
			getters.c\
			clears.c\
			getters_salles.c\
			adds.c\
			create_viz.c\
			create_ants.c\
			create_lines.c\
			create_room.c\
			get_events.c\
			exit.c\
			setters_viz.c\
			refresh.c\
			init.c\
			move_ants.c\
			move_ants2.c

SRC_LEM_IN = $(addprefix $(LEM_PATH),$(SRC_LEM))
OBJ_LEM_PATH = obj/
OBJ = $(addprefix $(OBJ_LEM_PATH), $(SRC_LEM:.c=.o))
INCLUDES_PATH = include/
INCLUDES_FILES = $(INCLUDES_PATH)lem_in.h
LIB_PATH = ./lib/
INC_LIBS = -l ft -l SDL2 -l SDL2main -l SDL2_test -l SDL2_image -l SDL2_mixer -l SDL2_ttf
CC = gcc -g
NAME = viz

all: $(NAME)

$(NAME): $(OBJ_LEM_PATH) $(OBJ)
	$(CC) -L $(LIB_PATH) $(INC_LIBS) $(OBJ) -I $(LIB_PATH) -o $@

$(OBJ_LEM_PATH):
	mkdir $@

$(OBJ_LEM_PATH)%.o: $(LEM_PATH)%.c $(INCLUDES_FILES)
	$(CC) -I $(INCLUDES_PATH) -I $(LIB_PATH) -o $@ -c $<

clean:
	rm -rf $(OBJ_LEM_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
