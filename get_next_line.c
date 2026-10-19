/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:29 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/19 17:49:57 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// read until newline with specified buffer
	// if read passes newline go back to last \n and move fd to there
	// every read call has to be with buffersize
	// use static variable to increment until newline or buffersize reached
	int			strlen;
	int			prev_len;
	char		*line;
	static char	*previous;

	strlen = BUFFER_SIZE;
	prev_len = len_to_c(previous, '\0');
	line = malloc(strlen);	
	previous = malloc(BUFFER_SIZE);
	if (!line || !previous)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		if (read(fd, line + (strlen - BUFFER_SIZE), BUFFER_SIZE) == 0)
			return (NULL);
		strlen += BUFFER_SIZE;
		line = expand_size(line, strlen);
	}
	ft_strlcat(previous, ft_strchr(line, '\n'), len_to_c(line, '\0'));
	return (line);
}
