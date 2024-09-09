/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:03 by yehara            #+#    #+#             */
/*   Updated: 2024/09/09 18:56:41 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

// デバッグ用
void	print_stack(t_strhdr stack)
{
	for (int i = 0; i < stack.len; i++)
	{
		printf("%d\n", stack.data[i].elem);
	}
}
void	error_call(void)
{
	write(2, "Error\n", 6);
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

void	check_error(char **argv)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (INT_MAX < temp || INT_MIN > temp)
			error_call();
		j = 0;
		while (argv[i][j])
		{
			if (0 > temp)
				j++;
			if (!(ft_isdigit(argv[i][j])))
				error_call();
			j++;
		}
		i++;
	}
}

void	push_swap(t_strhdr stacka, t_strhdr stackb)
{
	if (stacka.len < 6)
		sort_small(stacka, stackb);
	else
		radix_sort(&stacka, &stackb);
}

int	main(int argc, char **argv)
{
	t_strhdr	stacka;
	t_strhdr	stackb;
	char		**list;

	list = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			error_call();
		argv = list;
	}
	else
		argv++;
	init_stack(&stacka, argv);
	stackb.data = (t_info *)malloc(sizeof(t_info) * stacka.len);
	init_strhdr(&stackb, 0, stacka.len);
	init_info(&stackb);
	// print_stack(stacka);
	push_swap(stacka, stackb);
	//print_stack(stacka);
	free_all(list, &stacka, &stackb);
	return (0);
}
