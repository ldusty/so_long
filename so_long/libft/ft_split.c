/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldusty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:10:24 by ldusty            #+#    #+#             */
/*   Updated: 2021/11/12 15:10:26 by ldusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_cnt_words(const char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*ft_create_words(const char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	ft_free_words(int i, char **str)
{
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}

static char	*ft_str_chr_ptr(const char *s, char c, int choice)
{
	if (!c)
		return ((char *) s);
	else
	{
		if (choice)
			while (*s && *s == c)
				s++;
		else
			while (*s && *s != c)
				s++;
	}
	return ((char *) s);
}

char	**ft_split(char const *s, char c)
{
	char	**splitstr;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_cnt_words(s, c);
	splitstr = malloc(sizeof(char *) * (words + 1));
	if (!splitstr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = ft_str_chr_ptr(s, c, 1);
		splitstr[i] = ft_create_words(s, c);
		if (!splitstr[i])
		{
			ft_free_words(i, splitstr);
			return (NULL);
		}
		s = ft_str_chr_ptr(s, c, 0);
		i++;
	}
	splitstr[i] = NULL;
	return (splitstr);
}
