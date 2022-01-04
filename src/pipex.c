/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:08 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 17:39:24 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	pipe(fd);
	if (pipe(fd) == -1)
		return (perror("Error. fd is low than 0!"));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("pid1 error."));
	if (!pid1)
		child_proc(argv, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
	{
		parent_proc(argv, envp, fd);
	}
	waitpid(pid1, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);
	else
	{
		pipex(argv, envp);
	}
	return (0);
}
