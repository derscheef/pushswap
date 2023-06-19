/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_slst(t_slist *lst)
{
	t_slist	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->str)
		{
			free(tmp->str);
			tmp->str = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void	ft_free_dlst(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	ft_free_all(t_vars *vars)
{
	if (vars->stack_a)
		ft_free_dlst(vars->stack_a);
	if (vars->stack_b)
		ft_free_dlst(vars->stack_b);
	if (vars->instructions)
		ft_free_slst(vars->instructions);
	if (vars->input)
		ft_free_slst(vars->input);
	return (0);
}
