/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:13:38 by mhalli            #+#    #+#             */
/*   Updated: 2020/02/09 03:08:45 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(int fd, char *str)
{
	char	*buffer;
	int		rd;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (str == NULL)
		str = ft_strdup("");
	while (!(ft_strchr(str, '\n')))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (0);
		buffer[rd] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (rd == 0)
			break ;
	}
	free(buffer);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char		*str;
	char			*temp;
	int				len;

	len = 0;
	str = ft_fill(fd, str);
	if (!line || !str)
		return (-1);
	if (ft_strchr(str, '\n'))
	{
		while (str[len] != '\n')
			len++;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
}
