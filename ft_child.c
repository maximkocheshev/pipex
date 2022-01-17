/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:47:18 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 17:39:04 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_two(t_data *data, char **argv, char **envp)
/* will read from end[0], will start cmd2*/
{
	data->fdout = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fdout == -1)
		return (perror("Open of File 2 failed"));
	close(data->end[1]);
	if (dup2(data->end[0], STDIN_FILENO) < 0)
		return (perror("dup2"));
	close(data->end[0]);
	if (dup2(data->fdout, STDOUT_FILENO) < 0)
		return (perror("dup2"));
	close(data->fdout);
	if (!data->flag2)
		execve(data->cmd_path2, data->cmd2, envp);
	exit(EXIT_FAILURE);
}

void	child_one(t_data *data, char **argv, char **envp)
/* will write to end[1], will start cmd 1 */
{
	close(data->end[0]);
	if (dup2(data->end[1], STDOUT_FILENO) < 0)
		return (perror("dup2 failed"));
	close(data->end[1]);
	data->fdin = open(argv[1], O_RDONLY);
	if (data->fdin == -1)
		return (perror("Open of File 1 failed"));
	if (dup2(data->fdin, STDIN_FILENO) < 0)
		return (perror("dup2 failed"));
	close(data->fdin);
	if (!data->flag1)
		execve(data->cmd_path1, data->cmd1, envp);
	exit(EXIT_FAILURE);
}
