/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:26:29 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/02 09:26:46 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
