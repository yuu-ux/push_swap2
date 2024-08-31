/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:51 by yehara            #+#    #+#             */
/*   Updated: 2024/08/31 18:05:44 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

int ft_max(strhdr stack)
{
    int i;

    i = 0;
    while (stack.data[i].index != stack.len-1)
        i++;
    return (stack.data[i].elem);
}

int ft_min(strhdr stack)
{
    int i;

    i = 0;
    while (stack.data[i].index != 0)
        i++;
    return (stack.data[i].elem);
}

int ft_median(strhdr stack)
{
    int median;
    int i;

    i = 0;
    median = stack.len / 2;
    while (stack.data[i].index != median)
       i++;
    return (stack.data[i].elem);
}
