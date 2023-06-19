/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:21 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_limit_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	if (ft_strlen(str + i) == 10)
	{
		if (str[i] > '2')
			return (0);
		if (str[i] == '2')
		{
			if (str[0] == '-' && ft_strcmp(str + i, "2147483648") == 0)
				return (1);
			if (ft_strcmp(str + i, "2147483647") > 0)
				return (0);
		}
	}
	return (1);
}

int	ft_check_input3(t_vars *vars)
{
	t_slist	*tmp;

	tmp = vars->input;
	while (tmp)
	{
		if (!ft_int_limit_check(tmp->str))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_input2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			return (0);
		else if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] != '\0' && str[i] != ' ')
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_input1(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_input2(av[i]))
			return (0);
		i++;
	}
	return (1);
}
