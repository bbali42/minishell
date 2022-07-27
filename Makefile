# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 01:38:21 by bbali             #+#    #+#              #
#    Updated: 2022/07/27 19:21:27 by rbenayou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

CC		= cc

LFLAGS	= -L./libft -lft -lreadline
IFLAGS	= -I./inc -I./libft/inc
CFLAGS	= -I./inc -I./libft/inc #-g3 -fsanitize=address


SRCS	= 	./src/main/main.c \
			./src/parsing/parsing.c\
			./src/utils/split_to_list.c\
			./src/utils/node_funcions.c\
			./src/env/env.c \
					
OBJS	= $(SRCS:%.c=%.o)



$(NAME): $(OBJS) 

	@echo "$(_PURPLE_)Compiling ...$(_WHITE_)"
	@make -C libft/
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS) 
	@echo "$(_MEGAWHITE)minishell ✔️$(_WHITE_)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX)
	@make -C clean libft/
	@echo "$(_RED_)[minishell] object files deleted.$(_WHITE_)"


fclean:
	@make fclean -C libft/
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(_RED_)[minishell] binary file deleted.$(_WHITE_)"
		
re: fclean all

.PHONY: all clean fclean re

# ~~~~~~~~~~~~~~~ COLOR ~~~~~~~~~~~~~~~~~~~ #
_GREEN_=\033[0;32m
_WHITE_=\033[0;37m
_MEGAWHITE=\033[1;37m
_YELLOW_=\033[1;33m
_PURPLE_=\033[0;35m
_CYAN_=\033[1;36m
_RED_=\033[0;31m

.PHONY:		all clean fclean re
