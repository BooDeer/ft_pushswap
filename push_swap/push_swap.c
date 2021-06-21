/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:38:20 by hboudhir          #+#    #+#             */
/*   Updated: 2021/06/21 19:29:07 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	fill_list(int **num_list, int ac, char **av)
{
	int		i;

	*num_list = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac - 1)
	{
		(*num_list)[i] = ft_atoi(av[i + 1]);
		printf("%d\n", (*num_list)[i]);
	}
	(*num_list)[i] = 0;
}

int		check_dup(int num, int *num_list)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	while (num_list[++i])
		if (num_list[i] == num)
		{
			check++;
			if (check > 1)
				return (1);			
		}
	return (0);
}

//int		check_list(int *num_list)
//{
//	int		i;

//	i = -1;
//	while (num_list[++i])
//	{
//		if (check_dup(num_list[i], num_list))
			
//	}
//}

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
	int	*num_list;
	printf("%d\n", ac);
	fill_list(&num_list, ac, av);
	//check_list(num_list);
	//printf("Hello world!\n");
	return (0);
}