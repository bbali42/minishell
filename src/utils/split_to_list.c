#include "minishell.h"

char	*ft_malloc_str(char *str, char set)
{
	char	*res;
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 1;
	while (str[i] && str[i] != set)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (str[0] == '"' || str[0] == '\'')
	{
		if (str[0] == '"')
		{
			while(str[j] && str[j+1] != '|')
			{
				j++;
				if (str[j] == '"')
					count++;
			}
		}
		else if (str[0] == '\'')
		{
			while(str[j] && str[j+1] != '|')
			{
				j++;
				if (str[j] == '\'')
					count++;
			}
		}
		while (i < j+1)
		{
			res[i] = str[i];
			i++;
		}
	}
	else
	{
		while (str[i] && str[i] != set)
		{
			res[i] = str[i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

int	split_to_list(t_parse **list, char *str, char c)
{
	t_parse	*new;	

	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			new = ft_new_node(ft_malloc_str(str, c));
			if (!new)
				return (0);
			ft_node_add_back(list, new);
			if (str[0] == '"' || str[0] == '\'')
				while(str[0] && str[1] != '|')
					str++;
			else
				while (*str && *str != c)
					str++;
		}
	}
	return (1);
}
