/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:51 by yehara            #+#    #+#             */
/*   Updated: 2024/08/28 23:04:09 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

// 最小値のインデックスを返す
int	ft_min(strhdr stacka)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	while (i < stacka.len)
	{
		if (stacka.data[temp].elem > stacka.data[i].elem)
			temp = i;
		i++;
	}
	return (temp);
}

// 座標圧縮
void	position(strhdr *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack->len-1)
	{
		j = i+1;
		while (j < stack->len)
		{
			if (stack->data[i].elem > stack->data[j].elem)
			{
				temp = stack->data[i].elem;
				stack->data[i].elem = stack->data[j].elem;
				stack->data[j].elem = temp;
			}
			j++;
		}
		i++;
	}
}
