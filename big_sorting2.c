/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:46:36 by sleon             #+#    #+#             */
/*   Updated: 2022/09/27 18:08:05 by sleon            ###   ########.fr       */
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
