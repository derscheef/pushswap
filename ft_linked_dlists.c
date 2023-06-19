/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_dlists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:25 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_copy_dlist(t_dlist *stack_a, t_dlist *stack_b)
{
	t_dlist	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (!ft_dlstadd_back(&stack_b, ft_dlstnew(tmp->data)))
		{
			ft_free_dlst(stack_b);
			return (0);
		}
		tmp = tmp->next;
	}
	return (stack_b);
}

int	ft_dlstsize(t_dlist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
	return (1);
}

int	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*tmp;

	if (!new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (1);
}

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
