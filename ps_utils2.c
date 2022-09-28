/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:29:24 by sleon             #+#    #+#             */
/*   Updated: 2022/09/26 18:12:34 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	lst_size(t_list **stack_a)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = *stack_a;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
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
	return (tab[(size / 2)]);
}
