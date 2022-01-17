/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:02:36 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 17:42:05 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(char **argv, char **envp, t_data *data)
{
	int		i;
	char	*path_from_envp;

	i = 0;
	while (envp && envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	path_from_envp = ft_strrchr(envp[i], '=') + 1;
	data->mypaths = ft_split(path_from_envp, ':');
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd1)
	{
		perror("Error when initialising Command 1");
		data->flag1 = 1;
	}
	if (!data->cmd2)
	{
		perror("Error when initialising Command 2");
		data->flag2 = 1;
	}
	if (!data->mypaths)
	{
		perror("Error when initialising Paths");
		exit(EXIT_FAILURE);
	}
}

static void	pipex(t_data *data, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;

	child1 = fork();
	if (child1 < 0)
		perror("Fork failed");
	if (child1 == 0)
		child_one(data, argv, envp);
	child2 = fork();
	if (child2 < 0)
		perror("Fork failed");
	if (child2 == 0)
		child_two(data, argv, envp);
	waitpid(-1, NULL, 0);
	ft_free_struct(data);
}

int	main(int argc, char **argv, char **envp)
{
	static t_data	data;

	if (argc != 5)
	{
		perror("Usage : ./pipex infile \"cmd1\" \"cmd2\" outfile\nError");
		return (1);
	}
	if (pipe(data.end) == -1)
	{
		perror("Pipe failed");
		return (1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		write(STDERR, "pipex: ", 7);
		write(STDERR, argv[1], ft_strlen(argv[1]));
		write(STDERR, ": No such file or directory\n", 28);
		data.flag1 = 1;
	}
	ft_init(argv, envp, &data);
	ft_get_paths(&data);
	pipex(&data, argv, envp);
	return (0);
}
