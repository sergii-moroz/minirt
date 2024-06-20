/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:19:31 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/07 13:06:13 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/common.h"
#include "../libft/libft.h"

// filename.rt
// /folder/filename.rt
/*void	check_input(char *str)
{
	int	i;
	int	alpha;

	if (!ft_strlen(str))
		error_fatal(RED"ERROR: File's name couldn't be empty line\n"RESET);
	//skip spaces
	i = 0;
	while (str + i && ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '\0')
		error_fatal(RED"ERROR: File's name should contain at least one letter\n"RESET);
	if (!ft_isalpha(*(str + i)))
		error_fatal(RED"ERROR: File's name should start from letter\n"RESET);
	i++;
	alpha = 1;
	while (str + i && ft_isalnum(*(str + i)))
	{
		i++;
		alpha++;
	}
	printf("\n");
}*/

void	check_input(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY, S_IRUSR);
	if (fd < 0)
	{
		error_fatal(RED"ERROR: bad file's name"RESET);
	}
	close(fd);
}
