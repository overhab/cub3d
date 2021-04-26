#include "../include/cub3d.h"

char	**make_map(t_list *head, int size)
{
	char	**map;
	int		d;

	map = (char **)malloc((size + 1) * sizeof(char *));
	d = 0;
	if (map == NULL)
		return (NULL);
	while (head)
	{
		map[d] = ft_strdup(head->content);
		head = head->next;
		d++;
	}
	map[d] = '\0';
	return (map);
}

int	parsig(t_cub *cub, char *line)
{
	if (line[0] == 'R')
		return (set_resolution(cub, line));
	if (line[0] == 'F')
		return (set_colors(cub, line, 'F'));
	if (line[0] == 'C')
		return (set_colors(cub, line, 'C'));
	if (line[0] == 'N' && line[1] == 'O')
		return (set_tex_north(cub, line));
	if (line[0] == 'S' && line[1] == 'O')
		return (set_tex_south(cub, line));
	if (line[0] == 'W' && line[1] == 'E')
		return (set_tex_west(cub, line));
	if (line[0] == 'E' && line[1] == 'A')
		return (set_tex_east(cub, line));
	if (line[0] == 'S')
		return (set_tex_sprite(cub, line));
	if (line[0] == '\0' && cub->begin == 1)
		return (cub->error = -2);
	if (line[0] == ' ' || line[0] == '1' || line[0] == '\0')
		return (check_what(cub, line));
	return (cub->error = -2);
}

int	parsing_2(t_cub *cub, t_list *head)
{
	if (cub->error == -2)
	{
		ft_lstclear(&head);
		return (error_out(cub, "Config error"));
	}
	if (cub->error == -1)
	{
		ft_lstclear(&head);
		return (0);
	}
	cub->len = ft_lstsize(head);
	cub->map = make_map(head, cub->len);
	ft_lstclear(&head);
	if (cub->map == NULL)
		return (error_out(cub, "Malloc (can't make map)"));
	if (check_settings(cub) == 1)
		lets_go(cub);
	return (0);
}

int	ft_parsing(char *file, t_cub *cub)
{
	char	*line;
	t_list	*head;
	int		fd;

	head = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_out(cub, "Can't open file"));
	while ((get_next_line(fd, &line)) > 0)
	{
		parsig(cub, line);
		if ((line[0] == ' ' || line[0] == '1') && ft_is_space(cub, line) == 1)
			ft_lstadd(&head, line, cub);
		free(line);
	}
	if (((line[0] == ' ' || line[0] == '1') && ft_is_space(cub, line) == 1))
		ft_lstadd(&head, line, cub);
	else
		cub->error = -2;
	close(fd);
	free(line);
	parsing_2(cub, head);
	return (ft_freedom(cub));
}

int	xpm_func(t_cub *cub)
{
	cub->tex_n.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->tex_n.path, &cub->tex_n.width, &cub->tex_n.height);
	cub->tex_n.addr = mlx_get_data_addr(cub->tex_n.img, &cub->tex_n.bpp,
			&cub->tex_n.line_l, &cub->tex_n.en);
	cub->tex_s.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->tex_s.path, &cub->tex_s.width, &cub->tex_s.height);
	cub->tex_s.addr = mlx_get_data_addr(cub->tex_s.img, &cub->tex_s.bpp,
			&cub->tex_s.line_l, &cub->tex_s.en);
	cub->tex_w.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->tex_w.path, &cub->tex_w.width, &cub->tex_w.height);
	cub->tex_w.addr = mlx_get_data_addr(cub->tex_w.img, &cub->tex_w.bpp,
			&cub->tex_w.line_l, &cub->tex_w.en);
	cub->tex_e.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->tex_e.path, &cub->tex_e.width, &cub->tex_e.height);
	cub->tex_e.addr = mlx_get_data_addr(cub->tex_e.img, &cub->tex_e.bpp,
			&cub->tex_e.line_l, &cub->tex_e.en);
	cub->tex_sp.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->tex_sp.path, &cub->tex_sp.width, &cub->tex_sp.height);
	cub->tex_sp.addr = mlx_get_data_addr(cub->tex_sp.img, &cub->tex_sp.bpp,
			&cub->tex_sp.line_l, &cub->tex_sp.en);
	return (1);
}
