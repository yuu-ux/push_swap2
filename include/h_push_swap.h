/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:45 by yehara            #+#    #+#             */
/*   Updated: 2024/09/07 19:37:58 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "../printf/ft_printf.h"

typedef struct s_info
{
	int		elem;
	int		index;
}			t_info;

typedef struct s_strhdr
{
	t_info	*data;
	int		cap;
	int		len;
}			t_strhdr;

// エラーチェック・スタック生成
int			check_duplicate(t_strhdr *stack, int elem, int elem_num);
int			check_sorted(t_strhdr *stack, int elem_num);
void		generate_stack(t_strhdr *stack, char **argv);
void		error_call(void);
int			count_elem(char **s);
void		check_error(char **argv);

// 操作関数
void		operate_sa(t_strhdr stacka);
void		operate_rra(t_strhdr stacka);
void		operate_ra(t_strhdr stacka);
void		operate_pa(t_strhdr *stacka, t_strhdr *stackb);
void		operate_pb(t_strhdr *stacka, t_strhdr *stackb);
void		operate_rb(t_strhdr stack);

// 要素数が5以下のときのソート
void		sort_three(t_strhdr stacka);
void		sort_four(t_strhdr stacka, t_strhdr stackb);
void		sort_five(t_strhdr stacka, t_strhdr stackb);
void		sort_small(t_strhdr stacka, t_strhdr stackb);

// utils
void		init_struct(t_strhdr *stack);

// 座標圧縮
void		ft_swap(int *x, int *y);
int			partition(int *array, int left, int right);
void		ft_quick_sort(int *array, int left, int right);
void		coordinate(t_strhdr *stack, int *temp_array);
void		position(t_strhdr *stack);

// メインのソート
void		radix_sort(t_strhdr *stacka, t_strhdr *stackb);
int			get_max_bit(t_strhdr stack);

#endif
