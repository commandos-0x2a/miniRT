/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:03:40 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/30 17:23:26 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 4096

// int	get_next_line(int fd, char **line_r)
// {
// 	static char	left[BUFFER_SIZE];
// 	char		buffer[BUFFER_SIZE];
// 	ssize_t		nb_bytes;
// 	size_t		len;
// 	char		*line;

// 	*line_r = NULL;
// 	len = 0;
// 	while (1)
// 	{
// 		nb_bytes = read(fd, buffer, sizeof(buffer));
// 		if (nb_bytes < 0)
// 		{
// 			left[0] = '\0';
// 			return (-1);
// 		}
// 		*line_r = malloc();
// 		else if (nb_bytes == 0)
// 		{
			
// 		}
// 	}
// }


void	move_content(char *d, char *s)
{
	char	*p;

	p = s;
	while (isspace(*s))
		s++;
	while (*s && !isspace(*s))
		*d++ = *s++;
	*d = '\0';
	while (isspace(*s))
		s++;
	while (*s)
		*p++ = *s++;
	*p = '\0';
}

ssize_t	read_content(int fd, char content[BUFFER_SIZE])
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		nb_bytes;
	size_t		start;
	size_t		i;
	
	while (1)
	{
		move_content(content, buffer);
		if (content[0])
			return (1);
		nb_bytes = read(fd, buffer, sizeof(buffer));
		if (nb_bytes <= 0)
			return (nb_bytes);
	}
}