/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:21:29 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/10 01:37:02 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"





// int	fill_map(t_data *data, int fd)
// {
// 	static int	var = 0;
// 	char		*str;
// 	char		*tmp;

// 	str = ft_calloc(1, 1);
// 	if (!str)
// 		return (ft_printf("Malloc failed"), close(fd), exit(0), 1);
// 	while (1)
// 	{
// 		tmp = get_next_line(fd);
// 		if (!tmp)
// 			break ;
// 		if (!ft_strncmp(tmp, "\n", 1))
// 			var = 1;
// 		str = ft_gnl_strjoin(str, tmp);
// 		free(tmp);
// 	}
// 	free(tmp);
// 	data->map = ft_split(str, '\n');
// 	if (!data->map)
// 		return (free(str), close(fd), exit(0), 1);
// 	free(str);
// 	return (var);
// }


/*

init pos palyer = 1;

if pos player == 0
	???? put there start
IF POS PLAYER < 0
	error not valid map	


while( pos x y == ' ' || pos x y == 1 pos xy == 'N') // if another letters not valid
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
