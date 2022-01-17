/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:15:48 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 17:42:44 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_path_1(t_data *data)
/* will search for the correct path of command 1, print error if not found */
{
	int		i;
	char	*temp;

	if (access(data->cmd1[0], F_OK) == 0)
	{
		data->cmd_path1 = ft_strdup(data->cmd1[0]);
		temp = ft_strrchr(data->cmd1[0], '/') + 1;
		free(data->cmd1[0]);
		data->cmd1[0] = ft_strdup(temp);
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path1 = ft_strjoin(data->mypaths[i++], data->cmd1[0], '/');
		if (access(data->cmd_path1, F_OK) == 0)
			return ;
		free(data->cmd_path1);
		data->cmd_path1 = NULL;
	}
	write(STDERR, "pipex: ", 7);
	write(STDERR, data->cmd1[0], ft_strlen(data->cmd1[0]));
	write(STDERR, ": command not found\n", 20);
	data->flag1 = 1;
}

static void	ft_get_path_2(t_data *data)
/* will search for the correct path of command 2, print error if not found */
{
	int		i;
	char	*temp;

	if (access(data->cmd2[0], F_OK) == 0)
	{
		data->cmd_path2 = ft_strdup(data->cmd2[0]);
		temp = ft_strrchr(data->cmd2[0], '/') + 1;
		free(data->cmd2[0]);
		data->cmd2[0] = ft_strdup(temp);
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path2 = ft_strjoin(data->mypaths[i++], data->cmd2[0], '/');
		if (access(data->cmd_path2, F_OK) == 0)
			return ;
		free(data->cmd_path2);
		data->cmd_path2 = NULL;
	}
	write(STDERR, "pipex: ", 7);
	write(STDERR, data->cmd2[0], ft_strlen(data->cmd2[0]));
	write(STDERR, ": command not found\n", 20);
	data->flag2 = 1;
}

void	ft_get_paths(t_data *data)
/* will find the correct path of the function
** print error if not found */
{
	ft_get_path_1(data);
	ft_get_path_2(data);
}
