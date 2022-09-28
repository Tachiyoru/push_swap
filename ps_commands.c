/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:29:24 by sleon             #+#    #+#             */
/*   Updated: 2022/09/21 16:46:44 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_ab(t_list **stack)
{
	t_list	*tmp;
	int		temp;

	tmp = *stack;
	if (tmp && tmp->next)
	{
		temp = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = temp;
	}
	if ((*stack)->pile == 'a')
		write(1, "sa\n", 3);
	if ((*stack)->pile == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_samet(t_list **stack_a, t_list **stack_b )
{
	(*stack_a)->pile = 'x';
	(*stack_b)->pile = 'x';
	ft_swap_ab(stack_b);
	ft_swap_ab(stack_a);
	(*stack_a)->pile = 'a';
	(*stack_b)->pile = 'b';
	write(1, "ss\n", 3);
}

void	pile_chang(t_list **stack_from)
{
	if ((*stack_from)->pile == 'a')
	{
		write(1, "pb\n", 3);
		(*stack_from)->pile = 'b';
	}
	else
	{
		write(1, "pa\n", 3);
		(*stack_from)->pile = 'a';
	}
}

int	ft_push_ab(t_list **stack_from, t_list **stack_to)
{
	t_list	*to_tmp;
	t_list	*from_tmp;
	t_list	*tmp;

	pile_chang(stack_from);
	to_tmp = *stack_to;
	from_tmp = *stack_from;
	tmp = from_tmp;
	from_tmp = from_tmp->next;
	*stack_from = from_tmp;
	if (!(to_tmp))
	{
		to_tmp = tmp;
		to_tmp->next = NULL;
		*stack_to = to_tmp;
	}
	else
	{
		tmp->next = to_tmp;
		*stack_to = tmp;
	}
	return (1);
}
