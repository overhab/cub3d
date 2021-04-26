#include "../include/cub3d.h"

void	draw_sprites(t_cub *cub, t_sprite spr, int i)
{
	int	texx;
	int	texy;
	int	d;	

	i = -1;
	while (++i < spr.size)
	{
		if (spr.draw_x + i > cub->set.res_w || spr.draw_x + i < 0
			|| cub->rlen[i + (int)spr.draw_x] < spr.dist)
			continue ;
		texx = i / spr.size * cub->tex_sp.width;
		spr.tex_pos = 0;
		d = -1;
		while (++d < spr.size)
		{
			texy = (unsigned int)spr.tex_pos & ((cub->tex_sp.height) - 1);
			sprite_color(cub, texx, texy, &spr);
			spr.tex_pos += spr.step;
			if (spr.draw_y + d > cub->set.res_h || spr.draw_y + d < 0)
				continue ;
			if (*spr.clr != 0x0)
				pixel_put(&cub->mlx, spr.draw_x + i, spr.draw_y + d, *spr.clr);
		}
	}
}

void	sorting_plus(t_cub *cub)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < (cub->spr_cnt - 1))
	{
		if (cub->sprite[i].dist < cub->sprite[i + 1].dist)
		{
			tmp = cub->sprite[i];
			cub->sprite[i] = cub->sprite[i + 1];
			cub->sprite[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

void	sprite_calc(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->spr_cnt)
	{
		cub->sprite[i].angle = atan2(cub->sprite[i].y - cub->player.y,
				cub->sprite[i].x - cub->player.x);
		cub->sprite[i].dist = sqrt(pow((cub->player.x - cub->sprite[i].x), 2)
				+ pow((cub->player.y - cub->sprite[i].y), 2));
		angle_size(cub, i);
		cub->sprite[i].angle -= cub->player.dir;
		cub->sprite[i].draw_x = (cub->sprite[i].angle)
			* cub->set.res_w / (cub->test.fov)
			+ (cub->set.res_w / 2 - cub->sprite[i].size / 2);
		cub->sprite[i].draw_y = (cub->set.res_h / 2)
			- (cub->sprite[i].size / 2);
		cub->sprite[i].step = cub->tex_sp.height / cub->sprite[i].size;
		cub->sprite[i].tex_pos = 0;
		i++;
	}
}

void	sprite_sort(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->spr_cnt)
	{
		cub->sprite[i].dist = sqrt(pow((cub->player.x - cub->sprite[i].x), 2)
				+ pow((cub->player.y - cub->sprite[i].y), 2));
		i++;
	}
	sorting_plus(cub);
	sprite_calc(cub);
	i = 0;
	while (i < cub->spr_cnt)
	{
		draw_sprites(cub, cub->sprite[i], i);
		i++;
	}
}

int	scan_for_sprites(t_cub *cub)
{
	t_pos	pos;
	int		i;

	i = 0;
	ft_bzero(&pos, sizeof(t_pos));
	cub->sprite = (t_sprite *)malloc((cub->spr_cnt) * sizeof(t_sprite));
	if (cub->sprite == NULL)
		return (error_out(cub, "Malloc error /sprite"));
	while (cub->map[(int)pos.y])
	{
		pos.x = 0;
		while (cub->map[(int)pos.y][(int)pos.x])
		{
			if (cub->map[(int)pos.y][(int)pos.x] == '2')
			{
				if (i < cub->spr_cnt)
					init_sprites(cub, pos, i);
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
