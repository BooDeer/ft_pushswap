/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b00d33r <b00d33r@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:38:20 by hboudhir          #+#    #+#             */
/*   Updated: 2021/06/23 03:36:31 by b00d33r          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		list_length(int *list)
{
	int		i;
	
	if (list == NULL)
		return (0);
	i = -1;
	while(list[++i])
		;
	return (i);
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

/*
*
*	Check if any element of the list is duplicated or
*	if the list contains any erros.
*	@param num_list: the list to check
*/

int		check_list(int *num_list)
{
	int		i;

	i = -1;
	while (num_list[++i])
		if (check_dup(num_list[i], num_list))
			return (1);
	return (0);
}

int		check_str(char *str)
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

int		nbr_only(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (check_str(arr[i]) || (ft_atoi(arr[i]) == -1 &&
		ft_strcmp(arr[i], "-1")))
			return (1);
	return (0);
}


/*
*
*	fills the array of integers in a list:
*	@param num_list: the list to fill.
*	@param ac: number of elements expected.
*	@param av: the src list.
*
*/

void	fill_list(int **num_list, int ac, char **av)
{
	int		i;

	*num_list = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac - 1)
		(*num_list)[i] = ft_atoi(av[i + 1]);
	(*num_list)[i] = 0;
	if (check_list(*num_list))
		printf("Error! Duplicatd argument\n"); // TODO: #1
}

/*
*
*	Check if the list is ordered in an incrementing manner.
*
*/

int		check_order(int *num_list)
{
	int		i;

	i = -1;
	while (num_list[++i] && num_list[i + 1])
	{
		if (num_list[i] < num_list[i + 1])
			continue ;
		else
			return (1);
	}
	return (0);
}

void	swap_stack(int **num_list)
{
	if (list_length(*num_list) > 1)
	{
		(*num_list)[0] = (*num_list)[0] + (*num_list)[1];
		(*num_list)[1] = (*num_list)[0] - (*num_list)[1];
		(*num_list)[0] = (*num_list)[0] - (*num_list)[1];
	}
}

void	push_stack(int **src, int **dst) // REACHED HERE!! -- Check if the dst/src is null/empty then realloc the dst/src and move the element ;) Good luck
{
			
}

/*
*
*	Temporary function to test the actions.
*	
*	@param action: the value of the action, it can be one of the following
*						-	sa: 1 | pa: 4
*							pb :5 | ra: 6 | rb: 7 | rr: 8
*							rr: 9 | rra:10| rrb:11| rrr: 12
*
*/


void	dummy_actions(int action, int **num_list)
{
	switch (action)
	{
	case 1:
		swap_stack(num_list);
		break;

	default:
		break;
	}
	
}

/*
*
*	TODO: - read input and handle all possible input errosr.
*		  - Create the following actions:
*				- sa/sb/ss
*				- pa/pb
*				- ra/rb/rr
*				- rra/rrb/rrr
*
*
*	DONE: - making sure the params are numbers only and in the
*		  	integer interval. (Numbers between -2147483648 and 2147483647)
*		  - filling correctly the list.
*		  - 
*
*/

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
	//printf("%d\n", list_length(NULL));

	if (nbr_only(av + 1))
	{
		printf("Error!\n"); // TODO: #1
		return (0);	
	}

	//printf("%d\n", ft_atoi("0adjbajd"));
	int	*num_list;
	fill_list(&num_list, ac, av);
	dummy_actions(1, &num_list);
	printf("%d <=====> %d\n", num_list[0], num_list[1]);
	if (check_order(num_list))
		printf("The list is not ordered!\n");
	return (0);
}

/*
*
*	This is a glossary for this project,
*	any commentary that contains a #XXX
*	can be found here.
*
*	#1: Change the error message, preferably with a better function
*
*
*
*
*
*
*
*
*/