#include "../include/cub3d.h"

int	check_valid_path(char *path)
{
	int	len;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	len = ft_strlen(path);
	if (len <= 2)
		return (0);
	if (path[len - 1] == 'm' && path[len - 2] == 'p' && path[len - 3] == 'x'
		&& path[len - 4] == '.')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*get_path(t_cub *cub, char *line)
{
	int		i;
	char	*path;

	space_skip(cub, line);
	i = cub->index;
	while (line[i] != '\0')
		i++;
	path = (char *)malloc(i + 1 * sizeof(*line));
	if (path == NULL)
		return (0);
	i = 0;
	while (line[cub->index] != '\0')
	{
		path[i] = line[cub->index];
		cub->index++;
		i++;
	}
	path[i] = '\0';
	return (path);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc(i + 1 * sizeof(*s));
	if (dup == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n-- > 0)
		*d++ = 0;
	return (s);
}
