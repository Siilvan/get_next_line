/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:49:34 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/20 11:44:40 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *s, char c);
char	*get_next_line(int fd);
int		len_c(char *s, char c);
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
#endif