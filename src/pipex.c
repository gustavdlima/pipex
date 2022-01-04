/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:08 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 23:42:52 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	pipe(fd);
	if (pipe(fd) == -1)
		return (perror("Error. fd is low than 0!"));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("pid1 error."));
	if (pid1 == 0)
		child_proc(argv, envp, fd);
	waitpid(pid1, NULL, 0);
	parent_proc(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
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
