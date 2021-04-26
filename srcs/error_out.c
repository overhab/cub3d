#include "../include/cub3d.h"

int	error_out(t_cub *cub, char *error)
{
	if (cub->err_out == 0)
	{
		ft_putendl("Error");
		ft_putendl(error);
	}
	cub->err_out = 1;
	return (cub->error = -1);
}

int	ft_freedom(t_cub *cub)
{
	if (cub->rlen)
		free(cub->rlen);
	if (cub->sprite)
		free(cub->sprite);
	exit_tex(cub);
	clear_textures(cub);
	if (cub->map != NULL)
		clear_map(cub->map, (cub->len - 1));
	return (0);
}

void	clear_map(char **map, int size)
{
	while (size >= 0)
	{
		if (map[size])
			free(map[size]);
		size--;
	}
	if (map)
		free(map);
}

void	clear_textures(t_cub *cub)
{
	if (cub->tex_n.path != NULL)
		free(cub->tex_n.path);
	if (cub->tex_s.path != NULL)
		free(cub->tex_s.path);
	if (cub->tex_w.path != NULL)
		free(cub->tex_w.path);
	if (cub->tex_e.path != NULL)
		free(cub->tex_e.path);
	if (cub->tex_sp.path != NULL)
		free(cub->tex_sp.path);
	cub->tex_n.path = NULL;
	cub->tex_s.path = NULL;
	cub->tex_e.path = NULL;
	cub->tex_w.path = NULL;
	cub->tex_sp.path = NULL;
}

void	exit_tex(t_cub *cub)
{
	if (cub->tex_n.img)
		mlx_destroy_image(cub->mlx.mlx, cub->tex_n.img);
	if (cub->tex_s.img)
		mlx_destroy_image(cub->mlx.mlx, cub->tex_s.img);
	if (cub->tex_w.img)
		mlx_destroy_image(cub->mlx.mlx, cub->tex_w.img);
	if (cub->tex_e.img)
		mlx_destroy_image(cub->mlx.mlx, cub->tex_e.img);
	if (cub->tex_sp.img)
		mlx_destroy_image(cub->mlx.mlx, cub->tex_sp.img);
}
