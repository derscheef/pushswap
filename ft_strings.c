/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:31:44 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare_instructions(char *s1, char *s2)
{
	if (ft_strcmp(s1, "pa") == 0 && ft_strcmp(s2, "pb") == 0)
		return (1);
	else if (ft_strcmp(s1, "pb") == 0 && ft_strcmp(s2, "pa") == 0)
		return (1);
	else
		return (0);
}

void	ft_shorten_instructions(t_slist *lis)
{
	int		fakebool;
	t_slist	*tmp;

	fakebool = 1;
	while (fakebool == 1)
	{
		fakebool = 0;
		tmp = lis;
		while (tmp->next)
		{
			if (ft_compare_instructions(tmp->str, tmp->next->str))
			{
				ft_delete_node(&lis, tmp, tmp->next);
				fakebool = 1;
				break ;
			}
			else
				tmp = tmp->next;
		}
	}
}

void	ft_delete_node(t_slist **head, t_slist *del1, t_slist *del2)
{
	t_slist	*tmp;

	if (*head == del1)
	{
		*head = del2->next;
		free(del1->str);
		free(del2->str);
		free(del2);
		free(del1);
		return ;
	}
	tmp = *head;
	while (tmp->next != del1)
		tmp = tmp->next;
	tmp->next = del2->next;
	free(del1->str);
	free(del2->str);
	free(del1);
	free(del2);
}

void	ft_print_dlst(t_dlist *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->data, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}
