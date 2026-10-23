/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:29 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/23 11:23:16 by sgroenve         ###   ########.fr       */
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
	if (!((*buf)->buffer))
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

void	free_buf(t_buffer **buf)
{
	if (!*buf)
		return ;
	free((*buf)->buffer);
	free(*buf);
	*buf = NULL;
}

char	*get_next_line(int fd)
{
	int				rr;
	char			*line;
	size_t			count;
	static t_buffer	*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || !new_buffer(&buf))
		return (NULL);
	clean_buf(buf);
	count = 0;
	rr = 1;
	while (rr > 0)
	{
		while (count < buf->chars_read)
			if (buf->buffer[count++] == '\n')
				return (create_line(buf, count));
		rr = read_part(fd, buf);
	}
	line = NULL;
	if (rr == 0 && count > 0)
		line = create_line(buf, count);
	free_buf(&buf);
	return (line);
}
