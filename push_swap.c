/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:03 by yehara            #+#    #+#             */
/*   Updated: 2024/08/13 22:31:08 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

void error_call()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	count_elem(char **s, char c)
{
	size_t	count;
	int		in_word;
	int	i;
	int	j;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != c && !in_word)
			{
				in_word = 1;
				count++;
			}
			else if (s[i][j] == c)
			{
				in_word = 0;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void check_error(char **argv)
{
	int i;
	int j;
	long temp;
	i = 1;
	j = 0;

	//整数外・int外
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (INT_MAX < temp || INT_MIN > temp)
			error_call();
		// 整数外
		while (argv[i][j])
		{
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

	//error handling
	//要素数を数える
	if (argc < 3)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		check_error(list);
		elem_num = count_elem(list, ' ');
	}
	else
	{
		check_error(argv);
		elem_num = count_elem(argv, ' ');
	}
	if (elem_num < 2)
		exit(EXIT_FAILURE);
	stacka = generate_stack(argv, elem_num);
	stackb = generate_stack(argv, 0);
	for (int i = 0; i < elem_num; i++)
	{
		printf("%d ", stacka[i]);
	}
//	push_swap(stacka, stackb);
//	exit(EXIT_FAILURE);
}
