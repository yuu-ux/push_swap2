/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:51 by yehara            #+#    #+#             */
/*   Updated: 2024/09/09 14:52:17 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	init_info(t_strhdr *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		stack->data[i].elem = 0;
		stack->data[i].index = 0;
		i++;
	}
}

void	init_strhdr(t_strhdr *stack, int len, int cap_size)
{
	stack->len = len;
	stack->cap = cap_size;
	//    init_info(stack);
}

void	init_stack(t_strhdr *stack, char **argv)
{
	check_error(argv);
	init_strhdr(stack, count_elem(argv), count_elem(argv));
	generate_stack(stack, argv);
	//    init_info(stack);
	position(stack);
}

void	free_all(char **list, t_strhdr *stacka, t_strhdr *stackb)
{
	int	i;

	i = 0;
	if (list)
	{
		while (list[i] != NULL)
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	free(stacka->data);
	free(stackb->data);
}
