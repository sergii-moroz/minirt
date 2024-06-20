/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:53:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/06 13:16:49 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "../libft/libft.h"

# define POINT 1
# define SPACE 2
# define DIGIT 3
# define ALPHA 4

typedef struct s_lexer_data
{
	char	*s;
	int		i;
	char	current_char;
	int		had_error;
}			t_lexer_data;

#endif
