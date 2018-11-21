/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:56:14 by yholub            #+#    #+#             */
/*   Updated: 2018/04/06 10:56:15 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_print(t_solve *sol)
{
	if (sol->res == 2147483647)
		return (0);
	else
	{
		ft_putnbr(sol->y);
		ft_putchar(' ');
		ft_putnbr(sol->x);
		ft_putchar('\n');
		free(sol);
		return (1);
	}
}

int		normalize(char *str, t_filler *stu)
{
	char	**map;
	char	**fig;
	char	*f;
	t_solve *sol;

	map = init_map(str, stu);
	f = get_fig(stu);
	fig = init_fig(f, stu);
	sol = solve_filler(map, stu);
	if (check_print(sol) == 1)
		return (1);
	return (0);
}

int		main(void)
{
	char		*buff;
	t_filler	*stu;
	char		*str;

	stu = (t_filler*)malloc(sizeof(t_filler));
	get_next_line(0, &buff);
	if (buff[1] == '$')
		get_player(buff, stu);
	while (1)
	{
		get_next_line(0, &buff);
		if (ft_strstr(buff, "Plateau"))
		{
			get_mapsize(buff, stu);
			str = get_map(stu);
		}
		if (normalize(str, stu) == 0)
		{
			ft_putstr("0 0\n");
			return (0);
		}
		free(buff);
		free(str);
	}
	return (0);
}
