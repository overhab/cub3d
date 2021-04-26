#include "../include/cub3d.h"

void	angle_size(t_cub *cub, int i)
{
	while ((cub->sprite[i].angle - cub->player.dir) > M_PI)
		cub->sprite[i].angle -= (2.0 * M_PI);
	while ((cub->sprite[i].angle - cub->player.dir) < -M_PI)
		cub->sprite[i].angle += (2.0 * M_PI);
	if (cub->set.res_w > cub->set.res_h)
		cub->sprite[i].size = ((cub->set.res_h * SCALE)
				/ (cub->sprite[i].dist)) + 6;
	else if (cub->set.res_h > cub->set.res_w)
		cub->sprite[i].size = ((cub->set.res_h * SCALE)
				/ cub->sprite[i].dist) + 25;
	else if (cub->set.res_h == cub->set.res_w)
		cub->sprite[i].size = ((cub->set.res_h)
				/ cub->sprite[i].dist * SCALE) + 10;
}

int	init_sprites(t_cub *cub, t_pos pos, int i)
{
	if (i == cub->spr_cnt)
		return (-1);
	cub->sprite[i].x = pos.x * SCALE + (SCALE / 2);
	cub->sprite[i].y = pos.y * SCALE + (SCALE / 2);
	return (0);
}

void	sprite_color(t_cub *cub, int x, int y, t_sprite *spr)
{
	spr->clr = (unsigned int *)(cub->tex_sp.addr + (y * cub->tex_sp.line_l
				+ x * (cub->tex_sp.bpp / 8)));
}
