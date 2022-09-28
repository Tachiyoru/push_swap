/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_triple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:21:00 by sleon             #+#    #+#             */
/*   Updated: 2022/09/27 17:45:01 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rot_or_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	ft_lstlast(tmp);
	if ((*stack_b) && (*stack_b)->content > tmp->content)
		ft_rotate_samet(stack_a, stack_b);
	else
		ft_rotate_ab(stack_a);
	return (1);
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

void	swap_or_ss(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->content < (*stack_b)->next->content)
		ft_swap_samet(stack_a, stack_b);
	else
		ft_swap_ab(stack_a);
}

void	rev_or_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	ft_lstlast(tmp);
	if ((*stack_b) && (*stack_b)->content > tmp->content)
		ft_revrot_samet(stack_a, stack_b);
	else
		ft_revrot_ab(stack_a);
}

void	tri_triple2(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
	{
		swap_or_ss(stack_a, stack_b);
		rot_or_rr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
		rev_or_rrr(stack_a, stack_b);
	}
	else if (((*stack_a)->content < (*stack_a)->next->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
	{
		rot_or_rr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
		rev_or_rrr(stack_a, stack_b);
	}
	else if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
	{
		swap_or_ss(stack_a, stack_b);
		rot_or_rr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
		rev_or_rrr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
	}
}

void	tri_triple(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
	{
		swap_or_ss(stack_a, stack_b);
	}
	else if (((*stack_a)->content > (*stack_a)->next->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->content))
	{
		rot_or_rr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
		rev_or_rrr(stack_a, stack_b);
		swap_or_ss(stack_a, stack_b);
	}
	else
		tri_triple2(stack_a, stack_b);
}
