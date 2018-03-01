#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 14:27:35 by tlutsyk           #+#    #+#              #
#    Updated: 2018/02/11 14:27:36 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =	$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN = $(SWITCH)33m

NAME = fdf
CFILES = fdf.c list.c ft_error.c fill_struct.c draw_picture.c

OFILES = $(CFILES:.c=.o)
FOLDER = libft
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES)

$(NAME): $(OFILES)
		@make -C $(FOLDER)
		@gcc $(FLAGS) $(OFILES) -L $(FOLDER) -lft -o $(NAME) -lmlx -lm -framework OpenGL -framework AppKit
		@echo "$(STYLE_BOLD)$(COLOR_SGREEN) OK!!! FDF is READY!!!"
		@./bonus

clean:
	@/bin/rm -f $(OFILES)
	@make clean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_SGREEN) OK!!! ALL O_FILES DELETED!!!"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_RED) FDF have been deleted"

re: fclean all

.PHONY: all clean fclean