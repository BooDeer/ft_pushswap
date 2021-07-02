/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:18:32 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/02 19:20:40 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
		tmp = tmp + num_list[i];
		num_list[i] = tmp - num_list[i];
		tmp = tmp - num_list[i];
	}
	num_list[0] = tmp;
}