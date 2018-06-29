/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 18:09:11 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 18:58:56 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	void	fill_line(char **line, char *buff)
{
	char	*tmp;

	tmp = NULL;
	if (!*line)
		*line = ft_strdup(buff);
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
}

static int		get_tmp(char **line, char **tmp_st, char *buff)
{
	int		b_n;

	b_n = ft_char_pos(buff, '\n');
	buff[b_n] = 0;
	fill_line(line, buff);
	buff[b_n] = '\n';
	if (buff[b_n + 1] != 0)
		*tmp_st = ft_strsub(buff, b_n + 1, ft_strlen(&buff[b_n + 1]));
	return (1);
}

static int		read_fd(int fd, char **line, char **tmp_st)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		b_n;

	while ((ret = read(fd, buff, BUFF_SIZE)) && ret != -1)
	{
		buff[ret] = 0;
		if (ft_strchr(buff, '\n'))
		{
			b_n = ft_char_pos(buff, '\n');
			if (buff[b_n + 1] != 0 || ret == BUFF_SIZE)
				return (get_tmp(line, tmp_st, buff));
			buff[b_n] = 0;
		}
		fill_line(line, buff);
	}
	if (ret <= 0)
		return (ret);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*tmp_st = NULL;
	int			ret;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (tmp_st)
	{
		if (ft_strrchr(tmp_st, '\n'))
		{
			tmp = tmp_st;
			get_tmp(line, &tmp_st, tmp);
			tmp == tmp_st ? ft_strdel(&tmp_st) : ft_strdel(&tmp);
			return (1);
		}
		fill_line(line, tmp_st);
		if (*tmp_st)
			ft_strdel(&tmp_st);
	}
	ret = read_fd(fd, line, &tmp_st);
	return (*line ? 1 : ret);
}
