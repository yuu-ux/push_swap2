/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:33:44 by yehara            #+#    #+#             */
/*   Updated: 2024/08/25 22:56:09 by yehara           ###   ########.fr       */
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

//はじめの要素を一番うしろに持っていってすべての要素を全て一つ前にずらす。
void	operate_ra(strhdr stacka)
{
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

// 一番最後の要素を一番前に持ってきて、すべての要素をすべて後ろにずらす
void	operate_rra(strhdr stacka)
{
	int	temp;
	int	end;
	
	end = (stacka.len - 1);
	temp = stacka.data[end];
	while (end > 0)
	{
		stacka.data[end] = stacka.data[end - 1];
		end--;
	}
	stacka.data[0] = temp;
}
// capの制限とスタックに何も値が入ってないときの処理を含めないといけない
void	operate_pa(strhdr *stacka, strhdr *stackb)
{
	int	end;
	int	i;

	i = 0;
	end = stacka->len;
	if (stackb->data == NULL)
		return ;
	if (end == stacka->cap)
		return ;
	while (0 < end)
	{
		stacka->data[end] = stacka->data[end-1];
		end--;
	}
	stacka->data[0] = stackb->data[0];
	while (i < stackb->len-1)
	{
		stackb->data[i] = stackb->data[i+1];
		i++;
	}
	stackb->len--;
	stacka->len++;
}

void	operate_pb(strhdr *stacka, strhdr *stackb)
{
	int	end;
	int	i;

	i = 0;
	end = stackb->len;
	if (stacka->data == NULL)
		return ;
	if (end == stackb->cap)
		return ;
	while (0 < end)
	{
		stackb->data[end] = stackb->data[end-1];
		end--;
	}
	stackb->data[0] = stacka->data[0];
	while (i < stacka->len-1)
	{
		stacka->data[i] = stacka->data[i+1];
		i++;
	}
	stackb->len++;
	stacka->len--;
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
