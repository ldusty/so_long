/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:10:19 by ldusty            #+#    #+#             */
/*   Updated: 2021/12/21 18:10:29 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char) c)
			return ((char *) s - 1);
	if (!c)
		return ((char *) s);
	return (NULL);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		len = 0;
	if (len > i - start)
		len = i - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*read_buffer(int fd, char *buffer, char *remainder)
{
	long	count;
	char	*tmp;

	count = 1;
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

static char	*recover_remainder(char *str)
{
	long	count;
	char	*remain;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\0')
		return (0);
	remain = ft_substr(str, count + 1, ft_strlen(str) - count);
	if (*remain == '\0')
	{
		free(remain);
		remain = NULL;
	}
	str[count + 1] = '\0';
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	str = read_buffer(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!str)
		return (0);
	remainder = recover_remainder(str);
	return (str);
}
