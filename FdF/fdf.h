/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:12:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/17 19:12:59 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif
# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef SHIFT
#  define SHIFT 10
# endif
# ifndef ROT_SHIFT
#  define ROT_SHIFT 0.05
# endif
# ifndef ZOOM_SHIFT
#  define ZOOM_SHIFT 0.5
# endif

# define MAL_ERROR "Memory allocation failed."
# define LHEX "0123456789abcdef"

# define WHITE 0xFFFFFF
# ifndef COLOR_1
#  define COLOR_1 0x581845
# endif
# ifndef COLOR_2
#  define COLOR_2 0x900C3F
# endif
# ifndef COLOR_3
#  define COLOR_3 0xC70039
# endif
# ifndef COLOR_4
#  define COLOR_4 0xFF5733
# endif
# ifndef COLOR_5
#  define COLOR_5 0xFFC30F
# endif

# ifdef OSX
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_P 35
#  define KEY_MINUS 27
#  define KEY_PLUS 24
#  define KEY_R 15
#  define KEY_U 32
#  define KEY_J 38
#  define KEY_I 34
#  define KEY_K 40
#  define KEY_O 31
#  define KEY_L 37
# elif LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_P 112
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_R 114
#  define KEY_U 117
#  define KEY_J 106
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_O 111
#  define KEY_L 108
# else
#  define LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_P 112
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_R 114
#  define KEY_U 117
#  define KEY_J 106
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_O 111
#  define KEY_L 108
# endif

//Structures
typedef struct s_map
{
	int	w;
	int	h;
	int	**z_mt;
	int	**clrs;
	int	iscolor;
	int	min_z;
	int	max_z;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sz_l;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	float	zoom;
	int		iso;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

// utils.c
void	fdf_free_split(char **str);
void	fdf_free_vars(t_vars *vars);
void	fdf_free_all(t_vars *vars);
t_point	fdf_new_point(int x, int y, t_vars *vars);
t_point	fdf_get_coords(t_vars *vars, t_point point);

// error.c
void	fdf_err_exit(const char *err, const char *msg);
void	fdf_perror_exit(const char *str);

// map_utils.c
void	fdf_get_min_max_z(t_map *map);
void	fdf_free_map(t_map *tab);
void	fdf_alloc_map(t_map *map);
t_map	*fdf_initialise_map(char *file);

// handle_args.c
void	fdf_handle_args(t_map **map, int ac, char **av);

// mlx_main.c
int		fdf_mlx_main(t_map *map);

// mlx_hook.c
int		fdf_close_win(t_vars *vars);
int		fdf_key_hook(int keycode, t_vars *vars);

// mlx_loop.c
int		fdf_update(t_vars *vars);

// mlx_utils.c
void	fdf_reset_vars(t_vars *vars);
int		fdf_initialise_vars(t_vars *vars, t_map *map);
void	fdf_initialise_mlx(t_vars *vars);

// draw.c
void	fdf_draw(t_vars *vars);

// draw_utils.c
void	fdf_isometric(t_vars *vars, int *x, int *y, int z);
void	fdf_rot_x(t_vars *vars, int *y, int *z);
void	fdf_rot_y(t_vars *vars, int *x, int *z);
void	fdf_rot_z(t_vars *vars, int *x, int *y);
void	fdf_img_pixel_put(t_vars *vars, int x, int y, int color);

// controls.c
void	fdf_handle_zoom(int keycode, t_vars *vars);
void	fdf_handle_move(int keycode, t_vars *vars);
void	fdf_handle_rot(int keycode, t_vars *vars);
void	fdf_handle_flattening(int keycode, t_vars *vars);

// color.c
int		fdf_get_color(t_point current, t_point start, t_point end, t_point delta);
int		fdf_get_z_color(t_vars *vars, int cur_z);

#endif