/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:26:22 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/13 22:15:31 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(int *fd, t_pipx *pipx)
{
	int	infile;

	infile = open(pipx->infile, O_RDONLY);
	if (infile < 0)
		error_msg("Open() function in child_proc error.\n", 1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd_exec(pipx->cmd1, pipx);
}
