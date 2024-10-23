/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:47:27 by ferda-si          #+#    #+#             */
/*   Updated: 2024/10/23 14:47:30 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit_str(char *str)
{
	while (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	liberty(char **tmp, char **tmp2, int argc)
{
	if ((!ft_isdigit_str(*tmp)) || ((ft_atoi_limit(*tmp) > 2147483647) \
		|| (ft_atoi_limit(*tmp) < -2147483648)))
	{
		if (argc == 2)
		{
			ft_freestr(tmp2);
			free(tmp2);
		}
		ft_error();
	}
}

void	verify_valid_number(char **argv, int argc)
{
	char	**tmp;
	char	**tmp2;

	if (argc == 2)
		tmp2 = ft_split(argv[1], 32);
	else
		tmp2 = argv + 1;
	tmp = tmp2;
	while (*tmp != NULL)
	{
		liberty(tmp, tmp2, argc);
		tmp++;
	}
	if (argc == 2)
	{
		ft_freestr(tmp2);
		free(tmp2);
	}
}
