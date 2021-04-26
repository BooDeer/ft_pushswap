/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:35:55 by hboudhir          #+#    #+#             */
/*   Updated: 2021/04/26 16:49:39 by hboudhir         ###   ########.fr       */
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
int		main(int argc, char **argv)
{
	int		i;
	//int		rt;
	
	(void)argv;
	if (argc < 2)
		return(exit_program("Error: wrong number of arguments.\n", 1, 1));
	printf("Argc: %d\n", argc);
	i = 0;
	while (++i < argc)
	{
		if (!check_arg(argv[i]))
			return(exit_program("Error: wrong arguments.\n", 1, 1));
	}
	
	//char *line;
	//while((rt = get_next_line(0, &line)))
	//{
	//	printf("The line's:\n\"\"\"\"\"\"%d\"\"\"\"\"\"\n%s\n\"\"\"\"\"\"\"\"\"\"\"\"\n", rt, line);
	//	if (!rt)
	//		break ;
	//}

	
	//printf("%s\n", argv[3]);
	//printf("Reached here\n");
}