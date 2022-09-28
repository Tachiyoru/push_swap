/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:46:24 by sleon             #+#    #+#             */
/*   Updated: 2022/09/28 13:03:45 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_int_overflow(char *argv)
{
	if (argv[0] == '-')
	{
		if (ft_atoi(argv) > 0)
			return (1);
	}
	if (argv[0] != '-')
	{
		if (ft_atoi(argv) < 0)
			return (1);
	}
	return (0);
}

int	check_double(t_list **stack)
{
	t_list	*tmp;
	t_list	*seeker;

	tmp = *stack;
	seeker = tmp->next;
	while (tmp)
	{
		while (seeker)
		{
			if (seeker->content == tmp->content)
				return (1);
			seeker = seeker->next;
		}
		tmp = tmp->next;
		if (tmp)
			seeker = tmp->next;
	}
	return (0);
}

int	check_argv(char *argv)
{
	int		i;

	i = 0;
	if (ft_strlen(argv) > 11)
		return (1);
	if (argv[i] == '-' && !isnum(argv[i + 1]))
		return (1);
	if (argv[i] == '-' && isnum(argv[i + 1]))
		i++;
	while (argv[i])
	{
		if (!isnum(argv[i]))
			return (1);
		i++;
	}
	if (check_int_overflow(argv))
		return (1);
	return (0);
}
