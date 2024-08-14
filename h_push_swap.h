#ifndef H_PUSH_SWAP_H
# define H_PUSH_SWAP_H
# include "./printf/ft_printf.h"

int	check_duplicate(int *stack, int elem, int elem_num);
int	check_sorted(int *stack, int elem_num);
int	*generate_stack(char **argv, int elem_num);
void error_call();
int	count_elem(char **s);
void check_error(char **argv);
# endif
