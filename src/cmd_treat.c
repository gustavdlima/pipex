/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:49:23 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/13 19:26:33 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*size_treat(char *cmd)
{
	char	*new_cmd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_cmd = ft_calloc((ft_strlen(cmd) - 1), 4);
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i] && cmd[i] != 39)
			{
				new_cmd[j] = cmd[i];
				i++;
				j++;
			}
		}
		i++;
	}
	new_cmd[j] = '\0';
	free(cmd);
	return (new_cmd);
}

char	**cmd_treat(char **cmd_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (cmd_matrix[i])
	{
		j = 0;
		while (cmd_matrix[i][j])
		{
			if (cmd_matrix[i][j] == 39)
				cmd_matrix[i] = size_treat(cmd_matrix[i]);
			j++;
		}
		i++;
	}
	return (cmd_matrix);
}
