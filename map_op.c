/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:06:54 by yholub            #+#    #+#             */
/*   Updated: 2018/04/06 11:06:54 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_mapsize(char *buff, t_filler *stu)
{
	int i;

	i = 0;
	while (buff[i++])
		if (ft_isdigit(buff[i]))
		{
			stu->map_y = ft_atoi(buff + i);
			while (ft_isdigit(buff[i]))
				i++;
			break ;
		}
	while (buff[i++])
		if (ft_isdigit(buff[i]))
		{
			stu->map_x = ft_atoi(buff + i);
			break ;
		}
}

char	**init_map(char *str, t_filler *stu)
{
	char	**res;
	int		i;
	int		y;
	int		x;

	i = 0;
	res = (char**)malloc(sizeof(*res) * stu->map_y + 1);
	i = i + stu->map_x + 6;
	y = 0;
	while (y < stu->map_y)
	{
		res[y] = (char*)malloc(sizeof(char) * stu->map_x + 1);
		i = i + 4;
		x = 0;
		while (x < stu->map_x)
			res[y][x++] = str[i++];
		res[y++][x] = '\0';
		i++;
	}
	res[y] = 0;
	return (res);
}

void	symb_count(char **fig, t_filler *stu)
{
	int y;
	int x;
	int res;

	y = 0;
	res = 0;
	while (fig[y])
	{
		x = 0;
		while (fig[y][x])
		{
			if (fig[y][x] == '*')
				res++;
			x++;
		}
		y++;
	}
	stu->p_cou = res;
}

void	fig_coord(char **fig, t_filler *stu)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	symb_count(fig, stu);
	stu->mass_p = (int**)malloc(sizeof(int*) * stu->p_cou + 1);
	while (fig[y])
	{
		x = -1;
		while (fig[y][++x])
		{
			if (fig[y][x] == '*')
			{
				stu->mass_p[i] = (int*)malloc(sizeof(int) * 2 + 1);
				stu->mass_p[i][0] = y;
				stu->mass_p[i][1] = x;
				stu->mass_p[i][2] = '\0';
				i++;
			}
		}
		y++;
	}
	stu->mass_p[i] = 0;
}

char	**init_fig(char *str, t_filler *stu)
{
	char	**res;
	int		i;
	int		y;
	int		x;

	i = 0;
	res = (char**)malloc(sizeof(*res) * stu->p_y + 1);
	y = 0;
	while (y < stu->p_y)
	{
		res[y] = (char*)malloc(sizeof(char) * stu->p_x + 1);
		x = 0;
		while (x < stu->p_x)
			res[y][x++] = str[i++];
		res[y++][x] = '\0';
		i++;
	}
	res[y] = 0;
	fig_coord(res, stu);
	return (res);
}
