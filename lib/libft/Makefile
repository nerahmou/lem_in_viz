# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/06/29 20:48:09 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_ICYAN=$'\x1b[46m
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m

AR= libft.a
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
PATH_OBJ = ./objs/
PATH_SRC = ./srcs/
PATH_INC = ./includes/
INCS = $(addprefix $(PATH_INC), libft.h)
INCS += $(addprefix $(PATH_INC), ft_printf.h)


#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#

PATH_OBJ_LIB = $(PATH_OBJ)lib/
PATH_SRC_LIB = $(PATH_SRC)lib/
FILES_LIB =	ft_memchr.c\
		ft_putstr.c\
		ft_strjoin.c\
		ft_strsplit.c\
		ft_memcmp.c\
		ft_putstr_fd.c\
		ft_strlcat.c\
		ft_strstr.c \
		ft_atoi.c\
		ft_memcpy.c\
		ft_strcat.c\
		ft_strlen.c\
		ft_strsub.c\
		ft_bzero.c\
		ft_memdel.c\
		ft_strchr.c\
		ft_strmap.c\
		ft_strtrim.c\
		ft_isalnum.c\
		ft_memmove.c\
		ft_strclr.c\
		ft_strmapi.c\
		ft_tolower.c\
		ft_isalpha.c\
		ft_memset.c\
		ft_strcmp.c\
		ft_strncat.c\
		ft_toupper.c\
		ft_isascii.c\
		ft_countwords.c\
		ft_putchar.c\
		ft_strcpy.c\
		ft_strncmp.c\
		ft_isdigit.c\
		ft_putchar_fd.c\
		ft_strdel.c\
		ft_strncpy.c\
		ft_isprint.c\
		ft_ischar.c\
		ft_putendl.c\
		ft_strdup.c\
		ft_strnequ.c\
		ft_itoa.c\
		ft_putendl_fd.c\
		ft_strequ.c\
		ft_strnew.c\
		ft_memalloc.c\
		ft_putnbr.c\
		ft_putnbrendl.c\
		ft_striter.c\
		ft_strnstr.c\
		ft_memccpy.c\
		ft_putnbr_fd.c\
		ft_striteri.c\
		ft_strrchr.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_swap.c\
		ft_list_size.c\
		ft_foreach.c\
		ft_sqrt.c\
		ft_lstclear.c\
		ft_char_pos.c\
		ft_itoa_base.c\
		ft_abs.c\
		ft_atoierr.c\
		ft_putnbr_base.c\
		ft_putwchar.c\
		ft_putwstr.c\
		ft_wstrlen.c\
		ft_intlen.c\
		ft_uintlen.c\
		ft_wcharlen.c\
		ft_lstlen.c\
		ft_tablength.c\
		ft_strchr_occur.c\
		ft_double_abs.c\
		ft_free_tab.c

OBJ_LIB = $(addprefix $(PATH_OBJ_LIB), $(FILES_LIB:.c=.o))
SRC_LIB = $(addprefix $(PATH_SRC_LIB), $(FILES_LIB))


#******************************************************************************#
#                                    GNL                                   #
#******************************************************************************#


PATH_OBJ_GNL = $(PATH_OBJ)GNL/
PATH_SRC_GNL = $(PATH_SRC)GNL/
FILES_GNL = get_next_line.c

OBJ_GNL = $(addprefix $(PATH_OBJ_GNL), $(FILES_GNL:.c=.o))
SRC_GNL = $(addprefix $(PATH_SRC_GNL), $(FILES_GNL))
#******************************************************************************#
#                                    PRINT_F                                   #
#******************************************************************************#

PATH_OBJ_PRF = $(PATH_OBJ)printf/
PATH_SRC_PRF = $(PATH_SRC)printf/
FILES_PRF =	ft_printf.c\
			get_attributs.c \
			check_attributs.c \
			check_color_style.c \
			get_ret_value.c \
			print.c \
			print_s.c \
			print_ws.c \
			print_c.c \
			print_d.c \
			print_b.c \
			print_o.c \
			print_u.c \
			print_x.c \
			print_p.c \
			print_m.c \
			nbr_size.c



OBJ_PRF = $(addprefix $(PATH_OBJ_PRF), $(FILES_PRF:.c=.o))
SRC_PRF = $(addprefix $(PATH_SRC_PRF), $(FILES_PRF))

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#
PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_LIB) $(PATH_OBJ_PRF) $(PATH_OBJ_GNL)

OBJS = $(OBJ_LIB) $(OBJ_PRF) $(OBJ_GNL)

SRCS = $(SRC_LIB) $(SRC_PRF) $(OBJ_GNL)

FILES = $(FILES_LIB) $(FILES_PRF) $(FILES_GNL)

all: $(AR)

$(AR): $(PATHS_OBJ) $(OBJS) $(INCS)
	@ar rcs $(AR) $(OBJS)
	@echo "Library created 👍 \n"

$(PATHS_OBJ):
	@mkdir $@

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@echo "[$(_BOLD)$(_IRED)$(notdir $<)\033[0;0m] -> [$(_BOLD)$(_IGREEN)$(notdir $@)\033[0;0m]"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INC)
	@clear

clean:
	@rm -rf $(PATH_OBJ)
	@echo	"Clean libft O.K.\n"
	
fclean: clean
	@rm -f $(AR)
	@echo	"Fclean libft O.K.\n"

re: fclean all
