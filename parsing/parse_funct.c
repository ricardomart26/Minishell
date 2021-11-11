/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:14:41 by rimartin          #+#    #+#             */
/*   Updated: 2021/11/11 12:06:59 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 
 * @definition: Verifica se a arvore foi criada ou se e so 1 node com 1 comando
 * 
 * @params: node -> Contem o node da ABT
 *  
 * @return_value: Retorna verdade (1) se o lado direito e esquerdo forem iguais 
 * a NULL 
 * Retorna falso de a arvore tiver mais que um comando
 * 
 */

bool	is_empty_tree(t_node *node)
{
	if (node->l == NULL && node->r == NULL)
		return (true);
	return (false);
}

void	c_and_next(int *c, int *next, char *str, int i)
{
	*c = str[i];
	if (str[i + 1])
		*next = str[i + 1];
	else
		*next = 0;
}

/**
 * 
 * @definition: Procura um caracter dentro de uma string
 * 
 * @params: c -> Caracter a procurar
 * str -> String para procurar o caracter
 *  
 * @return_value: Retorna 1 se encontrar
 * Retorna 0 se nao encontrar
 * 
 */

bool	find_c_in_str(int c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (true);
		str++;
	}
	return (false);
}

/**
 * 
 * @definition: Verifica se encontrou uma double quote ou single quote, se 
 * encontrar verifica se ja estava aberta ou se e para abrir agora. Se a single
 * quote ja estiver "aberta" entao se encontrar uma double quote 
 * 
 * @params:
 *  
 * @return_value:
 * 
 */

bool	check_quotes(t_token token, bool *open_dq, bool *open_q)
{
	if (token == DQ && !(*open_q))
	{
		if (*open_dq == false)
			*open_dq = true;
		else if (*open_dq == true)
			*open_dq = false;
		return (true);
	}
	else if (token == Q && !(*open_dq))
	{			
		if (*open_q == false)
			*open_q = true;
		else if (*open_q == true)
			*open_q = false;
		return (true);
	}
	return (false);
}
