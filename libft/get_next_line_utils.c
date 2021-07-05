/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:22:58 by mhalli            #+#    #+#             */
/*   Updated: 2019/12/27 11:23:04 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			k;

	i = 0;
	k = (char)c;
	while (s[i] != '\0' && s[i] != k)
		i++;
	if (s[i] == k)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*b;
	size_t		i;
	size_t		z;

	i = 0;
	z = ft_strlen(s1);
	b = (char *)malloc(z + 1);
	if (!b)
		return (NULL);
	while (s1[i] != '\0')
	{
		b[i] = (char)s1[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if ((s1 == NULL && s2 == NULL) || s1 == NULL)
		return (0);
	string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (0);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*b;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	b = (char *)malloc(len + 1);
	if (!b)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		b[i] = s[start + i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
