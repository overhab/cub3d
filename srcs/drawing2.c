#include "../include/cub3d.h"

void	draw_background(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < (cub->set.res_h / 2))
	{
		x = 0;
		while (x < cub->set.res_w)
			pixel_put(&cub->mlx, x++, y, cub->set.ceiling_c);
		y++;
	}
	while (y < cub->set.res_h)
	{
		x = 0;
		while (x < cub->set.res_w)
			pixel_put(&cub->mlx, x++, y, cub->set.floor_c);
		y++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_color_two(t_cub *cub, char *line)
{
	cub->index = 1;
	if (cub->set.set_CF == 1 && line[0] == 'F')
		return (1);
	if (cub->set.set_CC == 1 && line[0] == 'C')
		return (1);
	while (line[cub->index] != '\0')
	{
		space_skip(cub, line);
		while (ft_isdigit(line[cub->index]) && line[cub->index] != '\0')
			cub->index++;
		space_skip(cub, line);
		if (ft_isdigit(line[cub->index]))
			return (1);
		else if (line[cub->index] != '\0')
			cub->index++;
	}
	return (0);
}

int	ft_strchr_plus(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

void	ft_putendl(char *s)
{
	size_t	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			write(1, &s[i], 1);
	}
	write(1, "\n", 1);
}
