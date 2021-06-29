/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:38:20 by hboudhir          #+#    #+#             */
/*   Updated: 2021/06/29 20:16:05 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));	
}

int		list_length(int *list) // Not needed anymore (You must save the length from the moment you have it)
{
	int		i;
	
	if (list == NULL)
		return (0);
	i = -1;
	while(list[++i])
		;
	return (i);
}

int		check_dup(int num, int *num_list, int size)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	while (++i < size)
		if (num_list[i] == num)
		{
			check++;
			if (check > 1)
				return (1);			
		}
	return (0);
}

/*
*
*	Check if any element of the list is duplicated or
*	if the list contains any erros.
*	@param num_list: the list to check
*/

int		check_list(int *num_list, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (check_dup(num_list[i], num_list, size))
			return (1);
	return (0);
}

int		check_str(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (1);
	return (0);
}

int		nbr_only(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (check_str(arr[i]) || (ft_atoi(arr[i]) == -1 &&
		ft_strcmp(arr[i], "-1")))
			return (1);
	return (0);
}

void	fill_list(int *num_list, int ac, int *av)
{
	int		i;

	//(*num_list) = (int *)malloc(sizeof(int) * ac); // the allocation happens before the call of this function
	i = -1;
	while (++i < ac)
		num_list[i] = av[i];
}

/*
*
*	fills the array of integers in a list:
*	@param num_list: the list to fill.
*	@param ac: number of elements expected.
*	@param av: the src list.
*
*/

void	ft_fill_list(int **num_list, int ac, char **av)
{
	int		i;

	(*num_list) = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		(*num_list)[i] = ft_atoi(av[i]);
	if (check_list(*num_list, ac))
		printf("Error! Duplicatd argument\n"); // TODO: #1
}

/*
*
*	Check if the list is ordered in an incrementing manner.
*/

int		check_order(int *num_list, int size)
{
	int		i;

	i = -1;
	while (++i < size )
	{
		if (num_list[i] < num_list[i + 1])
			continue ;
		else
			return (1);
	}
	return (0);
}

void	swap_stack(int **num_list, int size)
{
	if (size > 1)
	{
		(*num_list)[0] = (*num_list)[0] + (*num_list)[1];
		(*num_list)[1] = (*num_list)[0] - (*num_list)[1];
		(*num_list)[0] = (*num_list)[0] - (*num_list)[1];
	}
}

void	push_stack(t_struct *src, t_struct *dst) // TODO_HOME: Refactor the code to use less lines.
{
	int		*tmp_a;
	int		*tmp_b;

	if (src->length > 0)
	{
		tmp_a = (int *)malloc(sizeof(int) * src->length - 1);
		fill_list(tmp_a, src->length - 1, &(src->stack[1]));
		tmp_b = (int *)malloc(sizeof(int) * dst->length + 1);
		tmp_b[0] = src->stack[0];
		fill_list(&(tmp_b[1]), dst->length, dst->stack);
		free(src->stack);
		free(dst->stack);
		src->stack = tmp_a;
		dst->stack = tmp_b;
		src->length--;
		dst->length++;
	}
}

void	rotate_stack(int *num_list, int	size)
{
	int		i;
	int		tmp;
	
	if (size < 2)
		return ;
	i = -1;
	tmp = num_list[0];
	while (++i + 1 < size)
	{
		num_list[i] = num_list[i] + num_list[i + 1];
		num_list[i + 1] = num_list[i] - num_list[i + 1];
		num_list[i] = num_list[i] - num_list[i + 1];
	}
}

void	revrotate_stack(int	*num_list, int size)
{
	int		i;
	int		tmp;

	if (size < 2)
		return ;
	i = 0;
	tmp = num_list[0];
	num_list[0] = num_list[size];
	while (++i < size)
	{
		printf("\nBefore switch:\n*  %d <===> %d\n", num_list[i], num_list[i + 1]);
		////////////////////
		tmp = tmp + num_list[i];
		num_list[i] = tmp - num_list[i];
		tmp = tmp - num_list[i];
		////////////////////
		printf("\nAfter switch:\n*  %d <===> %d\n", num_list[i], num_list[i + 1]);
	}
	num_list[0] = tmp;
}
/*
*
*	Temporary function to test the actions.
*	
*	@param action: the value of the action, it can be one of the following
*						-	sa: 1 | pa: 4
*							pb :5 | ra: 6 | rb: 7 | rr: 8
*							rr: 9 | rra:10| rrb:11| rrr: 12
*
*/


void	dummy_actions(int action, t_struct *stack_a, t_struct *stack_b)
{
	switch (action)
	{
	case 1:
		swap_stack(&(stack_a->stack), stack_a->length);
		break;
	case 2:
		push_stack(stack_a, stack_b);
		break;
	case 3:
		rotate_stack(stack_a->stack, stack_a->length);
		break;
	case 4:
		revrotate_stack(stack_a->stack, stack_a->length);
		break;
	default:
		break;
	}
	
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
		printf("index: %d==>%d ==>%d\n ", i, (b.stack)[i], b.length);
	printf("\n=========================\n");
}


void	swap_a(t_struct *stack_a)
{
	swap_stack(&(stack_a->stack), stack_a->length);
	ft_putstr("sa\n");
}

void	swap_b(t_struct *stack_b)
{
	swap_stack(&(stack_b->stack), stack_b->length);
	ft_putstr("sb\n");
}

void	swap_ab(t_struct *stack_a, t_struct *stack_b)
{
	swap_stack(&(stack_a->stack), stack_a->length);
	swap_stack(&(stack_b->stack), stack_b->length);
	ft_putstr("ss\n");
}

void	push_a(t_struct *stack_b, t_struct *stack_a)
{
	push_stack(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_struct *stack_a, t_struct *stack_b)
{
	push_stack(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	rotate_a(t_struct *stack_a)
{
	rotate_stack(stack_a->stack, stack_a->length);
	ft_putstr("ra\n");
}

void	rotate_b(t_struct *stack_b)
{
	rotate_stack(stack_b->stack, stack_b->length);
	ft_putstr("rb\n");
}

void	rotate_ab(t_struct *stack_a, t_struct *stack_b)
{
	rotate_stack(stack_a->stack, stack_a->length);
	rotate_stack(stack_b->stack, stack_b->length);
	ft_putstr("rr\n");
}

void	revrotate_a(t_struct *stack_a)
{
	revrotate_stack(stack_a->stack, stack_a->length);
	ft_putstr("rra\n");
}

void	revrotate_b(t_struct *stack_b)
{
	revrotate_stack(stack_b->stack, stack_b->length);
	ft_putstr("rrb\n");
}

void	revrotate_ab(t_struct *stack_a, t_struct *stack_b)
{
	revrotate_stack(stack_a->stack, stack_a->length);
	revrotate_stack(stack_b->stack, stack_b->length);
	ft_putstr("rrr\n");
}

int		find_bigger(int	*list, int size)
{
	int		i;
	int		j;
	int		index;

	j = list[0];
	i = -1;
	index = 0;
	while (++i < size)
		if (j < list[i])
		{
			j = list[i];
			index = i;
		}
	return (index);
}

int		find_smallest(int *list, int size)
{
	int		i;
	int		j;
	int		index;

	j = list[0];
	i = -1;
	index = 0;
	while (++i < size)
		if (j > list[i])
		{
			j = list[i];
			index = i;
		}
	return (index);
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

int		*init_arr(t_struct *stack_a)
{
	int		*arr;
	
	arr = ft_calloc(sizeof(int), stack_a->length);
	fill_list(arr, stack_a->length, stack_a->stack);
	bubble_sort(arr, stack_a->length);
	return (arr);
}

int		chunk_cal(int len, int chunk, int length, int sign)
{
	int		res;

	res = len * chunk;
	if (res > (length / 2))
		res = length / 2;
	if (sign == -1 && res == (length / 2))
		res -= 1;
	return (res);
}

int		get_index(int length, int div, int chunk, int sign)
{
	int 	middle;
	int		len;
	int		ret;

	middle = (length / 2) - 1;
	len = length / div;
	if (sign == -1)
		ret = middle - chunk_cal(len, chunk, length, -1);
	else
		ret = middle + chunk_cal(length / div, chunk, length, 1);
	return (ret);
}

void	push_chunk(t_struct *stack_a, t_struct *stack_b, int div, int chunk)
{
	int		left_mid;
	int		right_mid;
	int		middle;
	int		nbr;
	
	left_mid = get_index(stack_a->length, div, chunk, -1);
	right_mid = get_index(stack_a->length, div, chunk, 1);
	middle = stack_a->length / 2 - 1;
	nbr = stack_a->stack[0];
	if ((nbr >= stack_a->arr[left_mid])
		&& (nbr < stack_a->arr[middle]))
	{
		push_b(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else if (nbr <= stack_a->arr[right_mid]
		&& (nbr >= stack_a->arr[middle]))
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void	push_chunk_back(t_struct *stack_a, t_struct *stack_b)
{
	int		nbr;

	while (stack_b->length > 0)
	{
		
	}
}

void	sort_hundred(t_struct *stack_a, t_struct *stack_b, int divisor)
{
	int		chunk;
	int		i;
	int		current_len;

	chunk = 1;
	stack_a->arr = init_arr(stack_a);
	while (stack_a->length > 0)
	{
		i = -1;
		current_len = stack_a->length;
		while (++i < current_len)
			push_chunk(stack_a, stack_b, divisor, chunk);
		chunk++;
	}
	push_chunk_back()
}

void	order_list(t_struct *stack_a, t_struct *stack_b)
{
	if (stack_a->length <= 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->length <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->length <= 100)
		sort_hundred(stack_a, stack_b, 6);
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
	b.length = 0;
	ft_fill_list(&(a.stack), a.length, (av + 1));
	ft_fill_list(&(b.stack), 0, 0);
	//dummy_actions(4, &a, &b);
	if (check_order(a.stack, a.length))
	{
		order_list(&a, &b);
		//printf("The list is not ordered!\n");
	}
	print_stack(a, b);
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