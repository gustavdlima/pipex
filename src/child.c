/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:26:22 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/10 20:59:34 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(int *fd, t_pipx *pipx)
{
	int		infile;

	infile = open(pipx->infile, O_RDONLY);
	if (infile == -1)
		errors("Error in child_proc open() function.", 42);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd_exec(pipx->cmd1, pipx);
}
