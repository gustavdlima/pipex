/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:08 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/16 02:54:56 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipx *pipx)
{
	int	fd[2];
	int	p_id;

	pipe(fd);
	if (pipe(fd) == -1)
		error_msg("Pipe() function error.\n", 1);
	p_id = fork();
	if (p_id < 0)
		error_msg("Fork() function error.\n", 1);
	if (p_id == 0)
		child_proc(fd, pipx);
	close(fd[1]);
	if (p_id != 0)
	{
		waitpid(p_id, NULL, 0);
		parent_proc(fd, pipx);
	}
	close(fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipx	pipx;

	if (argc != 5)
		error_msg("Argc error.\n", 1);
	else
	{
		start_struct(argv, envp, &pipx);
		cmd_check(&pipx);
		pipex(&pipx);
	}
	return (0);
}
