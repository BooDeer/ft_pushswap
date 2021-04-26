/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:35:55 by hboudhir          #+#    #+#             */
/*   Updated: 2021/04/24 15:56:19 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../libft/libft.h"

int		exit_program(char *error_msg, int fd, int exit_code)
{
	write(fd, error_msg, ft_strlen(error_msg));
	return (exit_code);
}

int		check_arg()
{
	
}
int		main(int argc, char **argv)
{
	int		i;
	if (argc < 2)
		return(exit_program("Error: wrong number of arguments.\n", 1, 1));
	i = 1;
	while (i < argc)
	{
		if (check_arg(argv[i]))
			return(exit_program("Error: wrong arguments.\n", 1, 1));
	}
	printf("%s\n", argv[3]);
	printf("Reached here\n");
}