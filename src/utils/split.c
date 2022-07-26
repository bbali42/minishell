#include "minishell.h"

static	char	*ft_malloc_str(char const *str, char set)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != set)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_split(t_token **token, char *str, char c)
{
	int		i;
	t_token	*new;	

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			new = ft_tokennew(ft_malloc_str(str, c), 1);
			if (!new)
				return (0);
			ft_tokenadd_back(token, new);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (1);
}