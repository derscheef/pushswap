/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_slists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:32 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_slstlast(t_slist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_slist	*ft_slstnew(char *str)
{
	t_slist	*new;

	new = malloc(sizeof(t_slist));
	if (!new)
		return (NULL);
	new->str = ft_strtrim(str, " +");
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

int	ft_slstadd_back(t_slist **lst, t_slist *new)
{
	t_slist	*last;

	if (!lst)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	last = ft_slstlast(*lst);
	last->next = new;
	return (1);
}

void	ft_print_slst(t_slist *lst)
{
	while (lst)
	{
		if (lst->str)
			ft_putstr_fd(lst->str, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

int	ft_split_input(t_vars *vars, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i > j)
		{
			tmp = ft_substr(str, j, i - j);
			if (!ft_slstadd_back(&vars->input, ft_slstnew(tmp)))
				return (0);
			free(tmp);
		}
	}
	return (1);
}
