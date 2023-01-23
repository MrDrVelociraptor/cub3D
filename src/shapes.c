#include "cub3D.h"

void render_square_outline_v3(t_image *img, t_vec3 *pos, int size, int color)
{
    int i;
    int j;
	// mlx_clear_window(img->ptr->mlx, img->ptr->win);
    /* Draw the top and bottom lines of the square */
    for (i = pos->x; i < pos->x + size; i++) {
        put_pixel(img, i, pos->y, color);
        put_pixel(img, i, pos->y + size - 1, color);
    }
    /* Draw the left and right lines of the square */
    for (j = pos->y; j < pos->y + size; j++) {
        put_pixel(img, pos->x, j, color);
        put_pixel(img, pos->x + size - 1, j, color);
    }
}

// void render_circle_v3(t_image *img, t_vec3 center, float radius, int color)
// {
//     float angle;
//     t_vec3 point;
//     for (angle = 0; angle < 2 * M_PI; angle += 0.01)
//     {
//         point.x = center.x + radius * cos(angle);
//         point.y = center.y + radius * sin(angle);
//         put_pixel(img, point.x, point.y, color);
//     }
// }

// void render_circle_v3(t_image *img, t_vec3 *pos, float radius, int color)
// {
//     float angle;
//     t_vec3 point;
//     for (angle = 0; angle < 2 * M_PI; angle += 0.01)
//     {
//         point.cx = pos->cx + radius * cos(angle);
//         point.cy = pos->cy + radius * sin(angle);
//         put_pixel(img, point.cx, point.cy, color);
//     }
// }