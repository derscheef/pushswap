/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:13 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_dlist *stack_a)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_init_stack_a(t_vars *v)
{
	t_slist	*tmp;

	tmp = v->input;
	v->i = 0;
	while (tmp)
	{
		if (!ft_dlstadd_back(&(v->stack_a), ft_dlstnew(ft_atoi(tmp->str))))
			return (0);
		tmp = tmp->next;
		v->i++;
	}
	if (!ft_check_duplicates(v->stack_a))
		return (0);
	if (!ft_get_index(v->stack_a))
		return (0);
	return (1);
}

int	ft_init_input(t_vars *vars, int ac, char **av)
{
	vars->i = 1;
	while (vars->i < ac)
	{
		if (!ft_isdigit_str(av[vars->i]))
		{
			if (!ft_split_input(vars, av[vars->i]))
				return (0);
		}
		else
		{
			if (!ft_slstadd_back(&(vars->input), ft_slstnew(av[vars->i])))
				return (0);
		}
		vars->i++;
	}
	if (!ft_check_input3(vars))
		return (0);
	return (1);
}

int	ft_init_vars(t_vars *vars, int ac, char **av)
{
	vars->stack_a = NULL;
	vars->stack_b = NULL;
	vars->instructions = NULL;
	vars->input = NULL;
	if (!ft_check_input1(ac, av))
		return (0);
	if (!ft_init_input(vars, ac, av))
		return (ft_free_all(vars));
	if (!ft_init_stack_a(vars))
		return (ft_free_all(vars));
	if (ft_check_sorted(vars->stack_a))
		return (ft_free_all(vars));
	if (ft_dlstsize(vars->stack_a) <= 5)
		ft_up_to_five(vars);
	else
		ft_radix_base2(vars);
	ft_shorten_instructions(vars->instructions);
	ft_print_slst(vars->instructions);
	ft_free_all(vars);
	return (1);
}
