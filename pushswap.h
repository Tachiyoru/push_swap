/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:29:07 by sleon             #+#    #+#             */
/*   Updated: 2022/09/28 13:04:52 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				pack;
	char			pile;
	struct s_list	*next;
}					t_list;

// pushswap
void	print_list(t_list *stack);
int		main(int argc, char **argv);

// ps_comands
void	ft_swap_ab(t_list **stack);
void	ft_swap_samet(t_list **stack_a, t_list **stack_b);
void	pile_chang(t_list **stack_from);
int		ft_push_ab(t_list **stack_from, t_list **stack_to);

// ps_commands2
int		ft_rotate_ab(t_list **stack);
void	ft_rotate_samet(t_list **stack_a, t_list **stack_b);
int		ft_revrot_ab(t_list **stack);
void	ft_revrot_samet(t_list **stack_a, t_list **stack_b);

// ps_utils
void	ft_sort_int_tab(int *tab, int size);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		isnum(char str);

// ps_utils_2
void	ft_revrot_sort4(t_list **stack_b, int j);
int		lst_size(t_list **stack_a);
int		lst_size_pack(t_list **stack_a, int number);
void	ft_lstpack(t_list **stack, int j);
int		ft_mid(t_list **stack_a, int size);
// check
int		check_tri(t_list **stack);
int		check_med(t_list **stack, int med);
int		is_last_pack(t_list **stack_b, int pack);

// error_check
int		check_int_overflow(char *argv);
int		check_double(t_list **stack);
int		check_argv(char *argv);

// stack
t_list	*new_node(int content);
void	del_stack(t_list **stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*args_to_stack(int argc, char **argv);

// tri_triple
int		rot_or_rr2(t_list **stack_b, t_list **stack_a);
int		rot_or_rr(t_list **stack_a, t_list **stack_b);
void	swap_or_ss(t_list **stack_a, t_list **stack_b);
void	rev_or_rrr(t_list **stack_a, t_list **stack_b);
void	tri_triple2(t_list **stack_a, t_list **stack_b);
void	tri_triple(t_list **stack_a, t_list **stack_b);

// big_sorting
void	sorting_b_to_a(t_list **stack_a, t_list **stack_b, int mid, int size);
void	sorting_b_to_a2(t_list **stack_a, t_list **stack_b, int mid, int z);
void	sort_to_b(t_list **stack_a, t_list **stack_b, int size, int mid);
void	big_sort2(t_list **stack_a, t_list **stack_b, int size);
void	big_sort(t_list **stack_a, t_list **stack_b);

// big_sorting2
void	sorting_b_to_a3(t_list **stack_a, t_list **stack_b, int size);
int		check_b_pack(t_list **stack_b, int size);

// sorting
void	len_3_2(t_list **stack_a);
void	len_3(t_list **stack_a);
void	len_4(t_list **stack_a, t_list **stack_b);
void	small_sort(t_list **stack_a, t_list **stack_b);

#endif