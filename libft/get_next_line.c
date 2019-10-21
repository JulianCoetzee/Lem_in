/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:51:16 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/07/26 09:57:31 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_freejoin_str(char *tmp, char *buf)
{
	char *fr;

	if (buf == NULL)
		return (NULL);
	fr = tmp;
	tmp = ft_strjoin(tmp, buf);
	free(fr);
	return (tmp);
}

static char	*ft_makeline(char **line, char *tmp)
{
	size_t	n;
	char	*fr;

	n = 0;
	while (tmp[n] != '\n' && tmp[n] != '\0')
		n++;
	*line = ft_strsub(tmp, 0, n);
	if (ft_strcmp(*line, tmp) == 0)
		ft_strdel(&tmp);
	else
	{
		fr = tmp;
		tmp = ft_strdup(tmp + n + 1);
		free(fr);
	}
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	size_t		ret;
	char		buf[BUFF_SIZE + 1];
	static char *arr[1024];

	if (BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!arr[fd])
		arr[fd] = ft_strnew(0);
	while (!ft_strchr(arr[fd], '\n')
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		arr[fd] = ft_freejoin_str(arr[fd], buf);
	}
	if (ret < BUFF_SIZE && !ft_strlen(arr[fd]))
		return (0);
	arr[fd] = ft_makeline(line, arr[fd]);
	return (1);
}
