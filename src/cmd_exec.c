/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:34:47 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/14 19:40:36 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**matrix_split(char *cmd, int cmd_size)
{
	int		i;
	char	**matrix;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			space_treat(cmd);
			matrix = ft_split(cmd, ' ');
			reverse_space_treat(matrix);
			cmd_treat(matrix);
			break ;
		}
		else if (cmd[i] == cmd[cmd_size])
		{
			matrix = ft_split(cmd, ' ');
			break ;
		}
		i++;
	}
	return (matrix);
}

void	cmd_exec(char *cmd, t_pipx *pipx)
{
	char	*cmd_path;
	char	**matrix;
	int		cmd_size;

	cmd_size = ft_strlen(cmd) - 1;
	matrix = matrix_split(cmd, cmd_size);
	cmd_path = find_path(matrix[0]);
	if (cmd_path == NULL)
	{
		free_matrix(matrix);
		error_msg("Command not found.\n", 127);
	}
	execve(cmd_path, matrix, pipx->envp);
}
