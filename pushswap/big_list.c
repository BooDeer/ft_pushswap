/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:23:41 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/12 17:44:56 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_chunk(t_struct *stack_a, t_struct *stack_b, int length,
int tab[2])
{
	int		left_mid;
	int		right_mid;
	int		middle;
	int		nbr;

	left_mid = get_index(length, tab[0], tab[1], -1);
	right_mid = get_index(length, tab[0], tab[1], 1);
	middle = length / 2;
	nbr = stack_a->stack[0];
	if ((nbr >= stack_a->arr[left_mid])
		&& (nbr < stack_a->arr[middle]))
	{
		push_b(stack_a, stack_b);
		rotate_b(stack_b);
	}
	else if (nbr <= stack_a->arr[right_mid]
		&& (nbr >= stack_a->arr[middle]))
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void	push_back(t_struct *stack_a, t_struct *stack_b, int n)
{
	while (1)
	{
		if (stack_b->stack[0] == stack_a->arr[n])
		{
			push_a(stack_b, stack_a);
			break ;
		}
		else if (stack_b->stack[0] == stack_a->arr[n - 1])
			push_a(stack_b, stack_a);
		else if (stack_b->stack[0] == stack_a->arr[n - 2])
		{
			push_a(stack_b, stack_a);
			rotate_a(stack_a);
		}
		else
		{
			if (get_pos(stack_b->stack, stack_a->arr[n], stack_b->length)
				> stack_b->length / 2)
				revrotate_b(stack_b);
			else
				rotate_b(stack_b);
		}
	}
}

void	push_chunk_back(t_struct *stack_a, t_struct *stack_b)
{
	int		nbr;

	while (stack_b->length > 0)
	{
		nbr = get_pos(stack_a->arr, find_biggest(stack_b->stack,
					stack_b->length), stack_b->length);
		push_back(stack_a, stack_b, nbr);
		if (stack_a->length > 1 && stack_a->stack[0] > stack_a->stack[1])
			swap_a(stack_a);
		if (stack_a->stack[stack_a->length - 1] < stack_a->arr[nbr])
			revrotate_a(stack_a);
	}
}

void	chunk_algo(t_struct *stack_a, t_struct *stack_b, int divisor)
{
	int		chunk;
	int		i;
	int		current_len;
	int		length;
	int		tab[2];

	chunk = 1;
	stack_a->arr = init_arr(stack_a);
	length = stack_a->length;
	while (stack_a->length > 0)
	{
		i = -1;
		current_len = stack_a->length;
		tab[0] = divisor;
		tab[1] = chunk;
		while (++i < current_len)
			push_chunk(stack_a, stack_b, length, tab);
		chunk++;
	}
	push_chunk_back(stack_a, stack_b);
}
