/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:07:21 by yehara            #+#    #+#             */
/*   Updated: 2024/08/31 18:04:38 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "h_push_swap.h"

void    ft_push_b(strhdr *stacka, strhdr *stackb)
{
    while (stacka->len != 0)
    {
        operate_pb(stacka, stackb);
    }
}

void    target_sort(strhdr *stacka, strhdr *stackb)
{
    int max;

    while (0 != stackb->len)
    {
        max = ft_max(*stackb);
        while (max != stackb->data[0].elem)
            operate_rb(*stackb);
        operate_pa(stacka, stackb);
    }
}

void	sort_main(strhdr *stacka, strhdr *stackb)
{
    // stackaの中央値より小さい値をすべてpbする
    ft_push_b(stacka, stackb);
    // インデックス番号をもとに選択ソートする
    target_sort(stacka, stackb);
	return ;
}
