/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:34:47 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 23:06:30 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char *argv, char **envp)
{
	char	**matrix;

	matrix = ft_split(argv, ' ');
	execve(find_path(matrix[0]), matrix, envp);
}

