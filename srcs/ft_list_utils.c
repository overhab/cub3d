#include "../include/cub3d.h"

int	ft_atoi(t_cub *cub, const char *nptr)
{
	int	d;
	int	k;

	k = 0;
	d = 1;
	space_skip(cub, nptr);
	if ((nptr[cub->index] == '+') || (nptr[cub->index] == '-'))
	{
		return (-1);
	}
	while (nptr[cub->index] >= '0' && nptr[cub->index] <= '9')
	{
		k = k * 10 + (nptr[cub->index] - '0');
		cub->index++;
		if (k > 20000)
			break ;
	}
	while (nptr[cub->index] >= '0' && nptr[cub->index] <= '9')
		cub->index++;
	return (k * d);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstadd(t_list **lst, char *line, t_cub *cub)
{
	t_list	*first;
	t_list	*new;

	if (!line)
		return (NULL);
	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (0);
	cub->begin = 1;
	new->content = ft_strdup(line);
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		first = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = first;
	}
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	d;

	d = 0;
	while (lst)
	{
		d++;
		lst = lst->next;
	}
	return (d);
}

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		(*list)->content = NULL;
		free(*list);
		*list = NULL;
		(*list) = tmp;
	}
}
