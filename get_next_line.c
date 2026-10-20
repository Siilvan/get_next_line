/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:29 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/20 11:45:26 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			strlen;
	char		*tmp[BUFFER_SIZE + 1];
	char		*line;
	static char	*keep;

	line = NULL;
	if (ft_strchr(keep, '\n'))
		ft_strjoin
}
