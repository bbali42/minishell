/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:32:08 by bbali             #+#    #+#             */
/*   Updated: 2022/07/28 22:32:08 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

// TO REMOVE !!!
# include <stdio.h>
// TO REMOVE !!!

# define NO_SEP 0
# define PIPE 1
# define REDIRECT_INPUT 2
# define REDIRECT_OUTPUT 3
# define CAT 4
# define APPEND 5

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_input
{
	char			*input;
	int				type;
	struct s_input	*prev;
	struct s_input	*next;
}				t_input;

typedef struct s_root
{
	t_env			*env;
}				t_root;

// env_parse
int		init_env(t_root *root, char **env);
int		env_size(t_env *head);

// exec
int		is_builtin(char *cmd);
void	exe_builtin(t_root *root, char *cmd);
t_input	*next_cmd(t_input *input);
t_input	*next_token(t_input *input);
void	exe_generic(t_root *root, t_input *cmd);

// Parsing
t_input	*parsing(char *str);
t_input	*split_to_list(char *str);
int		get_type(char *str);
int		quoted(char *line, int index);
void	print_input(t_input	*parse);

// Struct function => t_input
t_input	*last_input(t_input *head);
t_input	*new_input(char *str);
void	input_add_back(t_input *list, t_input *new);
int		add_input(t_input *list, char *str);
int		input_size(t_input *head);
void	print_input(t_input	*input);

// builtin
int		ft_env(t_env *env);

#endif
