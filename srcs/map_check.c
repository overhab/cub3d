#include "../include/cub3d.h"

int	map_checkk(char *map, int len)
{
	int	d;

	d = 0;
	while (map[d] == ' ')
		d++;
	if (map[d] != '1' || map[len - 1] != '1')
		return (-1);
	while (map[d] != '\0')
	{
		if (!ft_strchr_plus("NSEW120 ", map[d]))
			return (-1);
		d++;
	}
	return (0);
}

int	map_compare_hard(char *map1, char *map2, char *map3, int d)
{
	int	f;

	f = 1;
	f *= ft_strchr_plus("102NSEW", map2[d - 1]);
	f *= ft_strchr_plus("102NSEW", map2[d]);
	f *= ft_strchr_plus("102NSEW", map2[d + 1]);
	f *= ft_strchr_plus("102NSEW", map3[d - 1]);
	f *= ft_strchr_plus("102NSEW", map3[d]);
	f *= ft_strchr_plus("102NSEW", map3[d + 1]);
	f *= ft_strchr_plus("102NSEW", map1[d - 1]);
	f *= ft_strchr_plus("102NSEW", map1[d + 1]);
	if (f == 0)
		return (-1);
	return (0);
}

int	map_compare(t_cub *cub, int e)
{
	int	d;

	d = 0;
	while (cub->map[e][d] == ' ')
		d++;
	while (cub->map[e][d] != '\0')
	{
		if (cub->map[e][d] == '0' || cub->map[e][d] == '2'
				|| ft_strchr_plus("NEWS", cub->map[e][d]))
			if (map_compare_hard(cub->map[e], cub->map[e - 1],
					cub->map[e + 1], d) == -1)
				return (error_out(cub, "Wrong map format"));
		d++;
	}
	return (0);
}

int	map_first_last(t_cub *cub)
{
	int	d;
	int	e;

	e = 0;
	d = 0;
	while (cub->map[e][d] != '\0')
	{
		while (cub->map[e][d] == ' ')
			d++;
		if (cub->map[e][d] != '1')
			return (error_out(cub, "Wrong map format"));
		d++;
		if (cub->map[e][d] == '\0' && e == 0)
		{
			d = 0;
			e = cub->len - 1;
		}
	}
	return (0);
}

int	map_check(t_cub *cub)
{
	int	e;
	int	len;

	e = 1;
	while (e < (cub->len - 1))
	{
		scan_for_player(cub, cub->map[e]);
		len = ft_strlen(cub->map[e]);
		if (map_checkk(cub->map[e], len) == -1)
			return (error_out(cub, "Wrong map format"));
		if (map_compare(cub, e) == -1)
			return (-1);
		e++;
	}
	if (cub->plr_cnt > 1 || cub->plr_cnt == 0)
		return (error_out(cub, "Wrong map config"));
	if (!map_first_last(cub))
		return (cub->set.set_MAP = 1);
	return (0);
}
