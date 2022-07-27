#include "minishell.h"

t_parse	*ft_last_node(t_parse *head)
{
	t_parse	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

t_parse	*ft_new_node(char *data)
{
	t_parse	*new;

	new = (t_parse *) malloc(sizeof(t_parse));
	if (!new)
		return (NULL);
	new->data = data;
	if (!new->data)
	{
		free(new);
		return (NULL);
	}
	new->type = 0;
	new->next = NULL;
	return (new);
}

void	ft_node_add_back(t_parse **list, t_parse *new)
{
	t_parse	*n;

	if (*list)
	{
		n = ft_last_node(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	add_node(t_parse **list, char *data)
{
	t_parse	*new;

	new = ft_new_node(data);
	if (!new)
		return (0);
	ft_node_add_back(list, new);
	return (1);
}

int	ft_node_size(t_parse *head)
{
	int		i;
	t_parse	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
