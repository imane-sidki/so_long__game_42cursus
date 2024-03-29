/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_commun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:30:09 by isidki            #+#    #+#             */
/*   Updated: 2023/06/04 14:37:42 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nbr_lines(char *av, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = ft_open(av);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->y = i;
	return (i);
}

char	**remplir_lines_parsing(char *file, int size)
{
	char	**lines;
	char	*line;
	int		fd;
	int		i;

	lines = (char **)malloc(sizeof(char *) * (size + 1));
	if (!lines)
		return (0);
	fd = ft_open(file);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		lines[++i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	lines[++i] = NULL;
	return (lines);
}

void	ft_initialize(t_data *data)
{
	data->mlx_ptr = NULL;
	data->img_c = NULL;
	data->img_0 = NULL;
	data->img_w = NULL;
	data->img_e_c = NULL;
	data->img_e_o = NULL;
	data->img_p_l = NULL;
	data->img_p_r = NULL;
	data->img_height = 0;
	data->img_width = 0;
	data->x = 0;
	data->y = 0;
	data->num_frame = 0;
	data->nbr_collectb = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->moves = 0;
	data->lines = NULL;
}

void	position_player(char **lines, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'P')
			{
				data->x_player = j;
				data->y_player = i;
			}
		}
	}
}

void	print_moves(t_data *data, int i)
{
	if (data->moves > i)
	{
		write(1, "moves : ", 8);
		ft_putnbr(data->moves);
		write(1, "\n", 1);
	}
}
