#include "../include/cub3d.h"

static int	getcolor(t_cub *cub, int x, int y)
{
	char	*dst;
	int		color;

	dst = (cub->mlx.addr + (4 * (int)cub->set.res_w
				* ((int)cub->set.res_h - 1 - y) + (4 * x)));
	return (color = *(unsigned int *)dst);
}

static t_bmp	make_bitmap_header(t_cub *cub)
{
	t_bmp	bmp;

	ft_bzero(&bmp, sizeof(t_bmp));
	bmp.bitc = 24;
	bmp.img_w = cub->set.res_w;
	bmp.headersize = 40;
	bmp.imagesize = (3 * cub->set.res_w + bmp.pad) * cub->set.res_h;
	bmp.fileheadersize = 54;
	bmp.img_h = cub->set.res_h;
	bmp.pad = cub->set.res_w % 4;
	bmp.filesize = 54 + (3 * cub->set.res_w + bmp.pad) * cub->set.res_h;
	bmp.bpp = cub->mlx.bpp;
	return (bmp);
}

static int	fill_header(unsigned char *fileheader, t_bmp header, int fd)
{
	fileheader[0] = 'B';
	fileheader[1] = 'M';
	fileheader[2] = header.filesize;
	fileheader[3] = (header.filesize >> 8);
	fileheader[4] = (header.filesize >> 16);
	fileheader[5] = (header.filesize >> 24);
	fileheader[10] = 54;
	fileheader[14] = 40;
	fileheader[18] = header.img_w;
	fileheader[19] = (header.img_w >> 8);
	fileheader[20] = (header.img_w >> 16);
	fileheader[21] = (header.img_w >> 24);
	fileheader[22] = header.img_h;
	fileheader[23] = (header.img_h >> 8);
	fileheader[24] = (header.img_h >> 16);
	fileheader[25] = (header.img_h >> 24);
	fileheader[26] = 1;
	fileheader[28] = 24;
	if (write(fd, fileheader, 54) < 0)
		return (-1);
	return (0);
}

static int	bmp_write(t_cub *cub, int fd, t_bmp bmp)
{
	int				color;
	unsigned char	bmppad[3];
	int				x;
	int				y;

	ft_bzero(&bmppad, 3);
	y = 0;
	while (y < cub->set.res_h)
	{	
		x = 0;
		while (x < cub->set.res_w)
		{
			color = getcolor(cub, x, y);
			if (write(fd, &color, 3) < 0)
				return (1);
			x++;
		}
		if (bmp.pad > 0 && write(fd, &bmppad, bmp.pad) < 0)
			return (1);
		y++;
	}
	return (0);
}

int	make_screenshot(t_cub *cub)
{
	t_bmp			header;
	unsigned char	fileheader[54];
	int				indx;
	int				fd;

	draw_screen(cub);
	indx = 0;
	fd = open("./ScreenShot00.bmp", O_WRONLY | O_CREAT
			| O_TRUNC | O_APPEND, 0777);
	if (fd < 0)
		return (-1);
	header = make_bitmap_header(cub);
	while (indx < header.fileheadersize)
		fileheader[indx++] = (unsigned char)0;
	if (fill_header(fileheader, header, fd) == -1)
		return (-1);
	if (bmp_write(cub, fd, header))
		return (-1);
	close(fd);
	return (0);
}
