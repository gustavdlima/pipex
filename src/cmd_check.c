/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:34:35 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/10 21:50:35 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*subs_letter(char *cmd1, char *cmd2, char *new_cmd, char letter)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (cmd2[i])
	{
		new_cmd[i] = cmd2[i];
		if (cmd2[i + 1] == 39)
		{
			while (cmd1[i] != 39)
			{
				new_cmd[i] = letter;
				i++;
			}
			break ;
		}
		i++;
		j++;
	}
	new_cmd[ft_strlen(cmd1) - 1] = 39;
	new_cmd[ft_strlen(cmd1)] = '\0';
	return (new_cmd);
}

char	*size_treat(char *cmd1, char *cmd2, int size)
{
	char	*new_cmd;
	char	word;

	new_cmd = malloc(sizeof(char) * size);
	if (ft_strlen(cmd2) != ft_strlen(cmd1))
	{
		word = cmd2[ft_strlen(cmd2) - 2];
		new_cmd = subs_letter(cmd1, cmd2, new_cmd, word);
		free(cmd2);
		return (new_cmd);
	}
	else
		return (cmd2);
}

void	cmd_check(t_pipx *pipx)
{
	char	**matrix;
	char	*cmd1;
	char	*cmd2;

	pipx->error_flag = 0;
	matrix = ft_split(pipx->cmd1, ' ');
	cmd1 = find_path(matrix[0]);
	free_matrix(matrix);
	matrix = ft_split(pipx->cmd2, ' ');
	cmd2 = find_path(matrix[0]);
	free_matrix(matrix);
	if (cmd1 == NULL || cmd2 == NULL)
		pipx->error_flag = 127;
}
