/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:03 by yehara            #+#    #+#             */
/*   Updated: 2024/08/15 00:29:13 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void error_call()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	count_elem(char **s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

void check_error(char **argv)
{
	int i;
	int j;
	long temp;
	int flag;
	i = 0;

	//整数外・int外
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (INT_MAX < temp || INT_MIN > temp)
			error_call();
		flag = (0 > temp);
		// 整数外
		j = 0;
		while (argv[i][j])
		{
			if (flag)
			{
				flag = 0;
				j++;
			}
			if (!(ft_isdigit(argv[i][j])))
			{
				error_call();
			}	
			j++;
		}
		i++;
	}
	return ;
}

//void push_swap()
//{
//
//}

int main(int argc, char **argv)
{
	int	*stacka;
	int	*stackb;
	char **list;
	int elem_num;
	
	list = NULL;
	//引数が0,1
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		check_error(list);
		elem_num = count_elem(list);
		stacka = generate_stack(list, elem_num);
	}
	else
	{
		argv++;
		check_error(argv);
		elem_num = count_elem(argv);
		stacka = generate_stack(argv, elem_num);
	}
	stackb = generate_stack(list, 0);
	for (int i = 0; i < elem_num; i++)
		printf("%d\n", stacka[i]);
	// 各文字列を解放
	for (int i = 0; list[i] != NULL; i++) {
	    free(list[i]);
	}

	// 文字列の配列自体を解放
	free(list);
	free(stacka);
	free(stackb);
//	push_swap(stacka, stackb);
//	exit(EXIT_FAILURE);
}
