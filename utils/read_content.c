/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:03:40 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/31 12:27:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFFER_SIZE 15

# define RC_NONE		0
# define RC_PRINT		1 << 0
# define RC_CONT		1 << 1
# define RC_OVERFLOW	1 << 2
# define RC_ERROR		1 << 8


char	*move_content(char *d, char *s, char *d_end)
{
	char	*p;

	p = s;
	// skip white space
	while (isspace(*s))
		s++;

	// move content
	while (*s && !isspace(*s) && d < d_end)
		*d++ = *s++;
	*d = '\0';

	// check is left content
	if (!*s || d == d_end)
		return (d);
	
	// skip white space
	while (isspace(*s))
		s++;
	
	// move leftover to source
	while (*s)
		*p++ = *s++;
	*p = '\0';
	
	return (NULL);
}

ssize_t	read_content(int fd, char content[BUFFER_SIZE])
{
	static char	buffer[BUFFER_SIZE];
	char 		*cur;
	ssize_t		nb_bytes;

	cur = content;
	content[0] = '\0';
	while (1)
	{
		cur = move_content(cur, buffer, content + BUFFER_SIZE - 1);
		if (!cur)
			return (RC_PRINT | RC_CONT);
		if (cur >= content + BUFFER_SIZE - 1)
			return (RC_OVERFLOW);
		nb_bytes = read(fd, buffer, sizeof(buffer));
		if (nb_bytes < 0)
		{
			buffer[0] = '\0';
			return (RC_ERROR);
		}
		buffer[nb_bytes] = '\0';
		if (nb_bytes == 0 && content[0])
			return (RC_PRINT);
		else if (nb_bytes == 0)
			return (RC_NONE);
	}
}

int main()
{
	int 	fd;
	char	buf[BUFFER_SIZE];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open file");
		return (1);
	}
	int ret = RC_CONT;
	while (ret & RC_CONT)
	{
		ret = read_content(fd, buf);
		if (ret & RC_PRINT)
			printf("%s\n", buf);
	}
	printf("%s\n", buf);
	return (0);
}
