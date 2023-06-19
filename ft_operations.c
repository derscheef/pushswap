/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:36 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:20:06 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_vars *vars)
{
	t_dlist	*tmp;

	if (vars->stack_b)
	{
		tmp = vars->stack_b;
		vars->stack_b = vars->stack_b->next;
		if (vars->stack_b)
			vars->stack_b->prev = NULL;
		tmp->next = vars->stack_a;
		if (vars->stack_a)
			vars->stack_a->prev = tmp;
		vars->stack_a = tmp;
		ft_slstadd_back(&vars->instructions, ft_slstnew("pa"));
	}
}

void	ft_push_b(t_vars *vars)
{
	t_dlist	*tmp;

	if (vars->stack_a)
	{
		tmp = vars->stack_a;
		vars->stack_a = vars->stack_a->next;
		if (vars->stack_a)
			vars->stack_a->prev = NULL;
		tmp->next = vars->stack_b;
		if (vars->stack_b)
			vars->stack_b->prev = tmp;
		vars->stack_b = tmp;
		ft_slstadd_back(&vars->instructions, ft_slstnew("pb"));
	}
}

void	ft_rotate_a(t_vars *vars)
{
	t_dlist	*tmp;

	if (vars->stack_a && vars->stack_a->next)
	{
		tmp = vars->stack_a;
		vars->stack_a = vars->stack_a->next;
		vars->stack_a->prev = NULL;
		tmp->next = NULL;
		ft_dlstadd_back(&vars->stack_a, tmp);
		ft_slstadd_back(&vars->instructions, ft_slstnew("ra"));
	}
}

void	ft_reverse_rotate_a(t_vars *vars)
{
	t_dlist	*tmp;

	if (vars->stack_a && vars->stack_a->next)
	{
		tmp = vars->stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_dlstadd_front(&vars->stack_a, tmp);
		ft_slstadd_back(&vars->instructions, ft_slstnew("rra"));
	}
}

void	ft_switch_a(t_vars *vars)
{
	t_dlist	*tmp;

	if (vars->stack_a && vars->stack_a->next)
	{
		tmp = vars->stack_a;
		vars->stack_a = vars->stack_a->next;
		vars->stack_a->prev = NULL;
		tmp->next = vars->stack_a->next;
		if (tmp->next)
			tmp->next->prev = tmp;
		vars->stack_a->next = tmp;
		tmp->prev = vars->stack_a;
		ft_slstadd_back(&vars->instructions, ft_slstnew("sa"));
	}
}
