#include "../include/cub3d.h"

int	ft_atoi_color(t_cub *cub, const char *nptr)
{
	int	d;
	int	k;

	k = 0;
	d = 1;
	space_skip(cub, nptr);
	if ((nptr[cub->index] == '+') || (nptr[cub->index] == '-'))
	{
		if (nptr[cub->index] == '-')
			d *= -1;
		cub->index++;
	}
	while (nptr[cub->index] >= '0' && nptr[cub->index] <= '9')
	{
		k = k * 10 + (nptr[cub->index] - '0');
		cub->index++;
	}
	space_skip(cub, nptr);
	if (nptr)
		cub->index++;
	return (k * d);
}

int	close_win(t_cub *cub)
{
	if (cub->screen_shot == -1)
		error_out(cub, "Can't make a screenshot");
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	ft_freedom(cub);
	if (cub->mlx.mlx && cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	exit(0);
	return (0);
}

static void	init_window(t_cub *cub)
{
	if (cub->screen_shot == 0)
		cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->set.res_w,
				cub->set.res_h, "cub3d");
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->set.res_w, cub->set.res_h);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
			&cub->mlx.line_l, &cub->mlx.en);
}

int	lets_go(t_cub *cub)
{
	t_player	player;

	cub->mlx.mlx = mlx_init();
	if (cub->mlx.mlx == NULL)
		return (error_out(cub, "MLX ERROR"));
	init_player(cub, &player);
	cub->player = player;
	scan_for_sprites(cub);
	xpm_func(cub);
	init_window(cub);
	if (cub->screen_shot == 1)
	{
		cub->screen_shot = make_screenshot(cub);
		close_win(cub);
	}
	mlx_hook(cub->mlx.win, 2, (1L << 0), &key_press, cub);
	mlx_loop_hook(cub->mlx.mlx, &main_loop, cub);
	mlx_hook(cub->mlx.win, 3, (1L << 1), &key_release, cub);
	mlx_hook(cub->mlx.win, 33, (1L << 17), &close_win, cub);
	mlx_loop(cub->mlx.mlx);
	return (0);
}
