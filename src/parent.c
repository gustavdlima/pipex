/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:10:47 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/13 21:23:28 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_proc( int *fd, t_pipx *pipx)
{
	int	outfile;

	outfile = open(pipx->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		error_msg("Open() function in parent_proc error.\n", 1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	cmd_exec(pipx->cmd2, pipx);
}
