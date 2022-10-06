/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:31:12 by sleon             #+#    #+#             */
/*   Updated: 2022/10/05 15:50:34 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content >= tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	delstr(char *line)
{
	if (line == NULL)
		return ;
	free(line);
	line = NULL;
}

int	ft_strcmp(char *line, char *c)
{
	size_t	i;

	i = 0;
	if (line[i] == '\0')
		return (0);
	if (c[i] == '\0')
		return (0);
	while (line[i] != '\n' || c[i] != '\0')
	{
		if (line[i] != c[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_res(t_list **stack_a, t_list **stack_b)
{
	if (stack_sorted(stack_a) == 0 && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		del_stack(stack_a);
	if (stack_b)
		del_stack(stack_b);
}

int	ft_error(char *line, t_list **stack_a, t_list **stack_b)
{
	delstr(line);
	if (stack_a)
		del_stack(stack_a);
	if (stack_b)
		del_stack(stack_b);
	write(2, "Error/n", 6);
	return (0);
}
