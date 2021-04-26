#include "../include/cub3d.h"

void	scan_for_player(t_cub *cub, char *map)
{
	int	d;

	d = 0;
	while (map[d] != '\0')
	{
		if (ft_strchr_plus("NSEW", map[d]))
			cub->plr_cnt++;
		if (map[d] == '2')
			cub->spr_cnt++;
		d++;
	}
}

int	key_release(int key, t_cub *cub)
{
	if (key == W)
		cub->set.key_w = 0;
	if (key == S)
		cub->set.key_s = 0;
	if (key == D)
		cub->set.key_d = 0;
	if (key == A)
		cub->set.key_a = 0;
	if (key == LEFTK)
		cub->set.key_lft = 0;
	if (key == RIGHTK)
		cub->set.key_rght = 0;
	return (0);
}

int	key_press(int key, t_cub *cub)
{
	if (key == W)
		cub->set.key_w = 1;
	if (key == S)
		cub->set.key_s = 1;
	if (key == D)
		cub->set.key_d = 1;
	if (key == A)
		cub->set.key_a = 1;
	if (key == LEFTK)
		cub->set.key_lft = 1;
	if (key == RIGHTK)
		cub->set.key_rght = 1;
	if (key == ESC)
		close_win(cub);
	return (0);
}

int	is_it_map(t_cub *cub)
{
	if (cub->set.set_R && cub->set.set_CF && cub->set.set_CC
		&& cub->set.set_NO && cub->set.set_SO && cub->set.set_WE
		&& cub->set.set_EA && cub->set.set_SP)
		return (1);
	return (cub->error == -2);
}

void	space_skip(t_cub *cub, const char *nptr)
{
	while ((nptr[cub->index] == ' ') || (nptr[cub->index] == '\n')
		|| (nptr[cub->index] == '\f') || (nptr[cub->index] == '\v')
		|| (nptr[cub->index] == '\r') || (nptr[cub->index] == '\t'))
		cub->index++;
}
