/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:17:53 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/13 22:48:46 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *message, int num)
{
	int	msg_len;

	msg_len = ft_strlen(message) + 1;
	write(2, message, msg_len);
	exit(num);
}
