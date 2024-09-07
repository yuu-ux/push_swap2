/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:51 by yehara            #+#    #+#             */
/*   Updated: 2024/09/03 21:43:31 by ebarayuug        ###   ########.fr       */
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

//int ft_median(strhdr stack, int len)
//{
//    // 構造体を渡す範囲を決められたらそれでいいのでは？
//    // 中央値を取得するロジックで迷っている
//    // 配列をコピーする
//    // 中央値を求めるって手順が必要
//    int median;
//    strhdr  *temp;
//    int i;
//
//    i = 0;
//    // 配列をコピーする
//    temp = (strhdr *)malloc(sizeof(strhdr) * len);
//    while (i < len)
//    {
//        temp.data[i] = stack.data[i];
//        i++;
//    }
//    // ソートする
//    ft_quick_sort(temp, 0, len);
//
//    // 中央値を求める
//    if (stack.len % 2 == 0)
//    {
//
//    }
//    else
//    {
//        median =
//    }
//    free(temp);
//    return (stack.data[i].elem);
//}

void    init_struct(strhdr *stack)
{
    int i;

    i = 0;
    while (i < stack->len)
    {
        stack->data[i].elem = 0;
        stack->data[i].index = 0;
        i++;
    }
}
