/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:43 by yehara            #+#    #+#             */
/*   Updated: 2024/09/01 13:07:09 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	sort_three(t_strhdr stacka)
{
	int	first;
	int	second;
	int	third;

	first = stacka.data[0].elem;
	second = stacka.data[1].elem;
	third = stacka.data[2].elem;
	if ((first > second) && (second > third))
	{
		operate_ra(stacka);
		operate_sa(stacka);
	}
	else if ((first < second) && (second > third) && (first < third))
	{
		operate_rra(stacka);
		operate_sa(stacka);
	}
	else if ((first > second) && (second < third) && (first < third))
		operate_sa(stacka);
	else if ((first < second) && (second > third))
		operate_rra(stacka);
	else if ((first > second) && (second < third))
		operate_ra(stacka);
}

void	sort_four(t_strhdr stacka, t_strhdr stackb)
{
	while (stacka.data[0].index != 0)
		operate_rra(stacka);
	operate_pb(&stacka, &stackb);
	sort_three(stacka);
	operate_pa(&stacka, &stackb);
}

void	sort_five(t_strhdr stacka, t_strhdr stackb)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stacka.data[1].index == i)
			operate_ra(stacka);
		else if (stacka.data[2].index == i)
		{
			operate_ra(stacka);
			operate_ra(stacka);
		}
		else
		{
			while (stacka.data[0].index != i)
				operate_rra(stacka);
		}
		operate_pb(&stacka, &stackb);
		i++;
	}
	sort_three(stacka);
	i = 0;
	while (i++ < 2)
		operate_pa(&stacka, &stackb);
}

void	sort_small(t_strhdr stacka, t_strhdr stackb)
{
	(void)stackb;
	if (stacka.len == 2)
	{
		if (stacka.data[0].elem > stacka.data[1].elem)
			operate_sa(stacka);
	}
	if (stacka.len == 3)
		sort_three(stacka);
	else if (stacka.len == 4)
		sort_four(stacka, stackb);
	else if (stacka.len == 5)
		sort_five(stacka, stackb);
}
