#include "../include/cub3d.h"

void	player_dir(t_cub *cub, t_player *player, t_pos *pos)
{
	if (cub->map[(int)pos->y][(int)pos->x] == 'N')
		player->dir = 3 * M_PI_2;
	if (cub->map[(int)pos->y][(int)pos->x] == 'S')
		player->dir = M_PI_2;
	if (cub->map[(int)pos->y][(int)pos->x] == 'E')
		player->dir = 0;
	if (cub->map[(int)pos->y][(int)pos->x] == 'W')
		player->dir = M_PI;
}

void	init_player(t_cub *cub, t_player *player)
{
	t_pos	pos;

	ft_bzero(&pos, sizeof(t_pos));
	pos.y = 0;
	while (cub->map[(int)pos.y])
	{
		pos.x = 0;
		while (cub->map[(int)pos.y][(int)pos.x])
		{
			if (ft_strchr_plus("NSEW", cub->map[(int)pos.y][(int)pos.x]))
			{
				player->x = pos.x * SCALE + (SCALE / 2);
				player->y = pos.y * SCALE + (SCALE / 2);
				player_dir(cub, player, &pos);
				break ;
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	color_height(t_cub *cub, double x, double lineH)
{
	double		drawStart;
	double		tex_y;
	double		drawEnd;
	double		tex_x;

	drawStart = (cub->set.res_h - lineH) / 2;
	drawEnd = drawStart + lineH;
	tex_x = x - drawStart;
	tex_y = drawEnd - drawStart;
	cub->cheight = 63 * tex_x / tex_y;
}

void	color_side(t_cub *cub, t_player *player)
{
	if (cub->side == 'N')
	{
		cub->color.height = (((int)player->x % SCALE));
		cub->color.addr = cub->tex_n.addr;
	}
	if (cub->side == 'S')
	{
		cub->color.height = (((int)player->x % SCALE));
		cub->color.addr = cub->tex_s.addr;
	}
	if (cub->side == 'E')
	{
		cub->color.height = (((int)player->y % SCALE));
		cub->color.addr = cub->tex_e.addr;
	}
	if (cub->side == 'W')
	{
		cub->color.height = (((int)player->y % SCALE));
		cub->color.addr = cub->tex_w.addr;
	}
}

int	getcolor_wall(t_cub *cub, t_player *player)
{
	char	*dst;
	int		color;

	color_side(cub, player);
	dst = cub->color.addr + (cub->color.height * (cub->tex_n.bpp / 8)
			+ ((int)cub->cheight) * cub->tex_n.line_l);
	color = *(int *)dst;
	return (color);
}
