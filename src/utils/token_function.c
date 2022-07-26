#include "minishell.h"

t_token	*ft_tokenlast(t_token *head)
{
	t_token	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

t_token	*ft_tokennew(char *av)
{
	t_token	*new;

	new = (t_token *) malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->av = av;
	if (!new->av)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	ft_tokenadd_back(t_token **token, t_token *new)
{
	t_token	*n;

	if (*token)
	{
		n = ft_tokenlast(*token);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*token = new;
		(*token)->next = NULL;
	}
}

int	add_token(t_token **token, char *av)
{
	t_token	*new;

	new = ft_tokennew(av, 0);
	if (!new)
		return (0);
	ft_tokenadd_back(token, new);
	return (1);
}

int	ft_token_size(t_token *head)
{
	int		i;
	t_token	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}