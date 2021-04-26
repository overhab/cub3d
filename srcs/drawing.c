#include "../include/cub3d.h"

void	pixel_put(t_mlx *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (x * (win->bpp / 8) + y * win->line_l);
	*(unsigned int *)dst = color;
}

char	side_of_wall(t_cub *cub, t_player *player)
{
	cub->player.xa = (player->x - cosf(player->start));
	cub->player.ya = (player->y - sinf(player->start));
	if (((int)player->x / SCALE == (int)cub->player.xa / SCALE
			&& (player->y > cub->player.ya)))
		return ('S');
	if (((int)player->x / SCALE == (int)cub->player.xa / SCALE
			&& (player->y < cub->player.ya)))
		return ('N');
	if (((int)player->y / SCALE == (int)cub->player.ya / SCALE
			&& (player->x > cub->player.xa)))
		return ('E');
	if (((int)player->y / SCALE == (int)cub->player.ya / SCALE
			&& (player->x < cub->player.xa)))
		return ('W');
	else
		return (0);
}

void	ft_drawline(t_cub *cub, double ray_count, t_player *player)
{
	t_pos			draw;
	size_t			walldist;
	unsigned int	color;
	int				lineHeight;

	walldist = (double)cub->test.ray_dis * cosf(player->start - player->dir);
	if (walldist == 0)
		walldist = 1;
	lineHeight = ((cub->set.res_h * SCALE) / walldist);
	cub->rlen[(int)(ray_count)] = cub->test.ray_dis;
	draw.x = cub->set.res_h / 2 - lineHeight / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = cub->set.res_h / 2 + lineHeight / 2;
	if (draw.y >= cub->set.res_h)
		draw.y = cub->set.res_h - 1;
	cub->side = side_of_wall(cub, player);
	while (draw.x < draw.y)
	{		
		color_height(cub, draw.x, lineHeight);
		color = getcolor_wall(cub, player);
		pixel_put(&cub->mlx, (ray_count - 1), draw.x, color);
		draw.x++;
	}
}

void	draw_rays(t_cub *cub, t_player *plr)
{
	t_player	pl;
	double		ray_count;

	ray_count = 0;
	pl = cub->player;
	pl.start = pl.dir - (cub->test.fov / 2);
	pl.end = pl.dir + (cub->test.fov / 2);
	while (pl.start <= pl.end)
	{
		pl.x = plr->x;
		pl.y = plr->y;
		cub->test.ray_dis = 0;
		while ((cub->map[(int)(pl.y / SCALE)][(int)(pl.x / SCALE)] != '1'))
		{
			pl.x += cos(pl.start);
			pl.y += sin(pl.start);
			cub->test.ray_dis++;
		}
		ray_count += 1;
		ft_drawline(cub, ray_count, &pl);
		pl.start += cub->test.fov / cub->set.res_w;
	}	
}

void	draw_screen(t_cub *cub)
{
	if (cub->screen_shot == 1)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->set.res_w, cub->set.res_h);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
			&cub->mlx.line_l, &cub->mlx.en);
	draw_background(cub);
	draw_rays(cub, &cub->player);
	sprite_sort(cub);
	if (cub->screen_shot == 0)
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
}
