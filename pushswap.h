#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_struct
{
	int		length;
	int		arr_length;
	int		*stack;
	int		*arr;
}				t_struct;

int		check_dup(int num, int *num_list, int size);
int		check_list(int *num_list, int size);
int		check_str(char *str);
int		nbr_only(char **arr);
int		check_order(int *num_list, int size);
void	swap_a(t_struct *stack_a);
void	swap_b(t_struct *stack_b);
void	swap_ab(t_struct *stack_a, t_struct *stack_b);
void	push_b(t_struct *stack_a, t_struct *stack_b);
void	push_a(t_struct *stack_b, t_struct *stack_a);
void	rotate_a(t_struct *stack_a);
void	rotate_b(t_struct *stack_b);
void	rotate_ab(t_struct *stack_a, t_struct *stack_b);
void	revrotate_a(t_struct *stack_a);
void	revrotate_b(t_struct *stack_b);
void	push_chunk(t_struct *stack_a, t_struct *stack_b, int length, int tab[2]);
void	push_back(t_struct *stack_a, t_struct *stack_b, int n);
int		*init_arr(t_struct *stack_a);
void	push_chunk_back(t_struct *stack_a, t_struct *stack_b);
void	chunk_algo(t_struct *stack_a, t_struct *stack_b, int divisor);
int		find_smallest(int *list, int size);
int		find_bigger(int	*list, int size);
int		get_pos(int *arr, int n, int size);
int		find_biggest(int *arr, int size);
void	fill_list(int *num_list, int ac, int *av);
void	ft_fill_list(int **num_list, int ac, char **av);
void	exit_msg(int fd, char *message, int error_code);
void	sort_three(t_struct *stack_a);
void	push_index(t_struct *s_src, t_struct *s_dst, int index, int size);
void	sort_five(t_struct *stack_a, t_struct *stack_b);
void	ft_putstr(char *str);
void	bubble_sort(int *arr, int size);
int		get_index(int length, int div, int chunk, int sign);
int		chunk_cal(int len, int chunk, int length, int sign);
void	order_list(t_struct *stack_a, t_struct *stack_b);
void	swap_stack(int **num_list, int size);
void	push_stack(t_struct *src, t_struct *dst);
void	rotate_stack(int *num_list, int	size);
void	revrotate_stack(int	*num_list, int size);
void	revrotate_ab(t_struct *stack_a, t_struct *stack_b);






#endif