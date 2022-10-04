/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:31:12 by sleon             #+#    #+#             */
/*   Updated: 2022/10/04 17:19:12 by sleon            ###   ########.fr       */
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
	if (line == '\0')
		return (0);
	if (c == '\0')
		return (0);
	while (line != '\0' && c != '\0')
	{
		if (line != c)
			return (0);
		line++;
		c++;
	}
	return (1);
}

void	print_res(t_list **stack_a, t_list **stack_b)
{
	if (stack_sorted(stack_a) == 0 && !stack_b)
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
	ft_strdel(line);
	if (stack_a)
		del_stack(stack_a);
	if (stack_b)
		del_stack(stack_b);
	write(2, "Error/n", 6);
	return (0);
}
