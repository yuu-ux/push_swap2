/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:07:21 by yehara            #+#    #+#             */
/*   Updated: 2024/09/08 15:18:19 by ebarayuug        ###   ########.fr       */
/*   Updated: 2024/09/08 14:12:07 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "h_push_swap.h"

int get_max_digit(strhdr stack)
int get_max_bit(strhdr stack)
{
    int max;
    int max_digit;
    int max_bits;
    int i;

    i = 0;
    max = stack.data[0].index;
    max_digit = 0;
    max_bits = 0;
    while (i < stack.len)
    {
        if (stack.data[i].index > max)
            max = stack.data[i].index;
        i++;
    }
    while ((max >> max_digit) != 0)
        max_digit++;
    return (max_digit);
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(strhdr *stacka, strhdr *stackb)
{
    int i;
    int j;
    int max_digit;
    int max_bits;
    int size;

    size = stacka->len;
    i = 0;
    max_digit = get_max_digit(*stacka);
    while (i < max_digit)
    max_bits = get_max_bit(*stacka);
    size = stacka->len;
    while (i < max_bits)
    {
        j = 0;
        // 比較したあとにインクリメントされるから回る回数に影響はない
        // ただ、処理の中でjを使用する場合、挙動が変わってくるので注意が必要
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
