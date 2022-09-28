/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:46:24 by sleon             #+#    #+#             */
/*   Updated: 2022/09/28 13:04:19 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_tri(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_med(t_list **stack, int med)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content < med)
			break ;
		tmp = tmp->next;
	}
	if (tmp->content >= med && tmp->next == NULL)
		return (1);
	else
		return (0);
}

int	is_last_pack(t_list **stack_b, int pack)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->pack != pack)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}