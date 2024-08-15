/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:33:21 by yehara            #+#    #+#             */
/*   Updated: 2024/08/14 23:39:27 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

int	check_duplicate(int *stack, int elem, int elem_num)
{
	int	i;

	i = 0;
	while (i < elem_num)
	{
		if (stack[i] == elem)
			return 0;
		i++;
	}
	return 1;
}

int	check_sorted(int *stack, int elem_num)
{
	int	i;

	i = 0;
	if (elem_num == 0)
		return 1;
	while (i < elem_num-1)
	{
		if (stack[i] > stack[i+1])
			return 1;
		i++;
	}
	return 0;
}

int	*generate_stack(char **argv, int elem_num)
{
	// 重複・ソートチェック
	strhdr	*stack;
	int	temp;
	int	i;
	i = 0;
	stack = (strhdr *)malloc(sizeof(strhdr) * elem_num);
	if (!stack)
		error_call();
	while (i < elem_num)
	{
		temp = ft_atoi(argv[i]);
		if (check_duplicate(stack->stack, temp, i))
			stack->stack[i] = temp;
		else
		{
			free(stack);
			error_call();
		}
		i++;
	}
	if (!(check_sorted(stack-stack, elem_num)))
	{

		free(stack);
		error_call();
	}
	return (stack);
}
