/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:32 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/20 11:45:19 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_c(char *s, char c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
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

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = len_c(dst, '\0');
	if (size <= dstlen)
		return (size + len_c(src, '\0'));
	size = size - dstlen;
	i = 0;
	while (src[i] && (i < (size - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + len_c(src, '\0'));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*sjoin;

	size = len_c(s1, '\0') + len_c(s2, '\0') + 1;
	sjoin = malloc(size);
	if (sjoin == NULL)
		return (NULL);
	sjoin[0] = 0;
	ft_strlcat(sjoin, s1, size);
	ft_strlcat(sjoin, s2, size);
	return (sjoin);
}
