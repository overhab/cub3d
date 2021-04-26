#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define BUFFER_SIZE 42
# define ESC 0xff1b
# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define LEFTK 0xff51
# define RIGHTK 0xff53

# define SCALE 64
# define PLSPEED 8
# define M_PI_6 0.523598776

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_l;
	int				en;
	int				width;
	int				height;
	int				side;
	char			*path;
}	t_mlx;

typedef struct s_ray
{
	double			ray;
	double			mx;
	double			my;
	double			mp;
	double			dof;
	double			rx;
	double			ry;
	double			ra;
	double			xo;
	double			yo;
}	t_ray;

typedef struct s_test
{
	double			fov;
	double			half_fov;
	double			num_rays;
	double			max_depth;
	double			ray_da;
	double			ra;
	double			fe;
	double			dist;
	double			coeff;
	double			scal;
	double			ray_dis;
}	t_test;

typedef struct s_pos
{
	double			x;
	double			y;
}	t_pos;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dir;
	double			dist;
	double			size;
	double			angle;
	double			step;
	double			draw_x;
	double			draw_y;
	double			siz_ang;
	double			tex_pos;
	unsigned int	*clr;
	int				i;
}	t_sprite;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir;
	double			dx;
	double			dy;
	double			xa;
	double			ya;
	double			speed;
	double			start;
	double			end;
	t_pos			plr_pos;
}	t_player;

typedef struct s_set
{
	int				res_w;
	int				res_h;
	int				floor_c;
	int				ceiling_c;
	int				set_R;
	int				set_CF;
	int				set_CC;
	int				set_NO;
	int				set_SO;
	int				set_WE;
	int				set_EA;
	int				set_SP;
	int				set_MAP;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_lft;
	int				key_rght;
}	t_set;

typedef struct s_bmp
{
	int				filesize;
	int				headersize;
	int				fileheadersize;
	int				imagesize;
	int				bitc;
	int				width_byte;
	int				bpp;	
	int				img_w;
	int				img_h;
	int				pad;
}	t_bmp;	

typedef struct s_cub
{
	char			**map;
	char			**settings;
	int				len;
	int				map_len;
	int				plr_cnt;
	int				error;
	int				err_out;
	int				spr_cnt;
	t_player		player;
	t_mlx			mlx;
	t_pos			pos;
	t_ray			ray;
	t_test			test;
	t_set			set;
	t_sprite		*sprite;
	double			cheight;
	t_mlx			color;
	t_mlx			tex_n;
	t_mlx			tex_s;
	t_mlx			tex_w;
	t_mlx			tex_e;
	t_mlx			tex_sp;
	t_mlx			tex;
	char			side;
	int				index;
	double			*rlen;
	int				begin;
	int				screen_shot;
}	t_cub;

int			key_press(int key, t_cub *cub);
int			key_release(int key, t_cub *cub);

void		player_dir(t_cub *cub, t_player *player, t_pos *pos);
void		init_player(t_cub *cub, t_player *player);

int			ft_lstsize(t_list *lst);
t_list		*ft_lstadd(t_list **lst, char *line, t_cub *cub);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);

int			lets_go(t_cub *cub);
int			main_loop(t_cub *cub);
int			close_win(t_cub *cub);
int			ft_freedom(t_cub *cub);
void		exit_tex(t_cub *cub);
char		**make_map(t_list *head, int size);
int			ft_parsing(char *file, t_cub *cub);
int			parsing_2(t_cub *cub, t_list *head);
void		printmap(char **map);
void		clear_map(char **map, int size);
void		clear_textures(t_cub *cub);
int			xpm_func(t_cub *cub);

t_mlx		init_texture(void);
t_set		init_settings(void);

int			getcolor_wall(t_cub *cub, t_player *player);
void		color_side(t_cub *cub, t_player *player);
void		color_height(t_cub *cub, double x, double lineH);

char		*ft_strchr(const char *s, int c);
int			ft_atoi(t_cub *cub, const char *nptr);
int			ft_atoi_color(t_cub *cub, const char *nptr);
char		*ft_strdup(const char *s);
int			search_for_char(const char *str, t_cub *cub);
void		*ft_bzero(void *s, size_t n);
char		*get_path(t_cub *cub, char *line);
int			ft_strchr_plus(const char *s, char c);
int			ft_is_space(t_cub *cub, char *str);
int			is_it_map(t_cub *cub);
void		space_skip(t_cub *cub, const char *nptr);
void		ft_putendl(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);

int			set_colors(t_cub *cub, char *line, char ch);
int			set_resolution(t_cub *cub, char *line);
int			check_color_two(t_cub *cub, char *line);
int			check_settings(t_cub *cub);
int			set_tex_north(t_cub *cub, char *line);
int			set_tex_south(t_cub *cub, char *line);
int			set_tex_west(t_cub *cub, char *line);
int			set_tex_east(t_cub *cub, char *line);
int			set_tex_sprite(t_cub *cub, char *line);
int			check_valid_path(char *path);
int			error_out(t_cub *cub, char *error);
int			map_check(t_cub *cub);
int			map_checkk(char *map, int len);
int			check_what(t_cub *cub, char *line);
int			map_first_last(t_cub *cub);
int			map_compare(t_cub *cub, int e);
int			ft_strlen_space(const char *str);

int			get_next_line(int fd, char **line);
int			ft_strendl(char *str);
char		*ft_strjoin(char *rmd, char *buffer);
size_t		ft_strlen(const char *s);
size_t		ft_strlen_endl(char *s);

int			init_sprites(t_cub *cub, t_pos pos, int i);
void		draw_sprites(t_cub *cub, t_sprite spr, int i);
int			scan_for_sprites(t_cub *cub);
void		sprite_sort(t_cub *cub);
void		sorting_plus(t_cub *cub);
void		angle_size(t_cub *cub, int i);
void		sprite_color(t_cub *cub, int x, int y, t_sprite *spr);

char		side_of_wall(t_cub *cub, t_player *player);
void		ft_drawline(t_cub *cub,
				double ray_count, t_player *player);
void		draw_rays(t_cub *cub, t_player *plr);
void		draw_screen(t_cub *cub);
void		draw_background(t_cub *cub);
void		pixel_put(t_mlx *win, int x, int y, int color);

int			create_map(t_cub *cub);
int			scan_for_map(t_cub *cub);
void		scan_for_player(t_cub *cub, char *map);

int			make_screenshot(t_cub *cub);
#endif