/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:26:45 by yholub            #+#    #+#             */
/*   Updated: 2018/04/06 12:26:45 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_map(t_filler *stu)
{
	char	*str;
	char	*buff;
	int		i;

	i = 0;
	while (i <= stu->map_y)
	{
		get_next_line(0, &buff);
		str = ft_strjoin(str, buff);
		str = ft_strjoin(str, "\n");
		i++;
	}
	return (str);
}

void	get_player(char *str, t_filler *stu)
{
	if (str[10] == '1')
	{
		stu->pl = 1;
		stu->op = 2;
		stu->pl_ch = 'O';
		stu->pl_hl = 'o';
		stu->op_ch = 'X';
		stu->op_hl = 'x';
	}
	else
	{
		stu->pl = 2;
		stu->op = 1;
		stu->pl_ch = 'X';
		stu->pl_hl = 'x';
		stu->op_ch = 'O';
		stu->op_hl = 'o';
	}
}

void	get_figsize(char *buff, t_filler *stu)
{
	int i;

	i = 0;
	while (buff[i++])
		if (ft_isdigit(buff[i]))
		{
			stu->p_y = ft_atoi(buff + i);
			while (ft_isdigit(buff[i]))
				i++;
			break ;
		}
	while (buff[i++])
		if (ft_isdigit(buff[i]))
		{
			stu->p_x = ft_atoi(buff + i);
			break ;
		}
}

char	*get_fig(t_filler *stu)
{
	char	*buff;
	char	*str;
	int		i;

	i = 1;
	get_next_line(0, &buff);
	get_figsize(buff, stu);
	get_next_line(0, &buff);
	str = buff;
	str = ft_strjoin(str, "\n");
	while (i < stu->p_y)
	{
		get_next_line(0, &buff);
		str = ft_strjoin(str, buff);
		str = ft_strjoin(str, "\n");
		i++;
	}
	return (str);
}
