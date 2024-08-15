#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "./printf/ft_printf.h"

typedef struct {
    int *data;
    int cap;
    int len;
} strhdr;

int	check_duplicate(strhdr *stack, int elem, int elem_num);
int	check_sorted(strhdr *stack, int elem_num);
void	generate_stack(strhdr *stack, char **argv, int elem_num);
void error_call();
int	count_elem(char **s);
void check_error(char **argv);
void	operate_sa(strhdr stacka);
void	operate_ra(strhdr stacka);
# endif
