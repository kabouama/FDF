/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:25:34 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 00:33:08 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*stock_buff(const int fd, char *str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	while ((!ft_strchr(str, '\n') && (ret = read(fd, buff, BUFF_SIZE))))
	{
		buff[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buff)))
			str = NULL;
		free(tmp);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	char			*tmp;
	static char		*str[4096];

	if (fd < 0 || !line || (read(fd, *line, 0) < 0) || BUFF_SIZE <= 0)
		return (-1);
	if (!str[fd] && !(str[fd] = ft_strnew(0)))
		return (-1);
	str[fd] = stock_buff(fd, str[fd]);
	if (str[fd] == NULL)
		return (-1);
	i = 0;
	if (str[fd][i])
	{
		while (str[fd][i] && str[fd][i] != '\n')
			i++;
		tmp = str[fd];
		*line = ft_strsub(str[fd], 0, i);
		str[fd] = ft_strsub(str[fd], ++i, ft_strlen(str[fd]) -
				ft_strlen(*line));
		free(tmp);
		return (1);
	}
	return (0);
}
