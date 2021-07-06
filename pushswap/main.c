/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:54:56 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/05 11:55:21 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int ac, char **av)
{
	t_struct	a;
	t_struct	b;

	if (nbr_only(av + 1))
		exit_msg(2, "Error\n", 1);
	if (ac < 3)
		return (0);
	a.length = ac - 1;
	a.arr_length = a.length;
	b.length = 0;
	ft_fill_list(&(a.stack), a.length, (av + 1));
	ft_fill_list(&(b.stack), 0, 0);
	if (check_order(a.stack, a.length))
	{
		order_list(&a, &b);
	}
	return (0);
}