/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:36:25 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/05 08:25:32 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	bubble_sort(int *arr, int size)
{
	int		i;
	int		j;

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

int	chunk_cal(int len, int chunk, int length, int sign)
{
	int		res;

	res = len * chunk;
	if (res > (length / 2))
		res = length / 2;
	if (sign == 1 && res == length / 2 && (length % 2) == 0)
		res -= 1;
	return (res);
}

int	get_index(int length, int div, int chunk, int sign)
{
	int		middle;
	int		len;
	int		ret;

	middle = (length / 2);
	len = length / div;
	if (sign == -1)
		ret = middle - chunk_cal(len, chunk, length, -1);
	else
		ret = middle + chunk_cal(length / div, chunk, length, 1);
	return (ret);
}

void	order_list(t_struct *stack_a, t_struct *stack_b)
{
	if (stack_a->length <= 3)
		sort_three(stack_a);
	else if (stack_a->length <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->length <= 100)
		chunk_algo(stack_a, stack_b, 6);
	else if (stack_a->length > 100)
		chunk_algo(stack_a, stack_b, 16);
}
