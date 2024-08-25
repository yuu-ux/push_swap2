#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "./printf/ft_printf.h"

typedef struct {
    int *data;
    int cap;
    int len;
} strhdr;

// エラーチェック・スタック生成
int	check_duplicate(strhdr *stack, int elem, int elem_num);
int	check_sorted(strhdr *stack, int elem_num);
void	generate_stack(strhdr *stack, char **argv, int elem_num);
void	error_call();
int	count_elem(char **s);
void	check_error(char **argv);

// 操作関数
void	operate_sa(strhdr stacka);
void	operate_rra(strhdr stacka);
void	operate_ra(strhdr stacka);

// 要素数が6以下のときのソート
void	sort_three(strhdr stacka);
void	sort_four(strhdr stacka, strhdr stackb);
void	sort_five(strhdr stacka, strhdr stackb);
void	sort_six(strhdr stacka, strhdr stackb);
void	sort_small(strhdr stacka, strhdr stackb);

# endif
