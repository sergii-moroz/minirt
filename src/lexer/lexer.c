/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:49 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/06 13:18:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

static void	lexer_init(char *s, t_lexer_data *data)
{
	data->s = s;
	data->i = 0;
	data->had_error = 0;
	data->current_char = NULL;
	if (s)
		data->current_char = *s;
}

void	advance(t_lexer_data *data)
{

}

t_list	*lexer(char *line)
{
	t_lexer_data	data;
	t_list			*tokens;

	tokens = NULL;
	lexer_init(line, &data);
}
