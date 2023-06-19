/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:40 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_replace_by_index(t_dlist *stack_a, t_dlist *sorted)
{
	t_dlist	*tmp;
	int		i;

	tmp = sorted;
	while (stack_a)
	{
		i = 0;
		sorted = tmp;
		while (sorted)
		{
			if (stack_a->data == sorted->data)
			{
				stack_a->data = i;
				break ;
			}
			i++;
			sorted = sorted->next;
		}
		stack_a = stack_a->next;
	}
}

void	ft_dlst_sort(t_dlist **lst)
{
	t_dlist	*tmp;
	int		tmp_data;

	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			tmp_data = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = tmp_data;
			tmp = *lst;
		}
		else
			tmp = tmp->next;
	}
}

int	ft_get_index(t_dlist *stack_a)
{
	t_dlist	*sorted;

	sorted = 0;
	sorted = ft_copy_dlist(stack_a, sorted);
	if (!sorted)
		return (0);
	ft_dlst_sort(&sorted);
	ft_replace_by_index(stack_a, sorted);
	ft_free_dlst(sorted);
	return (1);
}

int	ft_check_sorted(t_dlist *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_radix_base2(t_vars *v)
{
	unsigned int	size;
	int				i;
	unsigned int	s;

	size = ft_dlstsize(v->stack_a);
	i = 0;
	s = 0;
	while (i < 31)
	{
		s = 0;
		while (s < size)
		{
			if (!(v->stack_a->data & (1 << i)))
				ft_push_b(v);
			else
				ft_rotate_a(v);
			s++;
		}
		while (ft_dlstsize(v->stack_b) > 0)
			ft_push_a(v);
		i++;
	}
}
