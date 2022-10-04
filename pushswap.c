/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:28:53 by sleon             #+#    #+#             */
/*   Updated: 2022/10/04 12:19:05 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
// printf("les listes a la fin de tout : \n");
// print_list(*stack_a);
// printf("stack b : \n");
// print_list(*stack_b);

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
		return (0);
	if (argc < 6)
	{
		small_sort(stack_a, stack_b);
		del_stack(stack_a);
		return (0);
	}
	else
		big_sort(stack_a, stack_b);
	del_stack(stack_a);
	free(stack_b);
	free(stack_a);
	return (0);
}
