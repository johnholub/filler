/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:24:51 by yholub            #+#    #+#             */
/*   Updated: 2018/03/29 15:24:58 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct		s_filler
{
	int				pl;
	int				op;
	char			pl_ch;
	char			pl_hl;
	char			op_ch;
	char			op_hl;
	int				map_x;
	int				map_y;
	int				p_cou;
	int				p_x;
	int				p_y;
	int				**mass_p;
}					t_filler;

typedef struct		s_solve
{
	int				x;
	int				y;
	int				res;
}					t_solve;

typedef struct		s_sol
{
	int				x;
	int				y;
	char			i;
}					t_sol;

char				*get_map(t_filler *stu);
void				get_player(char *str, t_filler *stu);
void				get_mapsize(char *buff, t_filler *stu);
char				**init_map(char *str, t_filler *stu);
char				**init_fig(char *str, t_filler *stu);
char				*get_fig(t_filler *stu);
t_solve				*solve_filler(char **map, t_filler *stu);
void				fill_map(char **map, t_filler *stu);

#endif
