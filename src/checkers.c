/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkers.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 20:39:09 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 20:39:32 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <lem_in.h>

int		check_digit(char *line)
{
	int i;

	i = 0;
	while (line[i])
		if (ft_isdigit(line[i++]) == 0)
			return (1);
	if (ft_strlen(line) >= 10 && ft_strcmp(line, "2147483647") > 0)
		return (1);
	return (0);
}

int		duplicate_liaison(t_salle *salle, char **tab)
{
	t_salle			*tmp;
	t_connection	*tmp_co;

	tmp = salle;
	while (ft_strcmp(tmp->name, tab[0]) != 0)
		tmp = tmp->next;
	tmp_co = tmp->co;
	while (tmp_co)
	{
		if (ft_strcmp(tmp_co->salle->name, tab[1]) == 0)
			return (1);
		tmp_co = tmp_co->next;
	}
	return (0);
}

int		ft_check_line(t_info *colonie)
{
	char	**tmp;
	int		tab_len;

	colonie->line_split = ft_strsplit(colonie->line, ' ');
	tmp = colonie->line_split;
	tab_len = ft_tablength(tmp);
	if (tab_len == 3)
		get_room(colonie);
	else if (tab_len == 1 || tmp[0][0] == '#')
		get_other(colonie, tmp[0], tab_len);
	free_tab(tmp);
	colonie->line_split = NULL;
	return (0);
}

void	ft_check_and_add(t_info *colonie)
{
	if (colonie->nb == 0)
	{
		if (!check_digit(colonie->line))
			colonie->nb = ft_atoi(colonie->line);
		else
			ft_error(colonie);
	}
	else if (ft_check_line(colonie) == 1)
		ft_error(colonie);
}
