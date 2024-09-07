/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:45 by yehara            #+#    #+#             */
/*   Updated: 2024/09/03 21:37:39 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "./printf/ft_printf.h"

typedef struct {
	int	elem;
	int	index;
} info;

typedef struct {
	info	*data;
	int	cap;
    int	len;
} strhdr;

// エラーチェック・スタック生成
int	check_duplicate(strhdr *stack, int elem, int elem_num);
int	check_sorted(strhdr *stack, int elem_num);
void	generate_stack(strhdr *stack, char **argv);
void	error_call();
int	count_elem(char **s);
void	check_error(char **argv);

// 操作関数
void	operate_sa(strhdr stacka);
void	operate_rra(strhdr stacka);
void	operate_ra(strhdr stacka);
void	operate_pa(strhdr *stacka, strhdr *stackb);
void	operate_pb(strhdr *stacka, strhdr *stackb);
void	operate_rb(strhdr stack);

// 要素数が5以下のときのソート
void	sort_three(strhdr stacka);
void	sort_four(strhdr stacka, strhdr stackb);
void	sort_five(strhdr stacka, strhdr stackb);
void	sort_small(strhdr stacka, strhdr stackb);

// utils
int ft_median(strhdr stack);
int ft_min(strhdr stack);
int ft_max(strhdr stack);
void    init_struct(strhdr *stack);

// 座標圧縮
void    ft_swap(int *x, int* y);
int partition(int *array, int left, int right);
void    ft_quick_sort(int *array, int left, int right);
void    coordinate(strhdr *stack, int *temp_array);
void    position(strhdr *stack);

// メインのソート
void    radix_sort(strhdr *stacka, strhdr *stackb);
int get_max_digit(strhdr stack);

# endif
