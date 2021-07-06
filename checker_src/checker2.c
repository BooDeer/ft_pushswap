/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:30:28 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 19:42:49 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	init_stack(t_struct *stack_a, t_struct *stack_b, int ac, char **av)
{
	stack_a->length = ac - 1;
	stack_a->arr_length = stack_a->length;
	stack_b->length = 0;
	ft_fill_list(&(stack_a->stack), stack_a->length, (av + 1));
	ft_fill_list(&(stack_b->stack), 0, 0);
}

void	ft_read_line(int *rt, char **buff, t_struct *stack_a, t_struct *stack_b)
{
	*rt = get_next_line(0, buff);
	if (check_action(*buff) && *rt)
	{	
		free(*buff);
		free(stack_b->stack);
		free(stack_a->stack);
		exit_msg(2, "Error\n", 1);
	}
	else
		exec_instruction(stack_a, stack_b, *buff);
}
