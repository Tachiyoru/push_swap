/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:57:26 by sleon             #+#    #+#             */
/*   Updated: 2022/11/14 14:26:19 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pschecker.h"

int	ft_swap_samet2(t_list **stack_a, t_list **stack_b )
{
	ft_swap_ab(stack_b);
	ft_swap_ab(stack_a);
	return (1);
}

int	ft_rotate_samet2(t_list **stack_a, t_list **stack_b )
{
	ft_rotate_ab(stack_a);
	ft_rotate_ab(stack_b);
	return (1);
}

int	ft_revrot_samet2(t_list **stack_a, t_list **stack_b)
{
	ft_revrot_ab(stack_a);
	ft_revrot_ab(stack_b);
	return (1);
}
