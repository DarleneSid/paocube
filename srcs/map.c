/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:21:29 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/13 21:33:38 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
1. what to do with path?

2. parse rgb for f n c

3. map
reach line with only 1 n spaces

111
1N1
111



*/




/*

all_stuff_map(int fd)
{
	if (path part)
		do stuff w path
	if (rgb)
		do stuff w color
	if (map)
		1) count lines for malloc data->map
		2)stuck map in char **
		malloc map


	


}
 


*/

int	height_of_map(int fd, t_data *data)
{
	int			i;
	int			c;
	char		*tmp;

	i = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		return (-1);
	while (tmp)
	{
		c = 0;
		while (tmp[c] && check_valid_char(tmp[c]))
			c++;
		if (tmp[c] == '\n')
			i++;
		if (tmp[c] == '\0')
		{
			free(tmp);
			break ;
		}
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
	}
	data->height = i;
	return (i);
}

void	free_dstr(char **dstr)
{
	int	i;

	if (!dstr)
		return ;
	i = 0;
	while (dstr[i])
		free(dstr[i++]);
	free(dstr);
}



int	invalid_start(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == '\n')
	{
		if (s[i] != ' ' || s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_floor(t_data *data, char *s)
{
	int		i;
	int		j;
	char	**ithinkdifferent;
	// int rgb[3] = {0};
	int number = 0;
	int count = 0;
	i = 2;
	j = 0;
	if (s[0] != 'F')
		return (-1);
	if (s[1] != ' ')
		return (-1);
	// 1 space or ???
	ithinkdifferent = ft_split(&s[i], ',');
	if (!ithinkdifferent)
		return (-1);
	while (ithinkdifferent[count])
	{
		number = ft_atoi(ithinkdifferent[count]);
		if (count == 0 && number >= 0 && number <= 255)
			data->f_r = number;
		if (count == 1 && number >= 0 && number <= 255)
			data->f_g = number;
		if (count == 2 && number >= 0 && number <= 255)
			data->f_b = number;
		count++;
	}
	return (1);
}

int	is_ceiling(t_data *data, char *s)
{
	int		i;
	int		j;
	char	**ithinkdifferent;
	// int rgb[3] = {0};
	int number = 0;
	int count = 0;
	i = 2;
	j = 0;
	if (s[0] != 'C')
		return (-1);
	if (s[1] != ' ')
		return (-1);
	// 1 space or ???
	ithinkdifferent = ft_split(&s[i], ',');
	if (!ithinkdifferent)
		return (-1);
	while (ithinkdifferent[count])
	{
		number = ft_atoi(ithinkdifferent[count]);
		if (count == 0 && number >= 0 && number <= 255)
			data->c_r = number;
		if (count == 1 && number >= 0 && number <= 255)
			data->c_g = number;
		if (count == 2 && number >= 0 && number <= 255)
			data->c_b = number;
		count++;
	}
	return (1);
}


int	check_valid_chars(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == '\n')
	{
		if (s[i] == '1' || s[i] == '0' || s[i] == ' ')
			i++;
		else if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
		{
			data->pos--;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_valid_char(char s)
{
	if (s == '1' || s == '0' || s == ' ' || s == 'N' || s == 'S' || s == 'E' || s == 'W')
		return (1);
	return (0);
}

void check_map(t_data *data, char *tmp, int fd)
{
	int			row;
	char		**map;

	row = 0;
	map = ft_calloc(sizeof(char *), (data->height + 1));
	if (!map)
		return ;
	if (invalid_start(tmp) == 0)
	{
		map[row] = ft_calloc(sizeof(char), ft_strlen(tmp) + 1);
		map[row] = ft_strdup(tmp);
		// free(tmp);
		// tmp = get_next_line(fd);
		while(tmp && check_valid_chars(data, tmp))
		{
			row++;
			tmp = get_next_line(fd);
			if (!tmp)
				return ;
			if (check_valid_chars(data, tmp) && data->pos >= 0)
			{
				map[row] = ft_calloc(sizeof(char), ft_strlen(tmp) + 1);
				map[row] = ft_strdup(tmp);
			}
			else
				return ;	
		}
	}
	int i = 0;
	while (i < row)
		printf("%s\n", map[i++]);
}

// void get_all_from_file(t_data *data, int fd)
// {
// 	data->data 
// }

int	all_stuff_map(t_data *data, int fd)
{
	int			row;
	char		*tmp;
	char		**map;

	row = 0;
	map = ft_calloc(sizeof(char *), (data->height + 1));
	if (!map)
		return (-1);
	data->pos = 1;
	tmp = get_next_line(fd);
	if (!tmp)
		return (-1);
	while (tmp)
	{
		// if (is_path(tmp))
		// 	// : NO SO WE EA
		// check_all_path??
		
		if (is_floor(data, tmp) != -1)
		{
			free(tmp);
			tmp = get_next_line(fd);
			if (!tmp)
				return (-1);
		}
		
		if (is_ceiling(data, tmp) != -1)
		{
			free(tmp);
			tmp = get_next_line(fd);
			if (!tmp)
				return (-1);
		}
		
		if (tmp[0] == '\n')
		{
			free(tmp);
			tmp = get_next_line(fd);
			if (!tmp)
				return (-1);
		}

		check_map(data, tmp, fd);
		// else if (!is_floor(data, tmp)  && !is_ceiling(data, tmp) && !start_map(tmp) && tmp[0] != '\n')
		// 	return (ft_printf("NOT VALID MAP\n"), -1);
		// else
		// {
		// 	free(tmp);
		// 	tmp = get_next_line(fd);
		// 	if (!tmp)
		// 		return (-1);
		// }

	}
	data->map = map;
	if (!data->map)
		return (free_dstr(map), close(fd), exit(0), 1);
	return (1);
}

int	parsing(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_printf("Not valid fd!\n"), exit(0));
	height_of_map(fd, data);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_printf("Not valid fd!\n"), exit(0));
	all_stuff_map(data, fd);
	close(fd);
	int i;

	i = 0;
	// while (data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	return (0);
// 	if (!*data->map)
// 		return (exit_safely(data->map, 1), 1);
// 	if (check_borders(data))
// 		return (exit_safely(data->map, 1), 1);
// 	if (check_valid_chars(data))
// 		return (exit_safely(data->map, 1), 1);
// 	if (map_rules(data))
// 		return (exit_safely(data->map, 3), 1);
// 	if (is_there_e_or_c(set_map_to_p(data->map)))
// 		return (exit_safely(data->map, 3), 1);
// 	return (0);
}

