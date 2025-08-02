/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:03:40 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/02 09:34:02 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>

# define BUFFER_SIZE 8

# define RC_NONE		0
# define RC_CTX			1 << 0
# define RC_CONT		1 << 1
# define RC_DELIMITER	1 << 3
# define RC_OVERFLOW	1 << 7
# define RC_ERROR		1 << 8


int move_content2(char **d_r, char *s, char *p, char *delimiters, char *d_end)
{
	// move content
	while (*s && !isspace(*s) && !strchr(delimiters, *s) && *d_r < d_end)
		*((*d_r)++) = *s++;
	**d_r = '\0';
	
	// check is left content
	if (*d_r >= d_end)
		return (RC_OVERFLOW);
		
	if (!*s)
		return (RC_NONE);

	// move leftover to source
	ft_strlcpy(p, s, -1);
	return (RC_CTX | RC_CONT);
}

int	move_content(char **d_r, char *s, char *delimiters, char *d_end)
{
	char	*p;

	p = s;
	// skip white space
	while (isspace(*s) && !strchr(delimiters, *s))
		s++;

	if (*s && strchr(delimiters, *s))
	{
		ft_strlcpy(p, s + 1, -1);
		return (RC_DELIMITER | RC_CONT);
	}

	return (move_content2(d_r, s, p, delimiters, d_end));
}

ssize_t	read_content(int fd, char *str, size_t size, char *delimiters)
{
	static char	buffer[BUFFER_SIZE];
	char 		*cur;
	ssize_t		nb_bytes;
	int			ret;

	cur = str;
	str[0] = '\0';
	ret = move_content(&cur, buffer, delimiters, str + size);
	while (1)
	{
		if (ret)
			return (ret);
		nb_bytes = read(fd, buffer, sizeof(buffer) - 1);
		write(2, buffer, nb_bytes);
		write(2, "|", 1);
		if (nb_bytes < 0)
		{
			buffer[0] = '\0';
			return (RC_ERROR);
		}
		buffer[nb_bytes] = '\0';
		if (nb_bytes == 0 && str[0])
			return (RC_CTX);
		else if (nb_bytes == 0)
			return (RC_NONE);
		ret = move_content2(&cur, buffer, buffer, delimiters, str + size);

	}
}

int main()
{
	int 	fd;
	char	str[BUFFER_SIZE];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("test.txt");
		return (1);
	}
	int ret = RC_CONT;
	while (ret & RC_CONT)
	{
		ret = read_content(fd, str, 12, "\n");
		if (ret & RC_CTX)
			printf("%s - ", str);
		else if (ret & RC_DELIMITER)
			printf("\\n\n");
	}
	if (ret & RC_OVERFLOW)
	{
		printf("content: %s\n", str);
		printf("\nOVERFLOW\n");
	}
	return (0);
}
