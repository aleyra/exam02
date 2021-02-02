/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:22:52 by lucille           #+#    #+#             */
/*   Updated: 2021/01/27 10:59:52 by lucille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		main(int ac, char *av[])
{
	int		i;
	int		j;
	int		k;

	i = 1;
	if (ac == 3)
	{
		if (av[1][0])
			write(1, &av[1][0], 1);
		while (av[1][i])
		{
			j = i - 1;
			while (j > - 1)
				j = (av[1][i] != av[1][j]) ? j - 1 : -2;
			if (j = -1)
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			j = 0;
			while (j > -1 && av[1][j])
				j = (av[2][i] != av[1][j]) ? j + 1 : -1;
			if (j > -1)
			{
				k = i - 1;
				while (k > -1)
					k = (av[2][i] != av[2][k]) ? k - 1 : -2;
				if (k == -1)
					write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
