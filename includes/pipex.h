/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:57:50 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/10 21:51:52 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PATH "/usr/local/sbin/:/usr/local/bin/:\
/usr/sbin/:/usr/bin/:/sbin/:/bin/"

typedef struct s_pipx {
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	int		error_flag;
}				t_pipx;

// start functions
void	start_struct(char **argv, char **envp, t_pipx *pipx);
void	pipex(t_pipx *pipx);

// proc functions
void	child_proc(int *fd, t_pipx *pipx);
void	parent_proc(int *fd, t_pipx *pipx);

// cmd exec funtions
void	cmd_exec(char *cmd, t_pipx *pipx);
char	**matrix_split(char *cmd, int cmd_size);

// cmd_treat functions
char	**cmd_treat(char **cmd_matrix);
char	*size_treat(char *cmd1, char *cmd2, int size);
char	*subs_letter(char *cmd1, char *cmd2, char *new_cmd, char letter);

// find path function
char	*find_path(char *cmd);

// utils
void	free_matrix(char **path);
char	*strjoin_free(char *s1, char const *s2);
char	*space_treat(char *cmd);
char	**reverse_space_treat(char **matrix);

// error
void	errors(char *string, int num);
void	cmd_check(t_pipx *pipx);

#endif
