/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:08 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/07 19:03:56 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipx *pipx)
{
	int	fd[2];
	int	p_id;

	pipx->error_flag = cmd_check(pipx);
	pipe(fd);
	if (pipe(fd) == -1)
		errors("Error in pipe() function.", 42);
	p_id = fork();
	if (p_id < 0)
		errors("Error in fork() function.", 42);
	if (p_id == 0)
		child_proc(fd, pipx);
	waitpid(p_id, NULL, 0);
	parent_proc(fd, pipx);
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipx	pipx;

	if (argc != 5)
		return (0);
	else
	{
		start_struct(argv, envp, &pipx);
		pipex(&pipx);
	}
	return (pipx.error_flag);
}
