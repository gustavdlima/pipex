/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:59:00 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/13 21:23:55 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_dup(int a, int b)
{
	if (dup2(a, b) == -1)
	{
		write(2, "Permission denied\n", 19);
		exit(1);
	}
	close(a);
}
