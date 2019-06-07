# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/27 18:24:40 by fcottet           #+#    #+#              #
#    Updated: 2019/06/03 14:52:18 by temehenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rt
CC=gcc
LIBFTDIR= ./libft
SRCDIR = src
OBJDIR = obj
FLAGS= -Wall -Wextra -Werror -O2
SRCFILE = core/main.c\
		  core/closestObj.c\
		  core/init_var.c\
		  core/print_bar.c\
		  core/loadObj.c\
		  core/raytracer.c\
		  core/texture.c\
		  core/texture2.c\
		  core/perlin.c\
		  core/shaders.c\
		  light/diffuseColor.c\
		  light/getColor.c\
		  light/reflection.c\
		  math_tool/basicMatrix.c\
		  math_tool/transMatrix.c\
		  math_tool/transMatrix2.c\
		  math_tool/quadric.c\
		  math_tool/interQuadric.c\
		  math_tool/vector.c\
		  math_tool/calPoint.c\
		  math_tool/resolve.c\
		  math_tool/resolv4.c\
		  math_tool/inter_tore.c\
		  mlx_func/event.c\
		  mlx_func/light_pixel.c\
		  parser/check_scene.c\
		  parser/check_obj.c\
		  parser/error.c\
		  parser/free_func.c\
		  parser/get_obj.c\
		  parser/obj.c\
		  parser/parse.c\
		  parser/parser_util_func.c\
		  parser/parser_util_func2.c\
		  parser/quit_all.c\
		  parser/read_file.c\
		  parser/check_error_parse.c\
		  parser/light_parse.c\
		  parser/material.c\

SRC = $(addprefix $(SRCDIR), $(SRCFILE))

OBJFILE = $(SRCFILE:.c=.o)

OBJ = $(addprefix $(OBJDIR)/,$(OBJFILE))

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) -g $(FLAGS) -o $@ -c $< -I include/ -I $(LIBFTDIR)
	@echo "File compiled : " $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -g -o $(NAME) $(OBJ) -I libft/ ./libft/libft.a -lmlx -framework AppKit -framework OpenGL #-lXext -lX11 -lm#
	@echo "\033[32mCompilation SUCCEED. Binary created :\033[32;1m" $@

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@mkdir $@
	@make -C libft/
	@mkdir -p obj/core/
	@mkdir -p obj/math_tool/
	@mkdir -p obj/light/
	@mkdir -p obj/mlx_func/
	@mkdir -p obj/parser/

clean:
	@make -C libft/ clean
	@rm -rf $(OBJDIR)
	@echo "\033[36mObjects have been deleted.\033[00m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[36m"$(NAME) "have been deleted.\033[00m"

re: fclean all

.PHONY: all clean fclean re
