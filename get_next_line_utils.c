/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:32 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 17:50:19 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*expand_size(char *ptr, size_t size)
{
	char	*newptr;
	size_t	i;

	i = 0;
	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	newptr = malloc(size);
	while (i < size && ptr[i])
	{
		newptr[i] = ptr[i];
		i++;
	}
	newptr[i] = 0;
	free(ptr);
	return (newptr);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = len_to_c(dst, '\0');
	if (size <= dstlen)
		return (size + len_to_c(src, '\0'));
	size = size - dstlen;
	i = 0;
	while (src[i] && (i < (size - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + len_to_c(src, '\0'));
}
