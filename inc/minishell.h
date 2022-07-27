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
#include <stdio.h>
// TO REMOVE !!!

# define NO_SEP 0
# define PIPE 1
# define REDIRECT_INPUT 2
# define REDIRECT_OUTPUT 3
# define CAT 4
# define APPEND 5

typedef struct	s_parse
{
	char			*data;
	int				type;
	struct s_parse	*prev;
	struct s_parse	*next;
}				t_parse;

typedef struct	s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct	s_root
{
	t_env			*env;
	t_parse			**parse;
	int				pid;
}				t_root;

// env_parse
int		init_env(t_root *root, char **env);
void	print_env(t_env	*env);
// exec
void	child_work(char *cmd, char *path_env, char **env);
void	exec(char *cmd, char *path_env, char **env);
char	*get_path_bin(char *cmd, char **env);
int		str_ncmp(char *str1, char *str2, int n);
int		strlen_chr(char *str, char c);
char	*str_ndup(char *str, unsigned int n);
char	**str_split(char *str, char sep);
void	free_split(char **args);
//parsing
t_parse	*ft_last_node(t_parse *head);
t_parse	*ft_new_node(char *data);
void	ft_node_add_back(t_parse **list, t_parse *new);
int		add_node(t_parse *list, char *data);
int		ft_node_size(t_parse *head);
int		split_to_list(t_parse **list, char *str, char c);
t_parse	**parsing(char *input);
int		get_type(char *str);
int		quoted(char *line, int index);
void	print_parse(t_parse	*parse);

#endif
