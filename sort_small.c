/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:43 by yehara            #+#    #+#             */
/*   Updated: 2024/08/27 21:04:12 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	sort_three(strhdr stacka)
{
	int	first;
	int	second;
	int	third;

	first = stacka.data[0];
	second = stacka.data[1];
	third = stacka.data[2];
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

// 最小値の要素のみスタックBに移動し、それ以外の要素は3個のパターンのソートに流す
void	sort_four(strhdr stacka, strhdr stackb)
{
	int	min_index;
	int	min_elem;
	
	// 最小値を探す
	min_index = ft_min(stacka);
	min_elem = stacka.data[min_index];
	// 最小値と一致するまでraする
	while (min_elem != stacka.data[0])
		operate_ra(stacka);
	// 先頭要素をスタックbに送る
	operate_pb(&stacka, &stackb);
	// それ以外の数字を3個のパターンのソートでソートする
	sort_three(stacka);
	// スタックbの要素をスタックaに戻す
	operate_pa(&stacka, &stackb);
}

// 最小値と2番めに小さい要素をスタックBに移動し、その他の値をsort_threeでソートする
void	sort_five(strhdr stacka, strhdr stackb)
{
	int	min_index;
	int	min_elem;
	int	i;

	i = 0;
	// 最小値と2番めに小さい値をpbする
	while (i < 2)
	{
		min_index = ft_min(stacka);
		min_elem = stacka.data[min_index];
		// 最小値と一致するまでraする
		while (min_elem != stacka.data[0])
			operate_ra(stacka);
		// 先頭要素をスタックbに送る
		operate_pb(&stacka, &stackb);
		i++;
	}
	// それ以外の数字を3個のパターンのソートでソートする
	sort_three(stacka);
	i = 0;
	while (i < 2)
	{
		// スタックbの要素をスタックaに戻す
		operate_pa(&stacka, &stackb);
		i++;
	}
}

void	sort_small(strhdr stacka, strhdr stackb)
{
	(void)stackb;
	if (stacka.len == 2)
	{
		if (stacka.data[0] > stacka.data[1])
			operate_sa(stacka);
	}
	if (stacka.len == 3)
		sort_three(stacka);
	else if (stacka.len == 4)
		sort_four(stacka, stackb);
	else if (stacka.len == 5)
		sort_five(stacka, stackb);
}
