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
			create_viz.c

SRC_LEM_IN = $(addprefix $(LEM_PATH),$(SRC_LEM))
OBJ_LEM_PATH = obj/
OBJ_LEM = $(SRC_LEM:.c=.o)
OBJ = $(addprefix $(OBJ_LEM_PATH),$(OBJ_LEM))
INCLUDES_PATH = include/
CC = clang -g
#CFLAGS = -Wall -Wextra -Werror
NAME = viz


all:
	gcc -Wall -Wextra  $(SRC_LEM_IN) -o viz -I include  -L lib -lft -lSDL2 -lSDL2_image -lSDL2_ttf
