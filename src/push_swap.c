/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:03 by yehara            #+#    #+#             */
/*   Updated: 2024/09/08 14:26:41 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_push_swap.h"

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
	char	**list;

	list = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			error_call();
		check_error(list);
		stacka.len = count_elem(list);
		stacka.cap = stacka.len;
		generate_stack(&stacka, list);
		position(&stacka);
	}
	else
	{
		argv++;
		check_error(argv);
		stacka.len = count_elem(argv);
		stacka.cap = stacka.len;
		generate_stack(&stacka, argv);
		position(&stacka);
	}
	stackb.data = (t_info *)malloc(sizeof(t_info) * stacka.len);
	init_struct(&stackb);
	stackb.len = 0;
	stackb.cap = stacka.len;
	push_swap(stacka, stackb);
	if (list)
	{
		for (int i = 0; list[i] != NULL; i++)
		{
			free(list[i]);
		}
		free(list);
	}
	free(stacka.data);
	free(stackb.data);
	exit(EXIT_FAILURE);
}
