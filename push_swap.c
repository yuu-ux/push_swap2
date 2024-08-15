/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:03 by yehara            #+#    #+#             */
/*   Updated: 2024/08/15 14:00:49 by yehara           ###   ########.fr       */
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
	strhdr	stacka;
	strhdr	stackb;
	char **list;
	
	list = NULL;

	//引数が0,1
	if (argc == 1)
	{
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		check_error(list);
		stacka.len = count_elem(list);
		stacka.data = generate_stack(list, stacka.len);
	}
	else
	{
		argv++;
		check_error(argv);
		stacka.len = count_elem(argv);
		stacka.data = generate_stack(argv, stacka.len);
	}

    for (int i = 0; i < stacka.len; i++)
        printf("%d\n", stacka.data[i]);

    // メモリの解放
    if (list) {
        for (int i = 0; list[i] != NULL; i++) {
            free(list[i]);
        }
        free(list);
    }
    // free(stacka);
    // free(stackb);
    // free(stacka);
    // free(stackb);
//	push_swap(stacka, stackb);
//	exit(EXIT_FAILURE);
}
