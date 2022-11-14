/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:28:53 by sleon             #+#    #+#             */
/*   Updated: 2022/11/14 12:53:15 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// void	print_list(t_list *stack)
// {
// 	if (!stack)
// 		return ;
// 	printf("\n");
// 	while (stack)
// 	{
// 		printf("%d\n", stack->content);
// 		printf(" pack = %d\n", stack->pack);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc <= 2)
		return (0);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	*stack_a = args_to_stack(argc, argv);
	if (! *stack_a)
	{
		del_stack(stack_a);
		free(stack_b);
		free(stack_a);
		return (0);
	}
	if (argc < 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	del_stack(stack_a);
	free(stack_b);
	free(stack_a);
	return (0);
}
