/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:31:12 by sleon             #+#    #+#             */
/*   Updated: 2022/11/14 14:26:30 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pschecker.h"

void	ft_stack_pile(t_list **stack_a, t_list **stack_b)
{
	(*stack_a)->pile = 'x';
	if ((*stack_b))
		(*stack_b)->pile = 'x';
	return ;
}

int	apply2(char *cmd_line, t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		return (1);
	if (ft_strcmp(cmd_line, "sb"))
		return (ft_swap_ab(stack_b));
	if (ft_strcmp(cmd_line, "ss"))
		return (ft_swap_samet2(stack_a, stack_b));
	if (ft_strcmp(cmd_line, "rb"))
		return (ft_rotate_ab(stack_b));
	if (ft_strcmp(cmd_line, "rr"))
		return (ft_rotate_samet2(stack_a, stack_b));
	if (ft_strcmp(cmd_line, "rrb"))
		return (ft_revrot_ab(stack_b));
	if (ft_strcmp(cmd_line, "rrr"))
		return (ft_revrot_samet2(stack_a, stack_b));
	if (ft_strcmp(cmd_line, "pb"))
		return (ft_push_ab(stack_a, stack_b));
	return (0);
}

int	apply(char *cmd_line, t_list **stack_a, t_list **stack_b)
{
	ft_stack_pile(stack_a, stack_b);
	if (!(*stack_a))
		return (1);
	if (ft_strcmp(cmd_line, "sa"))
		return (ft_swap_ab(stack_a));
	if (ft_strcmp(cmd_line, "ra"))
		return (ft_rotate_ab(stack_a));
	if (ft_strcmp(cmd_line, "rra"))
		return (ft_revrot_ab(stack_a));
	if (ft_strcmp(cmd_line, "pa"))
		return (ft_push_ab(stack_b, stack_a));
	if (apply2(cmd_line, stack_a, stack_b))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	*stack_a = args_to_stack(argc, argv);
	if (!(*stack_a))
	{
		del_stack(stack_a);
		return (free(stack_a), free(stack_b), 0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (!(apply(line, stack_a, stack_b)))
			return (ft_error(line, stack_a, stack_b));
		delstr(line);
		line = get_next_line(0);
	}
	print_res(stack_a, stack_b, line);
	return (0);
}
