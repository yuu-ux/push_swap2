/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:08:54 by yehara            #+#    #+#             */
/*   Updated: 2024/08/29 20:17:37 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "h_push_swap.h"

void ft_swap(int *x, int* y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *array, int left, int right)
{
    int i;
    int j;
    int pivot;

    i = left + 1;
    j = right;
    pivot = left;
    while (i <= j)
    {
        while (i <= right && array[i] < array[pivot])
            i++;
        while (j > left && array[pivot] < array[j])
            j--;
        if (i < j)
            ft_swap(&array[i], &array[j]);
    }
    if (j > left)
        ft_swap(&array[pivot], &array[j]);
    return j;
}

void ft_quick_sort(int *array, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(array, left, right);
        ft_quick_sort(array, left, pivot-1);
        ft_quick_sort(array, pivot+1, right);
    }
}

void    coordinate(strhdr *stack, int *temp_array)
{
    int i;
    int j;

    i = 0;
    while (i < stack->len)
    {
        j = 0;
        while (j < stack->len)
        {
            if (temp_array[i] == stack->data[j].elem)
                stack->data[j].index = i;
            j++;
        }
        i++;
    }
}

void	position(strhdr *stack)
{
    int *temp_array;
    int i;

    i = 0;
    temp_array = (int *)malloc(sizeof(int) * stack->len);
    // 配列をコピーする
    while (i < stack->len)
    {
        temp_array[i] = stack->data[i].elem;
        i++;
    }
    // ソートする
    ft_quick_sort(temp_array, 0, stack->len-1);
    // 座標圧縮する
    coordinate(stack, temp_array);
    // freeする
    free(temp_array);
}
