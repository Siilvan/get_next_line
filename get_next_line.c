/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:29 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/21 17:43:15 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_buffer(t_buffer **buf)
{
	if (*buf)
		return (1);
	*buf = malloc(sizeof(t_buffer));
	if (!*buf)
		return (0);
	(*buf)->buffer = malloc(BUFFER_SIZE + 1);
	if(!((*buf)->buffer))
	{
		free (*buf);
		*buf = 0;
		return (0);
	}
	(*buf)->buf_size = BUFFER_SIZE;
	(*buf)->idx = 0;
	(*buf)->chars_read = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buf;
	unsigned long	count;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || !new_buffer(&buf))
		return (NULL);
	if (buf->chars_read == 0)
		read_part(fd, buf);
	count = 0;
	while (buf->buffer[count] != '\n' && buf->buffer[count] != '\0')
	{
		if (buf->chars_read == buf->buf_size)
		{
			buf->buffer = add_size(buf->buffer, &buf->buf_size);
			if (read_part(fd, buf) <= 0)
				return (NULL);
		}
		count++;
	}
	line = create_line(buf, count);
	printf("'%lu'%s", count, line);
	return (line);
}
