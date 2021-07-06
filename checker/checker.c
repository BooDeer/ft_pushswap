/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:35:55 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 17:27:22 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

int		exit_program(char *error_msg, int fd, int exit_code)
{
	write(fd, error_msg, ft_strlen(error_msg));
	return (exit_code);
}

int		check_arg(char *arg)
{
	int		i;
	long long	nbr_check;
	
	i = -1;
	while (arg[++i])
	{
		if (ft_isdigit(arg[i]))
			continue ;
		else
			return (0);
	}
	nbr_check = ft_atoi(arg);
	if (nbr_check == -1)
		exit_program("Error: number is too big\n", 1, 1);
	else if (nbr_check == -2)
		exit_program("Error: number is too small\n", 1, 1);
	return (1);
}

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

void	print_stack(int *stack, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", stack[i]);
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