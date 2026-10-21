/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:32 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/21 17:41:45 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_part(int fd, t_buffer *buf)
{
	int	rr;

	rr = read(fd, buf->buffer + buf->chars_read, BUFFER_SIZE);
	if (rr <= 0)
		return (rr);
	buf->chars_read += rr;
	return (1);
}

void	*add_size(void *ptr, size_t *size)
{
	void	*new_ptr;
	size_t	i;

	if (!ptr)
		return (NULL);
	new_ptr = malloc(*size + BUFFER_SIZE);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	// ((char *)new_ptr)[i] = '\0';	
	*size += BUFFER_SIZE;
	free(ptr);
	return (new_ptr);
}

char	*create_line(t_buffer *buf, unsigned long new_idx)
{
	char			*res;
	unsigned long	i;

	i = 0;
	res = malloc(new_idx + 1);
	if (!res)
		return (NULL);
	while (i < new_idx)
	{
		res[i] = buf->buffer[buf->idx];
		i++;
		buf->idx++;
	}
	res[i] = 0;
	// printf("1%s1", res);
	return (res);
}
