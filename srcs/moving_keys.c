#include "../include/cub3d.h"

static	void	KEY_W(t_cub *cub)
{
	double			x;
	double			y;
	t_player		player;

	player = cub->player;
	x = player.x + cosf(cub->player.dir) * PLSPEED * 3;
	y = player.y + sinf(cub->player.dir) * PLSPEED * 3;
	if (cub->map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		cub->player.y += sinf(cub->player.dir) * PLSPEED;
		cub->player.x += cosf(cub->player.dir) * PLSPEED;
	}
}

static	void	KEY_S(t_cub *cub)
{
	double			x;
	double			y;
	t_player		player;

	player = cub->player;
	x = player.x - cosf(cub->player.dir) * PLSPEED * 3;
	y = player.y - sinf(cub->player.dir) * PLSPEED * 3;
	if (cub->map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		cub->player.y -= sinf(cub->player.dir) * PLSPEED;
		cub->player.x -= cosf(cub->player.dir) * PLSPEED;
	}
}

static	void	KEY_D(t_cub *cub)
{
	double			x;
	double			y;
	t_player		player;

	player = cub->player;
	x = player.x + cosf(cub->player.dir + M_PI_2) * PLSPEED * 3;
	y = player.y + sinf(cub->player.dir + M_PI_2) * PLSPEED * 3;
	if (cub->map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		cub->player.y += sinf(cub->player.dir + M_PI_2) * PLSPEED;
		cub->player.x += cosf(cub->player.dir + M_PI_2) * PLSPEED;
	}
}

static	void	KEY_A(t_cub *cub)
{
	double			x;
	double			y;
	t_player		player;

	player = cub->player;
	x = player.x - cosf(cub->player.dir + M_PI_2) * PLSPEED * 3;
	y = player.y - sinf(cub->player.dir + M_PI_2) * PLSPEED * 3;
	if (cub->map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		cub->player.y -= sinf(cub->player.dir + M_PI_2) * PLSPEED;
		cub->player.x -= cosf(cub->player.dir + M_PI_2) * PLSPEED;
	}
}

int	main_loop(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	if (cub->set.key_w)
		KEY_W(cub);
	if (cub->set.key_s)
		KEY_S(cub);
	if (cub->set.key_d)
		KEY_D(cub);
	if (cub->set.key_a)
		KEY_A(cub);
	if (cub->set.key_lft)
		cub->player.dir -= 0.05;
	if (cub->set.key_rght)
		cub->player.dir += 0.05;
	if (cub->player.dir > M_PI * 2)
		cub->player.dir -= M_PI * 2;
	if (cub->player.dir < 0)
		cub->player.dir += M_PI * 2;
	draw_screen(cub);
	return (0);
}
