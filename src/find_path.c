/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:35:59 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 17:19:53 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *argv)
{
	char	**path;
	char	*cmd_return;
	size_t	i;

	i = 0;
	cmd_return = argv;
	path = ft_split(PATH, ':');
	while (path[i] != NULL)
	{
		cmd_return = ft_strjoin(path[i], cmd_return);
		if (access(cmd_return, F_OK) == 0)
		{
			free_matrix(path);
			return (cmd_return);
		}
		free(cmd_return);
		i++;
	}
	free_matrix(path);
	return (NULL);
}
