/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:35:59 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 23:42:13 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *argv)
{
	char	**path;
	char	*cmd_return;
	char	*temp;
	size_t	i;

	i = 0;
	path = ft_split(PATH, ':');
	while (path[i] != NULL)
	{
		temp = ft_strjoin(path[i], "/");
		cmd_return = ft_strjoin(temp, argv);
		if (access(cmd_return, F_OK) == 0)
		{
			free_matrix(path);
			return (cmd_return);
		}
		free(temp);
		free(cmd_return);
		i++;
	}
	free_matrix(path);
	return (NULL);
}
