#include "../include/cub3d.h"

int	check_what(t_cub *cub, char *line)
{
	if (cub->begin == 1)
		return (0);
	cub->index = 0;
	if (ft_is_space(cub, line) != 1 && ft_is_space(cub, line) != 0)
		return (cub->error = -2);
	if (is_it_map(cub) != 1)
	{
		while (line[cub->index] != '\0')
		{
			if (line[cub->index] != ' ')
				return (cub->error = -2);
			cub->index++;
		}
	}
	return (0);
}
