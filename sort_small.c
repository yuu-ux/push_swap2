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
	int	temp;
	int	i;
	int	min_elem;
	
	temp = 0;
	i = 1;
	// 最小値を探す
	while (i < stacka.len)
	{
		if (stacka.data[temp] > stacka.data[i])
			temp = i;
		i++;
	}
	min_elem = stacka.data[temp];
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

//void	sort_five(strhdr stacka, strhdr stackb)
//{
//
//}
//
//void	sort_six(strhdr stacka, strhdr stackb)
//{
//
//}

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
//	else if (stacka.len == 5)
//		sort_five(stacka, stackb);
//	else if (stacka.len == 6)
//		sort_six(stacka, stackb);
}
