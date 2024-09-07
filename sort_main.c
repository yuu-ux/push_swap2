/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:07:21 by yehara            #+#    #+#             */
/*   Updated: 2024/09/03 22:14:16 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "h_push_swap.h"

int get_max_digit(strhdr stack)
{
    int max;
    int max_digit;
    int i;

    i = 0;
    max = stack.data[0].index;
    max_digit = 0;
    while (i < stack.len)
    {
        if (stack.data[i].index > max)
            max = stack.data[i].index;
        i++;
    }
    while ((max >> max_digit) != 0)
        max_digit++;
    return (max_digit);
}

void    radix_sort(strhdr *stacka, strhdr *stackb)
{
    int i;
    int j;
    int max_digit;

    i = 0;
    max_digit = get_max_digit(*stacka);
    while (i < max_digit)
    {
        j = 0;
        while (j++ < stacka->len)
        {
            if (((stacka->data[j].index >> i) & 1) == 1)
                operate_ra(*stacka);
            else
                operate_pb(stacka, stackb);
        }
        while (stackb->len != 0)
            operate_pa(stacka, stackb);
        i++;
    }
}
