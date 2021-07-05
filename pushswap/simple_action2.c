/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_action2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:28:21 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/02 09:29:08 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
