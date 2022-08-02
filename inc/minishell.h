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

typedef enum e_enum
{
	NO_SEP = 0,
	PIPE = 1,
	REDIRECT_STDIN = 2,
	REDIRECT_STDOUT = 3,
	CAT = 4,
	APPEND = 5,
}	t_enum;

# define READ 0
# define WRITE 1

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
	pid_t			pid;
	int				pipefd[2];
}				t_root;

// Env parse => t_env
int		init_env(t_root *root, char **env);
int		env_size(t_env *head);
void	free_env(t_env *head);

// Exec
t_input	*next_cmd(t_input *index);
t_input	*get_token(t_input *input);
int		is_builtin(char *cmd);
void	execute_cmd(t_root *root, t_input *cmd);
void	exe_builtin(t_root *root, char *cmd);
void	exe_generic(t_root *root, t_input *cmd);
void	ft_pipe(t_root *root, t_input *cmd);
void	reset_fd(t_root *root);

// Parsing
t_input	*parsing(char *str);
t_input	*split_to_list(char *str);
int		get_type(char *str);			//TO REMOVE : if not used
int		quoted(char *line, int index);	//TO REMOVE : if not used

// Struct function => t_input
t_input	*last_input(t_input *head);
t_input	*new_input(char *str);
void	input_add_back(t_input *list, t_input *new);
int		add_input(t_input *list, char *str);
int		input_size(t_input *head);
void	free_input(t_input *input);
void	print_input(t_input	*input);	//for debug /!\ TO REMOVE

// builtin
int		ft_env(t_env *env);

#endif
