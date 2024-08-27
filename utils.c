/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:51 by yehara            #+#    #+#             */
/*   Updated: 2024/08/27 21:04:12 by yehara           ###   ########.fr       */
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
		if (stacka.data[temp] > stacka.data[i])
			temp = i;
		i++;
	}
	return (temp);
}