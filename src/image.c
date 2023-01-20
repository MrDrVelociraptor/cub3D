#include "cub3D.h"

// The t_image structure is used to store information about an image in the memory of a computer.
// This function, new_image(), is used to create a new t_image structure and initialize its fields.
// The function takes in three parameters: a pointer to a t_mlx structure, an integer representing the width of the image in pixels,
// and an integer representing the height of the image in pixels.

// The function first creates a new image using the mlx_new_image() function,
// which takes in the pointer to the t_mlx structure and the width and height of the image as parameters.
// The mlx_new_image() function returns a pointer to the new image. This pointer is stored in the img field of the t_image structure.

// Next, the function uses the mlx_get_data_addr() function to get the address of the image data in memory,
// as well as the number of bits per pixel, the length of each line in the image, and the endianness of the image data.
// These values are stored in the addr, bpp, ln_len, and endian fields of the t_image structure, respectively.

// Finally, the function sets the width and height fields of the t_image structure to the values of the width and height parameters,
// respectively, and returns the newly-initialized t_image structure.

t_image	new_image(t_mlx *mlx, int width, int height)
{
	t_image	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln_len,
			&img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
