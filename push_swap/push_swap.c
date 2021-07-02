/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:38:20 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/02 19:27:13 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));	
}

void	print_stack(t_struct a, t_struct b)
{
	int		i;

	i = -1;
	printf("\n=========================\n");
	printf("\nStack a:\n");
	while (++i < a.length)
		printf("index: %d==>%d\n", i, (a.stack)[i]);
	printf("\n=========================\n");
	printf("\nStack b:\n");
	i = -1;
	while (++i < b.length)
		printf("index: %d==>%d\n ", i, (b.stack)[i]);
	printf("\n=========================\n");
}






void	revrotate_ab(t_struct *stack_a, t_struct *stack_b)
{
	revrotate_stack(stack_a->stack, stack_a->length);
	revrotate_stack(stack_b->stack, stack_b->length);
	ft_putstr("rrr\n");
}




// =============== Sorting list starts from below ===============

void	sort_three(t_struct *stack_a, t_struct *stack_b)
{
	int		index;
	int		big_num;
	
	if (stack_a->length == 3)
	{
		big_num	= find_bigger(stack_a->stack, stack_a->length);
		if (big_num < 2)
		{
			if (big_num == 0)
				rotate_a(stack_a);
			else if (big_num == 1)
				revrotate_a(stack_a);
		}
	}
	if (stack_a->stack[0] > stack_a->stack[1])
		swap_a(stack_a);
}

void	push_index(t_struct *s_src, t_struct *s_dst, int index, int size)
{
	int		i;
	int		target;

	target = s_src->stack[index];
	if (index >= (size / 2) - 1)
	{
		while (s_src->stack[0] != target)
			revrotate_a(s_src);
		push_b(s_src, s_dst);
	}
	else if (index < (size / 2) - 1)
	{
		while (s_src->stack[0] != target)
			rotate_a(s_src);
		push_b(s_src, s_dst);	
	}
}

void	sort_five(t_struct *stack_a, t_struct *stack_b)
{
	int		index;
	
	while (stack_a->length > 3)
		push_index(stack_a, stack_b,
		find_smallest(stack_a->stack, stack_a->length), stack_a->length);
	sort_three(stack_a, stack_b);
	while (stack_b->length > 0)
		push_a(stack_b, stack_a);
	
}

void	bubble_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (j < size - 1)
	{
		while (i < size - j - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] = arr[i] - arr[i + 1];
			}
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}


int		chunk_cal(int len, int chunk, int length, int sign)
{
	int		res;

	res = len * chunk;
	if (res > (length / 2))
		res = length / 2;
	if (sign == 1 && res == length / 2 && (length % 2) == 0)
		res -= 1;
	return (res);
}

int		get_index(int length, int div, int chunk, int sign)
{
	int 	middle;
	int		len;
	int		ret;

	middle = (length / 2);
	len = length / div;
	if (sign == -1)
		ret = middle - chunk_cal(len, chunk, length, -1);
	else
		ret = middle + chunk_cal(length / div, chunk, length, 1);
	return (ret);
}











void	order_list(t_struct *stack_a, t_struct *stack_b)
{
	if (stack_a->length <= 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->length <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->length <= 100)
		chunk_algo(stack_a, stack_b, 6);
	else if (stack_a->length > 100)
		chunk_algo(stack_a,stack_b, 16);
}



/*
*
*	TODO: - read input and handle all possible input errors.
*		  - Create the following actions:
*				- sa/sb/ss
*				- pa/pb
*				- ra/rb/rr
*				- rra/rrb/rrr
*
*
*	DONE: - making sure the params are numbers only and in the
*		  	integer interval. (Numbers between -2147483648 and 2147483647)
*		  - filling correctly the list.
*		  - 
*
*/

int		main(int ac, char **av)
{
	t_struct a;
	t_struct b;
	if (nbr_only(av + 1))
	{
		printf("Error!\n"); // TODO: #1
		return (0);	
	}
	a.length = ac -1;
	a.arr_length = a.length;
	b.length = 0;
	ft_fill_list(&(a.stack), a.length, (av + 1));
	ft_fill_list(&(b.stack), 0, 0);
	//dummy_actions(4, &a, &b);
	if (check_order(a.stack, a.length))
	{
		order_list(&a, &b);
	}
	//print_stack(a, b);
	return (0);
}

/*
*
*	This is a glossary for this project,
*	any commentary that contains a #XXX
*	can be found here.
*
*	#1: Change the error message, preferably with a better function
*
*
*
*
*
*
*
*
*/