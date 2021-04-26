#include "../include/cub3d.h"

int	set_resolution(t_cub *cub, char *line)
{
	if (cub->set.set_R == 1 || ft_strlen(line) <= 1)
		return (error_out(cub, "Double key (Resolution)"));
	cub->index = 1;
	if (search_for_char(line, cub))
		return (error_out(cub, "Wrong resolution"));
	cub->set.res_w = ft_atoi(cub, line);
	cub->set.res_h = ft_atoi(cub, line);
	space_skip(cub, line);
	cub->index++;
	if (cub->set.res_w > 1920)
		cub->set.res_w = 1920;
	if (cub->set.res_h > 1080)
		cub->set.res_h = 1080;
	if (cub->set.res_w <= 0 || cub->set.res_h <= 0
		|| line[cub->index - 1] != '\0')
		return (error_out(cub, "Wrong resolution"));
	return (cub->set.set_R = 1);
}

int	check_color_format(t_cub *cub, char *line)
{
	int	comma;

	comma = 0;
	cub->index = 1;
	if (cub->set.set_CF == 1 && line[0] == 'F')
		return (1);
	if (cub->set.set_CC == 1 && line[0] == 'C')
		return (1);
	while (line[cub->index] != '\0')
	{
		space_skip(cub, line);
		if (line[cub->index] == '\0')
			break ;
		if (line[cub->index] == ',')
			comma++;
		if (!(ft_isdigit(line[cub->index])) && line[cub->index] != ',')
			return (1);
		cub->index++;
	}
	if (comma != 2)
		return (1);
	return (check_color_two(cub, line));
}

int	set_colors(t_cub *cub, char *line, char ch)
{
	int	r;
	int	g;
	int	b;

	if (check_color_format(cub, line))
		return (error_out(cub, "Wrong color setting"));
	cub->index = 1;
	r = ft_atoi_color(cub, line);
	g = ft_atoi_color(cub, line);
	b = ft_atoi_color(cub, line);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		return (error_out(cub, "Wrong color setting"));
	if (ch == 'F')
	{
		cub->set.floor_c = r * 256 * 256 + g * 256 + b;
		cub->set.set_CF = 1;
	}
	if (ch == 'C')
	{
		cub->set.ceiling_c = r * 256 * 256 + g * 256 + b;
		cub->set.set_CC = 1;
	}
	return (1);
}

int	check_settings(t_cub *cub)
{
	if (cub->error == -1)
		return (0);
	map_check(cub);
	if (cub->error == -1)
		return (0);
	if (cub->set.set_R && cub->set.set_CF && cub->set.set_CC
		&& cub->set.set_NO && cub->set.set_SO && cub->set.set_WE
		&& cub->set.set_EA && cub->set.set_SP && cub->set.set_MAP)
	{
		cub->rlen = (double *)malloc((cub->set.res_w + 4) * sizeof(double));
		if (cub->rlen == NULL)
			return (error_out(cub, "Malloc error (ray len)"));
		return (1);
	}
	return (0);
}

int	ft_is_space(t_cub *cub, char *str)
{
	int	d;
	int	error;

	d = 0;
	error = 0;
	if (str[0] != ' ' && str[0] != '1')
		return (1);
	while (str[d] != '\0')
	{
		if (str[d] != ' ')
		{
			if (str[d] == '1')
				return (is_it_map(cub));
			error++;
		}
		d++;
	}
	if (error > 0)
		return (error_out(cub, "Config error"));
	return (0);
}
