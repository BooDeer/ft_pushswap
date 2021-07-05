/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:17:27 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/03 16:45:01 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_dup(int num, int *num_list, int size)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	while (++i < size)
	{
		if (num_list[i] == num)
		{
			check++;
			if (check > 1)
				return (1);
		}
	}
	return (0);
}

/*
*
*	Check if any element of the list is duplicated or
*	if the list contains any erros.
*	@param num_list: the list to check
*/

int	check_list(int *num_list, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (check_dup(num_list[i], num_list, size))
			return (1);
	return (0);
}

int	check_str(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (1);
	return (0);
}

int	nbr_only(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (check_str(arr[i]) || (ft_atoi(arr[i]) == -1
				&& ft_strcmp(arr[i], "-1")))
			return (1);
	return (0);
}

int	check_order(int *num_list, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (num_list[i] < num_list[i + 1])
			continue ;
		else
			return (1);
	}
	return (0);
}
