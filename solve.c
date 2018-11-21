/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:22:11 by yholub            #+#    #+#             */
/*   Updated: 2018/04/02 16:22:12 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	prepare_map(char **map, t_filler *stu)
{
	int y;
	int x;

	y = 0;
	while (y < stu->map_y)
	{
		x = 0;
		while (x < stu->map_x)
		{
			if (map[y][x] == stu->op_ch || map[y][x] == stu->op_hl)
				map[y][x] = 122;
			if (map[y][x] == stu->pl_ch || map[y][x] == stu->pl_hl)
				map[y][x] = 123;
			x++;
		}
		y++;
	}
}

int		check_full(char **map, t_filler *stu)
{
	int y;
	int x;

	y = 0;
	while (y < stu->map_y)
	{
		x = 0;
		while (x < stu->map_x)
		{
			if (map[y][x] == '.')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	fill_ar(char **map, t_sol *s, t_filler *stu)
{
	if (s->x - 1 >= 0)
		if (map[s->y][s->x - 1] == '.')
			map[s->y][s->x - 1] = s->i;
	if (s->x + 1 < stu->map_x)
		if (map[s->y][s->x + 1] == '.')
			map[s->y][s->x + 1] = s->i;
	if (s->y > 0)
		if (map[s->y - 1][s->x] == '.')
			map[s->y - 1][s->x] = s->i;
	if (s->y + 1 < stu->map_y)
		if (map[s->y + 1][s->x] == '.')
			map[s->y + 1][s->x] = s->i;
	if (s->y > 0 && s->x - 1 >= 0)
		if (map[s->y - 1][s->x - 1] == '.')
			map[s->y - 1][s->x - 1] = s->i;
	if (s->y > 0 && s->x + 1 < stu->map_x)
		if (map[s->y - 1][s->x + 1] == '.')
			map[s->y - 1][s->x + 1] = s->i;
	if (s->y + 1 < stu->map_y && s->x - 1 >= 0)
		if (map[s->y + 1][s->x - 1] == '.')
			map[s->y + 1][s->x - 1] = s->i;
	if (s->y + 1 < stu->map_y && s->x + 1 < stu->map_x)
		if (map[s->y + 1][s->x + 1] == '.')
			map[s->y + 1][s->x + 1] = s->i;
}

void	fill_map(char **map, t_filler *stu)
{
	t_sol	*s;
	char	i;

	s = (t_sol*)malloc(sizeof(s));
	i = 122;
	s->i = 1;
	prepare_map(map, stu);
	while (check_full(map, stu) == 1)
	{
		s->y = -1;
		while (++s->y < stu->map_y)
		{
			s->x = -1;
			while (++s->x < stu->map_x)
				if (map[s->y][s->x] == i)
					fill_ar(map, s, stu);
		}
		i = s->i;
		s->i++;
		if (s->i == 46)
			s->i++;
	}
	free(s);
}
