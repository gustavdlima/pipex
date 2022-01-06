/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:34:47 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/06 21:09:40 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*space_treat(char *cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == 39 && cmd[i + 1] == ' ' && cmd[i + 2] == 39)
			i = i + 2;
		if(cmd[i] == ' ')
			cmd[i] = ';';
		i++;
	}
	return (cmd);
}

void	cmd_exec(char *cmd, t_pipx *pipx)
{
	char	**matrix;
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			if (cmd[i + 1] == ' ' && cmd[i + 2] == 39)
			{
				space_treat(cmd);
				// dprintf(2, "%s\n", cmd);
				matrix = ft_split(cmd, ';');
				break ;
			}
		}
		else if (cmd[i + 1] == '\0')
		{
			matrix = ft_split(cmd, ' ');
			break ;
		}
		i++;
	}
	execve(find_path(matrix[0]), matrix, pipx->envp);
}
