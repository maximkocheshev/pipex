/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:50:24 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 17:43:05 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **str)
/* will free the given array and set it to NULL */
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_free_struct(t_data *data)
/* will free all allocated data of the data struct */
{
	ft_free_array(data->mypaths);
	ft_free_array(data->cmd1);
	ft_free_array(data->cmd2);
	free(data->cmd_path1);
	data->cmd_path1 = NULL;
	free(data->cmd_path2);
	data->cmd_path2 = NULL;
}
