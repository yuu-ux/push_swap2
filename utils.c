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
		if (stacka.data[temp] > stacka.data[i])
			temp = i;
		i++;
	}
	return (temp);
}
