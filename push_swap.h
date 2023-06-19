/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:03:37 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 15:27:08 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	int				i;
	struct s_dlist	*stack_a;
	struct s_dlist	*stack_b;
	struct s_slist	*instructions;
	struct s_slist	*input;

}					t_vars;

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;

}					t_dlist;

typedef struct s_slist
{
	char			*str;
	struct s_slist	*next;

}					t_slist;

t_slist				*ft_slstnew(char *str);
int					ft_slstadd_back(t_slist **lst, t_slist *new);
void				ft_print_slst(t_slist *lst);
t_slist				*ft_slstlast(t_slist *lst);
int					ft_split_input(t_vars *vars, char *str);

t_dlist				*ft_dlstnew(int data);
int					ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int					ft_dlstadd_front(t_dlist **lst, t_dlist *new);
int					ft_dlstsize(t_dlist *lst);
t_dlist				*ft_copy_dlist(t_dlist *stack_a, t_dlist *stack_b);

int					ft_isdigit_str(char *str);
int					ft_int_limit_check(char *str);
int					ft_check_input1(int ac, char **av);
int					ft_check_input2(char *str);
int					ft_check_input3(t_vars *vars);

int					ft_init_input(t_vars *vars, int ac, char **av);
int					ft_init_vars(t_vars *vars, int ac, char **av);
int					ft_check_duplicates(t_dlist *stack_a);
int					ft_init_stack_a(t_vars *vars);

void				ft_free_slst(t_slist *lst);
void				ft_free_dlst(t_dlist *lst);
int					ft_free_all(t_vars *vars);
void				ft_replace_by_index(t_dlist *stack_a, t_dlist *sorted);
void				ft_dlst_sort(t_dlist **lst);
int					ft_get_index(t_dlist *stack_a);
void				ft_radix_base2(t_vars *v);
int					ft_check_sorted(t_dlist *stack);
int					ft_compare_instructions(char *s1, char *s2);
void				ft_shorten_instructions(t_slist *lis);
void				ft_delete_node(t_slist **head, t_slist *del1,
						t_slist *del2);
void				ft_print_dlst(t_dlist *lst);
void				ft_rotate_a(t_vars *vars);
void				ft_reverse_rotate_a(t_vars *vars);
void				ft_push_a(t_vars *vars);
void				ft_push_b(t_vars *vars);
void				ft_switch_a(t_vars *vars);
void				ft_up_to_five(t_vars *v);
void				ft_up_to_three(t_vars *v);
int					ft_get_smallest(t_dlist *stack);
int					ft_get_pos(t_dlist *stack, int target);

#endif
