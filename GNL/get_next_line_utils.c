/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:18:33 by cstefany          #+#    #+#             */
/*   Updated: 2021/11/06 20:18:35 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_dst;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	len_dst = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof(char) * len_dst);
	if (dst == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *str, int chr)
{
	char	ch;

	ch = chr;
	while (*str != ch)
	{
		if (*str == '\0' && ch == '\0')
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		count;
	char	*return_str;

	i = 0;
	count = ft_strlen(s);
	return_str = (char *)malloc(sizeof(char) * (count + 1));
	if (return_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		return_str[i] = s[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
