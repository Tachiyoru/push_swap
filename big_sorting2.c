/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:46:36 by sleon             #+#    #+#             */
/*   Updated: 2022/10/04 14:06:31 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_b_to_a3(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 3)
		tri_triple(stack_a, stack_b);
	if (size == 2)
	{
		if (((*stack_a)->content > (*stack_a)->next->content))
			swap_or_ss(stack_a, stack_b);
	}
}

int	check_b_pack(t_list **stack_b, int size)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp->next && size--)
	{
		if (tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sorting_3b(t_list **stack_a, t_list **stack_b)
{
	ft_push_ab(stack_b, stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_ab(stack_a);
	ft_push_ab(stack_b, stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_ab(stack_a);
	tri_triple(stack_a, stack_b);
	ft_push_ab(stack_b, stack_a);
	tri_triple(stack_a, stack_b);
}

void	big_sort2_2(t_list **stack_a, t_list **stack_b, int size)
{
	while (size--)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_or_ss(stack_a, stack_b);
		ft_push_ab(stack_b, stack_a);
	}
	tri_triple(stack_a, stack_b);
}

int	push_rot_ab(t_list **stack_a, t_list **stack_b, int mid, int size)
{
	int	j;
	int	i;
	int	x;

	i = 0;
	j = 0;
	x = (size / 2);
	while (size > 0 && size-- && j != x)
	{
		if ((*stack_a)->content < mid)
			j += ft_push_ab(stack_a, stack_b);
		else
			i += rot_or_rr(stack_a, stack_b);
	}
	ft_lstpack(stack_b, j);
	return (i);
}
