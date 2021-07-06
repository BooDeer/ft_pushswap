/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:35:55 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 20:25:44 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_action(char *a)
{
	int	len;

	len = ft_strlen(a);
	if (len == 2)
	{
		if ((a[0] == 's' || a[0] == 'p' || a[0] == 'r') && \
		((a[1] == 'a' || a[1] == 'b' || a[1] == a[0]) && a[1] != 'p'))
			return (0);
	}
	else if (len == 3)
	{
		if ((a[0] == 'r' && a[1] == 'r') && \
		(a[2] == 'a' || a[2] == 'b' || a[2] == 'r'))
			return (0);
	}
	return (1);
}

static void	exec_instruction2(t_struct *stack_a, t_struct *stack_b, char *buff)
{
	if (!ft_strcmp(buff, "rr"))
	{
		rotate_stack(stack_a->stack, stack_a->length);
		rotate_stack(stack_b->stack, stack_b->length);
	}
	else if (!ft_strcmp(buff, "rra"))
		revrotate_stack(stack_a->stack, stack_a->length);
	else if (!ft_strcmp(buff, "rrb"))
		revrotate_stack(stack_b->stack, stack_b->length);
	else if (!ft_strcmp(buff, "rrr"))
	{
		revrotate_stack(stack_a->stack, stack_a->length);
		revrotate_stack(stack_b->stack, stack_b->length);
	}
}

void	exec_instruction(t_struct *stack_a, t_struct *stack_b, char *buff)
{
	if (!ft_strcmp(buff, "sa"))
		swap_stack(&(stack_a->stack), stack_a->length);
	else if (!ft_strcmp(buff, "sb"))
		swap_stack(&(stack_b->stack), stack_b->length);
	else if (!ft_strcmp(buff, "ss"))
	{
		swap_stack(&(stack_a->stack), stack_a->length);
		swap_stack(&(stack_b->stack), stack_b->length);
	}
	else if (!ft_strcmp(buff, "pa"))
		push_stack(stack_b, stack_a);
	else if (!ft_strcmp(buff, "pb"))
		push_stack(stack_a, stack_b);
	else if (!ft_strcmp(buff, "ra"))
		rotate_stack(stack_a->stack, stack_a->length);
	else if (!ft_strcmp(buff, "rb"))
		rotate_stack(stack_b->stack, stack_b->length);
	exec_instruction2(stack_a, stack_b, buff);
}

int	main(int ac, char **av)
{
	char		*buff;
	int			rt;
	t_struct	stack_a;
	t_struct	stack_b;

	if (ac < 2)
		return (0);
	if (nbr_only(av + 1))
		exit_msg(2, "Error\n", 1);
	init_stack(&stack_a, &stack_b, ac, av);
	while (1)
	{
		ft_read_line(&rt, &buff, &stack_a, &stack_b);
		if (!rt)
		{
			if (check_order(stack_a.stack, stack_a.length))
				exit_msg(2, "KO\n", 1);
			if (stack_b.length != 0)
				exit_msg(2, "KO\n", 1);
			break ;
		}
	}
	write(1, "OK\n", ft_strlen("OK\n"));
	return (0);
}
