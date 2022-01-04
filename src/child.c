/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:26:22 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 22:58:52 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **argv, char **envp, int *fd)
{
	int		file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		return ;
	dup2(file_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd_exec(argv[2], envp);
}
