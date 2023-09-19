/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:07:32 by bakilic           #+#    #+#             */
/*   Updated: 2023/05/04 19:07:34 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_by_step(t_list *data)
{
	char	*step;

	step = ft_itoa(data->step);
	mlx_put_image_to_window(data->mlx, data->window, data->image[0], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[0], 64, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->image[1], 64, 0);
	mlx_string_put(data->mlx, data->window, 0, 10, 0xffffff, "STEP =");
	mlx_string_put(data->mlx, data->window, 50, 10, 0xffffff, step);
	free(step);
}

void	step_plus(t_list *data)
{
	data->step++;
	step_by_step(data);
}

int	step_escape(t_list *data)
{
	step_plus(data);
	ft_printf("%d", data->step);
	exit(1);
}
