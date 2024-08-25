#include "h_push_swap.h"

//123 -> ×(ソート済み)
//321 -> 213 (ra) -> 123 (sa)
//132 -> 213 (rra) -> 123 (sa)
//213 -> 123 (sa)
//231 -> 123 (rra)
//312 -> 123 (ra)

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

//void	sort_four(strhdr stacka, strhdr stackb)
//{
//
//}
//
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
//	else if (stacka.len == 4)
//		sort_four(stacka, stackb);
//	else if (stacka.len == 5)
//		sort_five(stacka, stackb);
//	else if (stacka.len == 6)
//		sort_six(stacka, stackb);
}
