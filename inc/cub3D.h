#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 500
# define HEIGHT 500
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124



typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_image {
	int		*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		ln_len;
	int		endian;
	t_mlx	*ptr;
}	t_image;

typedef struct vec3
{
    int x;
    int y;
	int cx;
    int cy;
    int z;
	int center;

} t_vec3;

typedef struct {
    t_vec3 pos;
    t_image *img;
	int size;
	int color;
} t_data;

int	closeWin(void);
int	move_sqaure(int key, t_data *data);
void	put_pixel(t_image *img, int x, int y, int color);
// void	put_pixelz(t_image *img, t_vec3 *pos, int color);

void	my_mlx_window(void *win, void *mlx, t_data *data);
t_image	new_image(t_mlx *mlx, int width, int height);

void render_square_outline_v3(t_image *img, t_vec3 *pos, int size, int color);
void render_circle_v3(t_image *img, t_vec3 *pos, float radius, int color);


#endif