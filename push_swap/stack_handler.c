/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:07:24 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/02 19:17:55 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	fill_list(int *num_list, int ac, int *av)
{
	int		i;

	i = -1;
	while (++i < ac)
		num_list[i] = av[i];
}

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

int		*init_arr(t_struct *stack_a)
{
	int		*arr;
	
	arr = ft_calloc(sizeof(int), stack_a->length);
	fill_list(arr, stack_a->length, stack_a->stack);
	bubble_sort(arr, stack_a->length);
	return (arr);
}