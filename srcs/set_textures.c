#include "../include/cub3d.h"

int	set_tex_north(t_cub *cub, char *line)
{
	if (cub->set.set_NO == 1 || ft_strlen(line) <= 2)
		return (error_out(cub, "Double key (NORTH)"));
	cub->index = 2;
	space_skip(cub, line);
	if (line[cub->index] != '.' || line[cub->index + 1] != '/'
		|| line[2] != ' ')
		return (error_out(cub, "Wrong texture path (NORTH)"));
	cub->tex_n.path = get_path(cub, line);
	if (cub->tex_n.path == NULL)
		return (error_out(cub, "Malloc (path error)"));
	if (check_valid_path(cub->tex_n.path))
		return (cub->set.set_NO = 1);
	return (error_out(cub, "Wrong texture path (NORTH)"));
}

int	set_tex_south(t_cub *cub, char *line)
{
	if (cub->set.set_SO == 1 || ft_strlen(line) <= 2)
		return (error_out(cub, "Double key (SOUTH)"));
	cub->index = 2;
	space_skip(cub, line);
	if (line[cub->index] != '.' || line[cub->index + 1] != '/'
		|| line[2] != ' ')
		return (error_out(cub, "Wrong texture path (SOUTH)"));
	if (line[cub->index] != '.' || line[cub->index + 1] != '/')
		return (error_out(cub, "Wrong texture path (SOUTH)"));
	cub->tex_s.path = get_path(cub, line);
	if (cub->tex_s.path == NULL)
		return (error_out(cub, "Malloc (path error)"));
	if (check_valid_path(cub->tex_s.path))
		return (cub->set.set_SO = 1);
	return (error_out(cub, "Wrong texture path (SOUTH)"));
}

int	set_tex_west(t_cub *cub, char *line)
{
	if (cub->set.set_WE == 1 || ft_strlen(line) <= 2)
		return (error_out(cub, "Double key (WEST)"));
	cub->index = 2;
	space_skip(cub, line);
	if (line[cub->index] != '.' || line[cub->index + 1] != '/'
		|| line[2] != ' ')
		return (error_out(cub, "Wrong texture path (WEST)"));
	cub->tex_w.path = get_path(cub, line);
	if (cub->tex_w.path == NULL)
		return (error_out(cub, "Malloc (path error)"));
	if (check_valid_path(cub->tex_w.path))
		return (cub->set.set_WE = 1);
	return (error_out(cub, "Wrong texture path (WEST)"));
}

int	set_tex_east(t_cub *cub, char *line)
{
	if (cub->set.set_EA == 1 || ft_strlen(line) <= 2)
		return (error_out(cub, "Double key (EAST)"));
	cub->index = 2;
	space_skip(cub, line);
	if (line[cub->index] != '.' || line[cub->index + 1] != '/'
		|| line[2] != ' ')
		return (error_out(cub, "Wrong texture path (EAST)"));
	cub->tex_e.path = get_path(cub, line);
	if (cub->tex_e.path == NULL)
		return (error_out(cub, "Malloc (path error)"));
	if (check_valid_path(cub->tex_e.path))
		return (cub->set.set_EA = 1);
	return (error_out(cub, "Wrong texture path (EAST)"));
}

int	set_tex_sprite(t_cub *cub, char *line)
{
	if (cub->set.set_SP == 1 || ft_strlen(line) <= 2)
		return (error_out(cub, "Double key (SPRITE)"));
	cub->index = 1;
	space_skip(cub, line);
	if (line[cub->index] != '.' || line[cub->index + 1] != '/'
		|| line[1] != ' ')
		return (error_out(cub, "Wrong texture path (SPRITE)"));
	cub->tex_sp.path = get_path(cub, line);
	if (cub->tex_sp.path == NULL)
		return (error_out(cub, "Malloc (path error)"));
	if (check_valid_path(cub->tex_sp.path))
		return (cub->set.set_SP = 1);
	return (error_out(cub, "Wrong texture path (SPRITE)"));
}
