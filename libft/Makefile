# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:54:56 by bbali             #+#    #+#              #
#    Updated: 2022/07/01 18:14:41 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
INC			=	-I./inc

SRC			= 	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strcmp.c \
				ft_putstr.c
				
OBJ_NAME	= 	$(SRC:.c=.o)
OBJ 		=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR		=	src/
OBJ_DIR		=	.objs/


all: 			$(NAME)
							
$(NAME): 		$(OBJ)
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "[libft] compiled"
				
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:			
				@rm -rf $(OBJ_DIR)
				@echo "[libft] object files deleted"
				
fclean:			clean
				@rm -rf $(NAME)
				@echo "[libft] binary deleted"
				
re:				fclean all

.PHONY: all clean fclean re
