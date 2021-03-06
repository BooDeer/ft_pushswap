/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:50:15 by hboudhir          #+#    #+#             */
/*   Updated: 2021/07/06 18:48:49 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*s;
	unsigned char		a;
	size_t				i;

	s = (unsigned char *)b;
	a = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = a;
		i++;
	}
	return (b);
}
