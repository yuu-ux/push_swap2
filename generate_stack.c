/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:33:21 by yehara            #+#    #+#             */
/*   Updated: 2024/08/15 22:02:53 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

int	check_duplicate(strhdr *stack, int elem, int elem_num)
{
	int	i;

	i = 0;
	while (i < elem_num)
	{
		if (stack->data[i] == elem)
			return 0;
		i++;
	}
	return 1;
}

int	check_sorted(strhdr *stack, int elem_num)
{
	int	i;

	i = 0;
	if (elem_num == 0)
		return 1;
	while (i < elem_num-1)
	{
		if (stack->data[i] > stack->data[i+1])
			return 1;
		i++;
	}
	return 0;
}

void	generate_stack(strhdr *stack, char **argv, int elem_num)
{
	// 重複・ソートチェック
	int	temp;
	int	i;

	i = 0;
	stack->data = (int *)malloc(sizeof(int) * elem_num);
	if (!stack->data)
		error_call();
	while (i < elem_num)
	{
		temp = ft_atoi(argv[i]);
		if (check_duplicate(stack, temp, i))
			stack->data[i] = temp;
		else
		{
			free(stack->data);
			error_call();
		}
		i++;
	}
	if (!(check_sorted(stack, elem_num)))
	{

		free(stack->data);
		error_call();
	}
}