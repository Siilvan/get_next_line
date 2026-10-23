/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:34 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/23 10:53:16 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_buffer
{
	char			*buffer;
	size_t			buf_size;
	unsigned long	idx;
	unsigned long	chars_read;
}	t_buffer;

int		read_part(int fd, t_buffer *buf);
int		add_size(t_buffer *buf);
void	free_buf(t_buffer **buf);
void	clean_buf(t_buffer *buf);
char	*get_next_line(int fd);
char	*create_line(t_buffer *buf, unsigned long new_idx);
#endif