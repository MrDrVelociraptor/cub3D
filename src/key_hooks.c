#include "cub3D.h"

int	closeWin(void)
{
	exit(0);
	return (0);
}

int	keypress(int key, t_data *data)
{
	// printf("data address: %p\n", data);
    // printf("key: %d\n", key);
	// printf("IN KEYPRESS FIRST ******** pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
    if (data == NULL)
    {
        printf("data is NULL\n");
        return (0);
    }
		if (key == 126)
		{
			printf("UP PRESSED\n");
			printf("data address: %p\n", data);
    		printf("key: %d\n", key);
			printf("pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
			data->pos.y -= 10;
			printf("AFTER UP PRESS pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
		}
		if (key == 125)
		{
			printf("DOWN PRESSED\n");
			printf("data address: %p\n", data);
    		printf("key: %d\n", key);
			printf("pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
			data->pos.y += 10;
			printf("AFTER DOWN PRESS pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
		}
		if (key == 123)
		{
			printf("LEFT PRESSED\n");
			printf("data address: %p\n", data);
    		printf("key: %d\n", key);
			printf("pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
			data->pos.x -= 10;
			printf("AFTER LEFT PRESS pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
		}
		if (key == 124)
		{
			printf("RIGHT PRESSED\n");
			printf("data address: %p\n", data);
    		printf("key: %d\n", key);
			printf("pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);
			data->pos.x += 10;
			printf("AFTER RIGHT PRESS pos.x = %f ---- pos.y = %f\n", data->pos.x, data->pos.y);	
		}
			printf("data->img * = %p\n", data->img);
			data->img->img = mlx_new_image(data->img->ptr->mlx, WIDTH, HEIGHT);
			data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, &data->img->ln_len,
			&data->img->endian);
			render_square_outline_v3(data->img, &data->pos, data->size, data->color);
			mlx_put_image_to_window(data->img->ptr->mlx, data->img->ptr->win, data->img->img, 0, 0);
	if (key == ESC)
		closeWin();
	return (0);
}

void	my_mlx_window(void *win, void *mlx, t_data *data)
{
	mlx_hook(win, 2, 1L << 0, keypress, data);
	mlx_hook(win, 17, 1L << 17, closeWin, 0);
	mlx_loop(mlx);
}

// The first function closeWin() simply exits the program by calling the exit() function.
// The second function keypress(int key, void *data) is a callback function that is called when a key is pressed.
// This function takes in two arguments, the first is an integer representing the key code of the pressed key and
// the second is a void pointer which is not used in this function.
// This function checks if the key code is equal to 53, which corresponds to the "esc" key and if it is, it calls the closeWin() function to close the program.
// The third function my_mlx_window(void *win, void *mlx) is used to setup event handlers for the window.
// It takes in two arguments, a pointer to the window and a pointer to the mlx context.
// This function sets up two event handlers using the mlx_hook function.
// The first hook is for the key press event, it sets the keypress function as the callback function to be called when a key is pressed,
// the second hook is for the close event, it sets the closeWin function as the callback function to be called when the window is closed.
// Finally, it enters the main loop of the mlx library using the mlx_loop function which waits for user inputs and calls the appropriate callback function.
// This function sets up the event handling for the window, allowing the user to close the window by pressing the esc key or by clicking the close button in the window's title bar.