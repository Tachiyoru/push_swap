/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:46:36 by sleon             #+#    #+#             */
/*   Updated: 2022/10/06 16:05:12 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_to_b(t_list **stack_a, t_list **stack_b, int size, int mid)
{
	int		j;
	t_list	*tmp;

	j = 0;
	while (size--)
	{
		tmp = *stack_a;
		if ((check_med(stack_a, mid) == 1 || check_tri(stack_a) == 1)
			&& check_b(stack_a, stack_b) == 1)
			break ;
		else if ((*stack_a)->content < mid)
			j += ft_push_ab(stack_a, stack_b);
		else if ((*stack_a)->content >= mid)
		{
			tmp = ft_lstlast(tmp);
			if (tmp->content < mid)
			{
				rev_or_rrr(stack_a, stack_b);
				j += ft_push_ab(stack_a, stack_b);
			}
			else
				rot_or_rr(stack_a, stack_b);
		}
	}
	ft_lstpack(stack_b, j);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	sizetmp;
	int	mid;
	int	size;

	size = lst_size(stack_a);
	sizetmp = size;
	while (sizetmp > 3)
	{
		mid = ft_mid(stack_a, sizetmp);
		if (check_tri(stack_a) == 1)
			break ;
		sort_to_b(stack_a, stack_b, sizetmp, mid);
		sizetmp = size - (lst_size(stack_b));
	}
	if (sizetmp == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_or_ss(stack_a, stack_b);
		ft_push_ab(stack_b, stack_a);
	}
	len_3(stack_a);
	big_sort2(stack_a, stack_b, size);
}

void	big_sort2(t_list **stack_a, t_list **stack_b, int size)
{
	int	mid;

	mid = 0;
	while ((*stack_b))
	{
		size = lst_size_pack(stack_b, (*stack_b)->pack);
		if (size <= 2)
			big_sort2_2(stack_a, stack_b, size);
		else
		{
			if (check_b_pack(stack_b, size) == 0)
			{
				while (size--)
				{
					ft_push_ab(stack_b, stack_a);
					if ((*stack_a)->content > (*stack_a)->next->content)
						ft_swap_ab(stack_a);
				}
			}
			else
			{
				ft_b_to_a(stack_a, stack_b, mid, size);
			}
		}
	}
}

void	sorting_b_to_a(t_list **stack_a, t_list **stack_b, int mid, int size)
{
	int	i;
	int	j;
	int	x;

	mid = ft_mid(stack_b, size);
	if (size % 2 == 0)
		x = (size / 2);
	else
		x = (size / 2) + 1;
	j = 0;
	i = 0;
	if (size == 3)
	{
		sorting_3b(stack_a, stack_b);
		return ;
	}
	while (size-- && i != x)
	{
		if ((*stack_b)->content >= mid)
			i += ft_push_ab(stack_b, stack_a);
		else
			j += rot_or_rr2(stack_b, stack_a);
	}
	if (!is_last_pack(stack_b, (*stack_b)->pack))
		ft_revrot_sort4(stack_b, j);
}

void	sorting_b_to_a2(t_list **stack_a, t_list **stack_b, int mid, int size)
{
	int	i;

	size = lst_size_pack(stack_a, (*stack_a)->pack);
	if (size <= 3)
	{
		sorting_b_to_a3(stack_a, stack_b, size);
		return ;
	}
	else
	{
		mid = ft_mid(stack_a, size);
		i = push_rot_ab(stack_a, stack_b, mid, size);
		while (i--)
			rev_or_rrr(stack_a, stack_b);
		sorting_b_to_a2(stack_a, stack_b, mid, size);
	}
}
