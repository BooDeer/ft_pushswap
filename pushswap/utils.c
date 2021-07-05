/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:08:51 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/03 17:11:16 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	find_smallest(int *list, int size)
{
	int		i;
	int		j;
	int		index;

	j = list[0];
	i = -1;
	index = 0;
	while (++i < size)
	{
		if (j > list[i])
		{
			j = list[i];
			index = i;
		}
	}
	return (index);
}

int	find_bigger(int	*list, int size)
{
	int		i;
	int		j;
	int		index;

	j = list[0];
	i = -1;
	index = 0;
	while (++i < size)
	{
		if (j < list[i])
		{
			j = list[i];
			index = i;
		}
	}
	return (index);
}

int	get_pos(int *arr, int n, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (n == arr[i])
			return (i);
	return (i);
}

int	find_biggest(int *arr, int size)
{
	int		n;
	int		i;

	n = arr[0];
	i = -1;
	while (++i < size)
		if (n < arr[i])
			n = arr[i];
	return (n);
}
