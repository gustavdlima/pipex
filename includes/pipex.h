/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:57:50 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/14 19:56:37 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

# define PATH "/usr/local/sbin/:/usr/local/bin/:\
/usr/sbin/:/usr/bin/:/sbin/:/bin/"

typedef struct s_pipx {
	char	**matrix;
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	**cmd1_matrix;
	char	*cmd2;
	char	**cmd2_matrix;
	char	**envp;
	int		infile_open;
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
void	cmd_check(t_pipx *pipx);
char	**matrix_split(char *cmd, int cmd_size);

// cmd_treat functions
char	**cmd_treat(char **cmd_matrix);
char	*size_treat(char *cmd);

// find path function
char	*find_path(char *cmd);

// utils
void	check_dup(int a, int b);
void	free_matrix(char **path);
char	*strjoin_free(char *s1, char const *s2);
char	*space_treat(char *cmd);
char	**reverse_space_treat(char **matrix);

// error
void	error_msg(char *message, int num);
void	free_array(char *array);
void	free_matrix(char **matrix);

#endif
