/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:09:51 by olanokhi          #+#    #+#             */
/*   Updated: 2024/07/26 15:16:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	usage(void)
{
	printf("%sUsage:\n\t./miniRT [your-scene-file.rt]%s\n", YELLOW, RESET);
}

static int	is_file_rt(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 3, ".rt", 4) != 0)
		return (0);
	return (1);
}

int	is_args_valid(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("%sError: Provide scene '*.rt' as argument!%s\n", RED, RESET);
		usage();
		return (0);
	}
	else if (argc > 2)
	{
		printf("%sError: Too many arguments!%s\n", RED, RESET);
		usage();
		return (0);
	}
	else if (!is_file_rt(argv[1]))
	{
		printf("%sError: Invalid file extension!%s\n", RED, RESET);
		usage();
		return (0);
	}
	return (1);
}
