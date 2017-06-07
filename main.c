/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:33:09 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/07 16:03:57 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		main(int ac, char **av)
{
	t_type3	s;

	s.sq_s = 2;
	if (ac != 2 || ft_tetra_nb_char(av[1]) == 0 ||
			!(ft_tetra_valid(av[1], ft_tetra_nb_char(av[1]))))
	{
		ft_putstr("error\n");
		return (0);
	}
	s.nb_tetra = ((ft_tetra_nb_char(av[1]) - 20) / 21) + 1;
	s.file = (ft_tetra_valid(av[1], ft_tetra_nb_char(av[1])));
	s.coor = ft_tab_to_int(s.file, s.nb_tetra);
	s.square = ft_new_square(s.sq_s);
	while (ft_backtracking(s.square, s.sq_s, s.coor, s.nb_tetra) != 1)
	{
		s.sq_s++;
		s.square = ft_new_square(s.sq_s);
	}
	s.nb_tetra = 0;
	while (s.nb_tetra < s.sq_s)
	{
		ft_putstr(s.square[s.nb_tetra]);
		s.nb_tetra++;
	}
	return (0);
}