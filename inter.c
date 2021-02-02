/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:22:52 by lucille           #+#    #+#             */
/*   Updated: 2021/01/26 16:22:53 by lucille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		check_in_str_before(int k, char *s1, int i)
{
	while (k >= 0)
		k = (s1[i] != s1[k]) ? k - 1 : -2;
	if (k == -1)
		write(1, &s1[i], 1);
	return (-1);
}

int		main(int ac, char *av[])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (ac == 3 && av[1][0] && av[2][0])
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j] && j > -1)
			{
				k = i - 1;
				if (av[1][i] != av[2][j])
					j++;
				else
					j = check_in_str_before(k, av[1], i);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
