/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:48 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:20:06 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	ft_init_vars(vars, ac, av);
	free(vars);
	return (0);
}
