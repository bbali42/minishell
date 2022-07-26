#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define PIPE 3
# define REDIR 4

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
}				t_token;

typedef struct	s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct	s_root
{
	int				fdin;
	int				fdout;
	t_env			env;
}				t_root;

int	env_init(t_root *root, char **env);
// pipex
char	*get_path(char *cmd, char **env);
int		str_ncmp(char *str1, char *str2, int n);
int		strlen_chr(char *str, char c);
char	*str_ndup(char *str, unsigned int n);
char	**str_split(char *str, char sep);
void	free_split(char **args);

#endif