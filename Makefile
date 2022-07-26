# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 01:38:21 by bbali             #+#    #+#              #
#    Updated: 2022/06/25 01:38:21 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -I ./inc/ -I ./libft/inc
LIB			=	-L ./libft -lft -lreadline

EXEC		=	pipex main

SRC			=	$(addsuffix .c, $(addprefix src/main/, $(EXEC))) 


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
OBJ_DIR		=	.objs/

# ~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~ #
all: $(NAME)

$(NAME):	$(OBJ)
			@make -C libft/
			@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
			@echo "$(_MEGAWHITE)Done ✔️$(_WHITE_)"

$(OBJ_DIR)%.o: %.c
				@echo "$(_PURPLE_)Compiling ...$(_WHITE_)"
				@echo "$(_YELLOW_)$@$(_WHITE_)\r"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $< 

clean:		
			@echo "$(_RED_)Deleting object files ...$(_WHITE_)"
			@make clean -C libft/
			@rm -rf $(OBJ_DIR)

fclean:
			@make clean
			@echo "$(_RED_)Deleting executable ...$(_WHITE_)"
			@make fclean -C libft/
			@rm -rf $(NAME)

re:			fclean all

# ~~~~~~~~~~~~~~~ COLOR ~~~~~~~~~~~~~~~~~~~ #
_GREEN_=\033[0;32m
_WHITE_=\033[0;37m
_MEGAWHITE=\033[1;37m
_YELLOW_=\033[1;33m
_PURPLE_=\033[0;35m
_CYAN_=\033[1;36m
_RED_=\033[0;31m

.PHONY:		all clean fclean re bonus install fclean-install re-install