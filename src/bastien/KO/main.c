#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	char	*dst;

	if (x >= data->width || y >= data->height || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

bool	touch(float x, float y, t_data *data)
{
	int	real_x;
	int	real_y;

	real_x = x / BLOCK_SIZE;
	real_y = y / BLOCK_SIZE;
	if (data->map[real_y][real_x] == '1')
		return (true);
	return (false);
}

void	draw_line(float start_x, float start_y, float angle, t_data *data)
{
	float	cos_angle;
	float	sin_angle;
	float	x;
	float	y;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x = start_x;
	y = start_y;
	while (x < data->width && y < data->height && x >= 0 && y >= 0 && !touch(x,
			y, data))
	{
		put_pixel(x, y, 0xFF0000, data);
		x += cos_angle;
		y += sin_angle;
		if (touch(x, y,data))
			put_pixel(x, y, 0xFF0000, data);
	}
}

void	init_game(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	init_player(6 * BLOCK_SIZE + BLOCK_SIZE / 2, 18 * BLOCK_SIZE + BLOCK_SIZE / 2, WEST, &data->player);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_prog(data, 1);
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	if (!data->win)
		exit_prog(data, 1);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		exit_prog(data, 1);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	if (!data->addr)
		exit_prog(data, 1);
}

void	draw_square(int x, int y, int size, int color, t_data *data)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		put_pixel(x + i, y, color, data);
	}
	i = -1;
	while (++i < size)
	{
		put_pixel(x, y + i, color, data);
	}
	i = -1;
	while (++i < size)
	{
		put_pixel(x + i, y + size, color, data);
	}
	i = -1;
	while (++i < size)
	{
		put_pixel(x + size, y + i, color, data);
	}
}

void	draw_map(t_data *data)
{
	int	color;
	int	x;
	int	y;

	color = 0x0000FF;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, data);
			x++;
		}
		y++;
	}
}

int	draw_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_memset(data->addr, 0, data->width * data->height * data->bpp / 8);
	move_player(data);
	put_pixel(data->player.x, data->player.y, 0xFF0000, data);
	draw_map(data);
	//raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	init_game(&data);
	data.map = get_map();
	draw_map(&data);
	draw_line(data.player.x, data.player.y, data.player.angle, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, (int (*)())(void *)key_press, &data.player);
	mlx_hook(data.win, 3, 1L << 1, (int (*)())(void *)key_release,
		&data.player);
	mlx_loop_hook(data.mlx, (int (*)())(void *)draw_loop, &data);
	mlx_loop(data.mlx);
	exit_prog(&data, 0);
	return (0);
}
