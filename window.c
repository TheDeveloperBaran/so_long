/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:07:38 by bakilic           #+#    #+#             */
/*   Updated: 2023/05/04 19:07:39 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window(t_list *data)
{
	data->image = malloc(sizeof(void *) * 5);
	data->mlx = mlx_init();
	data->image[0] = mlx_xpm_file_to_image(data->mlx, B_XPM, &data->image_x,
			&data->image_y);
	data->image[1] = mlx_xpm_file_to_image(data->mlx, W_XPM, &data->image_x,
			&data->image_y);
	data->image[2] = mlx_xpm_file_to_image(data->mlx, D_XPM, &data->image_x,
			&data->image_y);
	data->image[3] = mlx_xpm_file_to_image(data->mlx, C_XPM, &data->image_x,
			&data->image_y);
	data->image[4] = mlx_xpm_file_to_image(data->mlx, P_XPM, &data->image_x,
			&data->image_y);
	data->window = mlx_new_window(data->mlx, 64 * data->column, 64 * data->row,
			"SO_LONG");
	background(data);
}

void	background(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (data->split[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->window, data->image[0],
					j * 64, i * 64);
				mlx_put_image_to_window(data->mlx, data->window, data->image[1],
					j * 64, i * 64);
			}
			if (data->split[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->image[0],
					j * 64, i * 64);
			backgorund2(data, i, j);
			j++;
		}
		i++;
	}
	step_by_step(data);
}

void	backgorund2(t_list *data, int i, int j)
{
	if (data->split[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0], j * 64,
			i * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[4], j * 64,
			i * 64);
	}
	if (data->split[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0], j * 64,
			i * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[2], j * 64,
			i * 64);
	}
	if (data->split[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image[0], j * 64,
			i * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->image[3], j * 64,
			i * 64);
	}
}
