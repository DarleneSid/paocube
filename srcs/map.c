/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:21:29 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/13 01:11:30 by dsydelny         ###   ########.fr       */
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


int	first_line(char *s)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if (s[i] == ' ' || s[i] == '1')
			i++;
		else
			return (0);
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

int	check_valid_chars(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	height_of_map(int fd)
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
		while (tmp[c] && check_valid_chars(tmp[c]))
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
	return (i);
}

// void	free_dstr(char **dstr)
// {
// 	int	i;

// 	if (!dstr)
// 		return ;
// 	i = 0;
// 	while (dstr[i])
// 		free(dstr[i++]);
// 	free(dstr);
// }

//when i reach line with only 1 and spaces

int	fill_map(t_data *data, int fd)
{
	int			i;
	char		**str;
	char		*tmp;

	i = 0;
	printf("im here\n");
	str = ft_calloc(sizeof(char *), height_of_map(fd) + 1);
	if (!str)
		return (ft_printf("Malloc failed"), close(fd), exit(0), 1);
	while (1)
	{
		printf("im haaaaaere\n");
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		printf("im herrrrrre\n");
		if (first_line(tmp))
		{
			printf("here\n");
			while (tmp)
			{
				str[i] = tmp;
				free(tmp);
				i++;
				tmp = get_next_line(fd);
			}
		}
		printf("here\n");
		free(tmp);
	}
	free(tmp);
	data->map = str;
	if (!data->map)
		return (free(str), close(fd), exit(0), 1);
	free(str);
	return (0);
}

int	parsing(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_printf("Not valid fd!\n"), exit(0));
	printf("lines: %d\n", height_of_map(fd));
	fill_map(data, fd);
	close(fd);
	int i;

	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
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

/*

init pos palyer = 1;

if pos player == 0
	???? put there start
IF POS PLAYER < 0
	error not valid map	


while( pos x y == ' ' || pos x y == 1 pos xy == 'Nsew') // if another letters not valid
{
	if (pos xy == 'N')
		pos player--;
	while( pos x y == ' ' || pos x y == 1 )
	{
		if (pos x y == ' ' 
		y++;
	}
	x++;



if xy = ' ' && x + 1, y == 1
{
	
}

*/
