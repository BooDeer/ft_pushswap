/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:38:20 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 19:34:16 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_struct *stack_a)
{
	int		big_num;

	if (stack_a->length == 3)
	{
		big_num = find_bigger(stack_a->stack, stack_a->length);
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
	while (stack_a->length > 3)
		push_index(stack_a, stack_b,
			find_smallest(stack_a->stack, stack_a->length), stack_a->length);
	sort_three(stack_a);
	while (stack_b->length > 0)
		push_a(stack_b, stack_a);
}
