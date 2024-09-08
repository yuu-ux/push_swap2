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
