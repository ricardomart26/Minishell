/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:52:00 by rimartin          #+#    #+#             */
/*   Updated: 2021/12/02 22:24:32 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipes(int p[2], int save_fd, int index_for_pipes, int n_pipes)
{
	if (index_for_pipes == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
	}
	else if (index_for_pipes < n_pipes)
	{
		close(p[0]);
		dup2(save_fd, STDIN_FILENO);
		close(save_fd);
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
	}
	else
	{
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
	}
}

void	get_error_and_wait(void)
{
	int	status;

	waitpid(0, &status, 0);
	if (g_gl.error_code != 130)
		g_gl.error_code = status / 256;
}

int	close_and_save_p(t_pipes *p)
{
	get_error_and_wait();
	if (p->n_pipes == 0)
		return (0);
	if (p->index_for_pipes == 0)
	{
		close(p->pfd[1]);
	}
	else if (p->index_for_pipes < p->n_pipes)
	{
		close(p->pfd[0]);
		close(p->pfd[1]);

	}
	else
	{
		close(p->pfd[0]);
		close(p->pfd[1]);
	}
	return (p->save_fd);
}
