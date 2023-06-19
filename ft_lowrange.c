/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:27:18 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:20:06 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smallest(t_dlist *stack)
{
	int	smallest;

	smallest = stack->data;
	while (stack)
	{
		if (stack->data < smallest)
			smallest = stack->data;
		stack = stack->next;
	}
	return (smallest);
}

int	ft_get_pos(t_dlist *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	ft_up_to_three(t_vars *v)
{
	int	s;
	int	b;

	if (ft_check_sorted(v->stack_a))
		return ;
	if (ft_dlstsize(v->stack_a) == 2)
	{
		ft_switch_a(v);
		return ;
	}
	s = ft_get_smallest(v->stack_a);
	b = s + 2;
	if (ft_get_pos(v->stack_a, s) == 2 && ft_get_pos(v->stack_a, b) == 1)
		ft_reverse_rotate_a(v);
	else if (ft_get_pos(v->stack_a, s) == 1 && ft_get_pos(v->stack_a, b) == 0)
		ft_rotate_a(v);
	else
		ft_switch_a(v);
	if (!ft_check_sorted(v->stack_a))
		ft_up_to_three(v);
}

void	ft_up_to_five(t_vars *v)
{
	int	target;

	target = 0;
	while (ft_dlstsize(v->stack_a) > 3 && !ft_check_sorted(v->stack_a))
	{
		if (v->stack_a->data == target)
		{
			ft_push_b(v);
			target++;
		}
		else if (ft_get_pos(v->stack_a, 0) <= ft_dlstsize(v->stack_a) / 2)
			ft_rotate_a(v);
		else
			ft_reverse_rotate_a(v);
	}
	ft_up_to_three(v);
	while (ft_dlstsize(v->stack_b) > 0)
		ft_push_a(v);
}
