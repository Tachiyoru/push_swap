/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:51:21 by sleon             #+#    #+#             */
/*   Updated: 2022/10/05 16:41:08 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	len_3_2(t_list **stack_a)
{
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
	{
		ft_rotate_ab(stack_a);
	}
	else if (((*stack_a)->content < (*stack_a)->next->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
	{
		ft_revrot_ab(stack_a);
		ft_swap_ab(stack_a);
	}
	else if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
	{
		ft_swap_ab(stack_a);
		ft_revrot_ab(stack_a);
	}
}

void	len_3(t_list **stack_a)
{
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
	{
		ft_swap_ab(stack_a);
	}
	else if (((*stack_a)->content > (*stack_a)->next->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->content))
	{
		ft_revrot_ab(stack_a);
	}
	else
		len_3_2(stack_a);
}

void	len_4(t_list **stack_a, t_list **stack_b)
{
	ft_push_ab(stack_a, stack_b);
	len_3(stack_a);
	ft_push_ab(stack_b, stack_a);
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
		ft_swap_ab(stack_a);
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content > (*stack_a)->next->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->next->content))
	{
		ft_revrot_ab(stack_a);
		ft_swap_ab(stack_a);
		ft_rotate_ab(stack_a);
		ft_rotate_ab(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->next->next->content)
	{
		ft_rotate_ab(stack_a);
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lst_size(stack_a);
	if (check_tri(stack_a) == 1)
		return ;
	if (size == 1)
		return ;
	if (size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		ft_swap_ab(stack_a);
	if (size == 3)
		len_3(stack_a);
	if (size == 4)
		len_4(stack_a, stack_b);
	return ;
}
