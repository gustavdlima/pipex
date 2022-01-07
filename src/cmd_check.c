/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:34:35 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/07 19:05:15 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_check(t_pipx *pipx)
{
	char	**matrix;
	char	*cmd1;
	char	*cmd2;

	pipx->error_flag = 0;
	matrix = ft_split(pipx->cmd1, ' ');
	cmd1 =  find_path(matrix[0]);
	free_matrix(matrix);
	matrix = ft_split(pipx->cmd2, ' ');
	cmd2 = find_path(matrix[0]);
	free_matrix(matrix);
	if (cmd1 == NULL || cmd2 == NULL)
		pipx->error_flag = 127;
	return(pipx->error_flag);
}
