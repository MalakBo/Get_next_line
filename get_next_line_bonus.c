/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:40:31 by mbouyi            #+#    #+#             */
/*   Updated: 2025/01/04 22:38:00 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_buffer(int fd, char *res)
{
	ssize_t	i;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(res);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		res = ft_strjoin(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_f(char *res)
{
	int		i;
	char	*line;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = ft_substr(res, 0, i);
	return (line);
}

char	*get_n(char *res)
{
	int		i;
	char	*line;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = ft_substr(res, i, ft_strlen(res) - i);
	free(res);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res[fd] = get_buffer(fd, res[fd]);
	if (!res[fd] || *res[fd] == '\0')
	{
		if (res[fd])
			free(res[fd]);
		res[fd] = NULL;
		return (NULL);
	}
	line = get_f(res[fd]);
	res[fd] = get_n(res[fd]);
	return (line);
}
