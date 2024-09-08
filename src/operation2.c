/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:22:41 by yehara            #+#    #+#             */
/*   Updated: 2024/08/31 18:31:02 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void	operate_rb(t_strhdr stack)
{
	t_info	temp;
	int		i;

	i = 0;
	temp = stack.data[0];
	while (i < stack.len - 1)
	{
		stack.data[i] = stack.data[i + 1];
		i++;
	}
	stack.data[stack.len - 1] = temp;
	ft_printf("rb\n");
}
