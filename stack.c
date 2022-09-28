/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:40:35 by sleon             #+#    #+#             */
/*   Updated: 2022/09/20 15:12:17 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*new_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->pack = 0;
	node->pile = 'a';
	node->next = NULL;
	return (node);
}

void	del_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*del;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_list	*args_to_stack(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tmp;
	t_list	*last;
	int		i;

	i = 1;
	stack_a = new_node(ft_atoi(argv[i]));
	while (++i < argc)
	{
		if (check_argv(argv[i]))
		{
			write(2, "ERROR !\n", 8);
			del_stack(&stack_a);
			return (NULL);
		}
		tmp = new_node(ft_atoi(argv[i]));
		last = ft_lstlast(stack_a);
		last->pile = 'a';
		last->pack = 0;
		last->next = tmp;
	}
	if (check_double(&stack_a))
		return (write(2, "ERROR !\n", 8), NULL);
	return (stack_a);
}
