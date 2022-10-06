/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:29:24 by sleon             #+#    #+#             */
/*   Updated: 2022/10/06 18:32:57 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_rotate_ab(t_list **stack)
{
	t_list	*last;
	t_list	*frst_to_lst;
	t_list	*tmp;

	if ((*stack)->pile == 'a')
		write(1, "ra\n", 3);
	else if ((*stack)->pile == 'b')
		write(1, "rb\n", 3);
	tmp = *stack;
	if (!(tmp && tmp->next))
		return (0);
	frst_to_lst = tmp;
	tmp = tmp->next;
	last = tmp;
	while (last ->next)
		last = last->next;
	last->next = frst_to_lst;
	frst_to_lst->next = NULL;
	*stack = tmp;
	return (1);
}

void	ft_rotate_samet(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	(*stack_a)->pile = 'x';
	(*stack_b)->pile = 'x';
	ft_rotate_ab(stack_a);
	ft_rotate_ab(stack_b);
	tmp = ft_lstlast(*stack_a);
	tmp->pile = 'a';
	tmp = ft_lstlast(*stack_a);
	tmp->pile = 'b';
	write(1, "rr\n", 3);
}

int	ft_revrot_ab(t_list **stack)
{
	t_list	*scndlst_to_lst;
	t_list	*tmp;
	t_list	*last;

	if ((*stack)->pile == 'a')
		write(1, "rra\n", 4);
	else if ((*stack)->pile == 'b')
		write(1, "rrb\n", 4);
	tmp = *stack;
	if (!(tmp && tmp->next))
		return (0);
	last = tmp;
	while (last->next)
		last = last->next;
	scndlst_to_lst = *stack;
	while (scndlst_to_lst->next->next != NULL)
		scndlst_to_lst = scndlst_to_lst->next;
	scndlst_to_lst->next = NULL;
	last->next = tmp;
	*stack = last;
	return (1);
}

void	ft_revrot_samet(t_list **stack_a, t_list **stack_b)
{
	(*stack_a)->pile = 'x';
	(*stack_b)->pile = 'x';
	ft_revrot_ab(stack_a);
	ft_revrot_ab(stack_b);
	(*stack_a)->pile = 'a';
	(*stack_b)->pile = 'b';
	write(1, "rrr\n", 4);
}

int	rot_or_rr2(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	ft_lstlast(tmp);
	if ((*stack_a) && (*stack_a)->content < tmp->content)
		ft_rotate_samet(stack_a, stack_b);
	else
		ft_rotate_ab(stack_b);
	return (1);
}
