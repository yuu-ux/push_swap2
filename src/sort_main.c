/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:07:21 by yehara            #+#    #+#             */
/*   Updated: 2024/09/08 14:26:18 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

int	get_max_bit(t_strhdr stack)
{
	int	max;
	int	max_bits;
	int	i;

	i = 0;
	max = stack.data[0].index;
	max_bits = 0;
	while (i < stack.len)
	{
		if (stack.data[i].index > max)
			max = stack.data[i].index;
		i++;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_strhdr *stacka, t_strhdr *stackb)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	i = 0;
	max_bits = get_max_bit(*stacka);
	size = stacka->len;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((stacka->data[0].index >> i) & 1) == 1)
				operate_ra(*stacka);
			else
				operate_pb(stacka, stackb);
		}
		while (stackb->len != 0)
			operate_pa(stacka, stackb);
		i++;
	}
}
