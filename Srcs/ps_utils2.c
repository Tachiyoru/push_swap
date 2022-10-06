/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:29:24 by sleon             #+#    #+#             */
/*   Updated: 2022/10/06 18:33:04 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_b_to_a(t_list **stack_a, t_list **stack_b, int mid, int size)
{
	sorting_b_to_a(stack_a, stack_b, mid, size);
	if (check_tri(stack_a) == 0)
		sorting_b_to_a2(stack_a, stack_b, mid, size);
	return ;
}

void	ft_revrot_sort4(t_list **stack_b, int j)
{
	if (j != lst_size(stack_b))
	{
		while (j-- != 0)
		{
			ft_revrot_ab(stack_b);
		}
	}
}

int	lst_size_pack(t_list **stack_a, int number)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = *stack_a;
	while (stack && stack->pack == number)
	{
		if (stack && stack->pack == number)
			i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_lstpack(t_list **stack, int j)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	i = j;
	while (i)
	{
		tmp->pack = j;
		tmp = tmp->next;
		i--;
	}
}

int	ft_mid(t_list **stack_a, int size)
{
	int		*tab;
	int		i;
	t_list	*tmp;
	int		x;

	tab = malloc(sizeof(int) * size);
	tmp = *stack_a;
	i = 0;
	while (i < size)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	x = tab[(size / 2)];
	free(tab);
	return (x);
}
