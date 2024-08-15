/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:33:44 by yehara            #+#    #+#             */
/*   Updated: 2024/08/15 14:21:55 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	operate_sa(strhdr stacka)
{
	int	temp;
	
	temp = stacka.data[0];
	stacka.data[0] = stacka.data[1]; 
	stacka.data[1] = temp;
}

void	operate_ra(strhdr stacka)
{
	//はじめの要素を一番うしろに持っていってすべての要素を全て一つ前にずらす。
	int	temp;
	int 	i;

	i = 0;
	temp = stacka.data[0];
	while (i < stacka.len-1)
	{
		stacka.data[i] = stacka.data[i+1];
		i++;
	}
	stacka.data[stacka.len-1] = temp;
}
//void	operate_sb()
//{
//
//}
//
//void	operate_ss()
//{
//
//}


