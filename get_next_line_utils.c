/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:32 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/23 11:04:58 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_part(int fd, t_buffer *buf)
{
	ssize_t	rr;

	if (buf->buf_size - buf->chars_read < BUFFER_SIZE && !add_size(buf))
		return (-1);
	rr = read(fd, buf->buffer + buf->chars_read, BUFFER_SIZE);
	if (rr < 0)
		return (-1);
	buf->chars_read += rr;
	return (rr > 0);
}

int	add_size(t_buffer *buf)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = malloc(buf->buf_size + BUFFER_SIZE + 1);
	if (!new_ptr)
		return (0);
	i = 0;
	while (i < buf->chars_read)
	{
		new_ptr[i] = buf->buffer[i];
		i++;
	}
	free(buf->buffer);
	buf->buffer = new_ptr;
	buf->buf_size += BUFFER_SIZE;
	return (1);
}

char	*create_line(t_buffer *buf, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = buf->buffer[buf->idx];
		i++;
		buf->idx++;
	}
	res[i] = '\0';
	return (res);
}

void	clean_buf(t_buffer *buf)
{
	size_t	i;

	if (buf->idx == 0)
		return ;
	i = 0;
	while (buf->idx + i < buf->chars_read)
	{
		buf->buffer[i] = buf->buffer[buf->idx + i];
		i++;
	}
	buf->chars_read = i;
	buf->idx = 0;
}
