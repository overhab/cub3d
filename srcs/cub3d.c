#include "../include/cub3d.h"

t_mlx	init_texture(void)
{
	t_mlx	tex;

	tex.mlx = NULL;
	tex.win = NULL;
	tex.img = NULL;
	tex.addr = NULL;
	tex.bpp = 0;
	tex.line_l = 0;
	tex.en = 0;
	tex.width = 0;
	tex.height = 0;
	tex.side = 0;
	tex.path = NULL;
	return (tex);
}

t_set	init_settings(void)
{
	t_set	set;

	set.floor_c = 0;
	set.set_R = 0;
	set.set_CF = 0;
	set.set_CC = 0;
	set.set_NO = 0;
	set.set_SO = 0;
	set.set_WE = 0;
	set.set_EA = 0;
	set.set_SP = 0;
	set.set_MAP = 0;
	set.ceiling_c = 0;
	set.key_w = 0;
	set.key_s = 0;
	set.key_d = 0;
	set.key_a = 0;
	set.key_lft = 0;
	set.key_rght = 0;
	return (set);
}

void	ft_init(char *file, int save)
{
	t_cub		cub;
	t_test		test;

	cub.mlx = init_texture();
	cub.tex_n = init_texture();
	cub.tex_s = init_texture();
	cub.tex_w = init_texture();
	cub.tex_e = init_texture();
	cub.tex_sp = init_texture();
	cub.tex = init_texture();
	cub.color = init_texture();
	cub.set = init_settings();
	test.fov = M_PI / 3;
	test.ray_dis = 0;
	cub.sprite = NULL;
	cub.map = NULL;
	cub.rlen = 0;
	cub.plr_cnt = 0;
	cub.spr_cnt = 0;
	cub.begin = 0;
	cub.err_out = 0;
	cub.test = test;
	cub.error = 0;
	cub.screen_shot = save;
	ft_parsing(file, &cub);
}

int	check_file(char *path)
{
	int	len;
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_putendl("Error\nFile is a derictory");
		return (0);
	}
	len = ft_strlen(path);
	if (path[len - 1] == 'b' && path[len - 2] == 'u' && path[len - 3] == 'c'
		&& path[len - 4] == '.')
		return (1);
	ft_putendl("Error\nInvalid argument(s)");
	return (0);
}

int	main(int ac, char **av)
{
	int	save;

	save = 0;
	if (ac == 3 && check_file(av[1]))
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
		{
			save = 1;
			ft_init(av[1], save);
		}
		else
			ft_putendl("Error\nInvalid argument(s)");
	}
	else if (ac == 2 && check_file(av[1]))
		ft_init(av[1], save);
	if (ac > 3 || ac < 2)
		ft_putendl("Error\nInvalid argument(s)");
	return (0);
}
