/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:35:55 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 18:55:33 by hboudhir         ###   ########.fr       */
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

void	exec_instruction(t_struct *stack_a, t_struct *stack_b, char *buff)
{
	if (!strcmp(buff, "sa"))
		swap_stack(&(stack_a->stack), stack_a->length);
	else if (!strcmp(buff, "sb"))
		swap_stack(&(stack_b->stack), stack_b->length);
	else if (!strcmp(buff, "ss"))
	{
		swap_stack(&(stack_a->stack), stack_a->length);
		swap_stack(&(stack_b->stack), stack_b->length);

	}
	else if (!strcmp(buff, "pa"))
		push_stack(stack_b, stack_a);
	else if (!strcmp(buff, "pb"))
		push_stack(stack_a, stack_b);
	else if (!strcmp(buff, "ra"))
		rotate_stack(stack_a->stack, stack_a->length);
	else if (!strcmp(buff, "rb"))
		rotate_stack(stack_b->stack, stack_b->length);
	else if (!strcmp(buff, "rr"))
	{
		rotate_stack(stack_a->stack, stack_a->length);
		rotate_stack(stack_b->stack, stack_b->length);
	}
	else if (!strcmp(buff, "rra"))
		revrotate_stack(stack_a->stack, stack_a->length);
	else if (!strcmp(buff, "rrb"))
		revrotate_stack(stack_b->stack, stack_b->length);
	else if (!strcmp(buff, "rrr"))
	{
		revrotate_stack(stack_a->stack, stack_a->length);
		revrotate_stack(stack_b->stack, stack_b->length);
	}
	
}

int		main(int ac, char **av)
{
	char	*buff;
	int		rt;
	t_struct stack_a;
	t_struct stack_b;
	
	if (ac < 2)
		return (0) ;
	if (nbr_only(av + 1))
		exit_msg(2, "Error\n", 1);
	stack_a.length = ac -1;
	stack_a.arr_length = stack_a.length;
	stack_b.length = 0;
	ft_fill_list(&(stack_a.stack), stack_a.length, (av + 1));
	ft_fill_list(&(stack_b.stack), 0, 0);
	
	while (1)
	{
		rt = get_next_line(0, &buff);
		if(check_action(buff) && rt)
		{	
			free(buff);
			free(stack_b.stack);
			free(stack_a.stack);
			exit_msg(2, "Error\n", 1);
		}
		else
			exec_instruction(&stack_a, &stack_b, buff);
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