#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3D.h"

int main(void)
{
    t_mlx mlx;
    t_image img;
    // t_vec3 pos;
	t_data data;
    data.size = 250;
    data.color = 0xFF0000;

	// t_vec3 center = {300, 540};
    data.pos.x = (WIDTH - data.size) / 2;
    data.pos.y = (HEIGHT - data.size) / 2;
    data.pos.z = 0;
	// printf("IN MAIN ------- pos.x = %f ---- pos.y = %f\n", data.pos.x, data.pos.y);


    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Square Outline");
    img = new_image(&mlx, WIDTH, HEIGHT);
	data.img = &img;
	printf("img * = %p\ndata.img * = %p", &img, data.img);
	data.img->ptr=&mlx;
    render_square_outline_v3(data.img, &data.pos, data.size, data.color);

	// render_circle_v3(&img, center, size, color);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
    my_mlx_window(mlx.win, mlx.mlx, &data);
	printf("DOWN IN MAIN ------- pos.x = %f ---- pos.y = %f\n", data.pos.x, data.pos.y);

    return (0);
}
