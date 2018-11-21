/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:58:19 by yholub            #+#    #+#             */
/*   Updated: 2018/04/11 16:58:20 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_solve(t_solve *sol)
{
	sol->x = 99;
	sol->y = 99;
	sol->res = 2147483647;
}

int			give_res(char **map, int y, int x, t_filler *stu)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < stu->p_cou)
	{
		res = res + (int)map[y + stu->mass_p[i][0]][x + stu->mass_p[i][1]];
		i++;
	}
	return (res);
}

int			is_valid(char **map, int y, int x, t_filler *stu)
{
	int i;
	int op;
	int pl;

	i = 0;
	op = 0;
	pl = 0;
	while (i < stu->p_cou)
	{
		if (y + stu->mass_p[i][0] < stu->map_y
				&& x + stu->mass_p[i][1] < stu->map_x)
		{
			if (map[y + stu->mass_p[i][0]][x + stu->mass_p[i][1]] == 122)
				op++;
			if (map[y + stu->mass_p[i][0]][x + stu->mass_p[i][1]] == 123)
				pl++;
		}
		else
			return (0);
		i++;
	}
	if (pl == 1 && op == 0)
		return (1);
	return (0);
}

t_solve		*solve_filler(char **map, t_filler *stu)
{
	int			x;
	int			y;
	int			res;
	t_solve		*sol;

	sol = (t_solve*)malloc(sizeof(sol));
	init_solve(sol);
	fill_map(map, stu);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (is_valid(map, y, x, stu))
			{
				res = give_res(map, y, x, stu);
				if (res < sol->res)
				{
					sol->res = res;
					sol->x = x;
					sol->y = y;
				}
			}
	}
	return (sol);
}
