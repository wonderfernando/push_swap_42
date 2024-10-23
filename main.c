/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:30:38 by ferda-si          #+#    #+#             */
/*   Updated: 2024/10/21 19:30:46 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_init_sub(char **argv, int argc)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	verify_valid_number(argv, argc);
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi_limit(tmp[i]);
		push(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			a = ft_init_sub(argv, argc);
		else
		{
			verify_valid_number(argv, argc);
			while (i < argc)
			{
				j = ft_atoi_limit(argv[i]);
				push(&a, ft_stack_new(j));
				i++;
			}
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*pilha_a;
	t_stack	*pilha_b;

	pilha_b = NULL;
	pilha_a = ft_init(argc, argv);
	if (pilha_a == NULL)
		return (0);
	if (ft_checkdup(pilha_a))
	{
		ft_free(&pilha_a);
		ft_error();
	}
	if (ft_checksorted(pilha_a))
		ft_free(&pilha_a);
	else
	{
		if (ft_stack_lstsize(pilha_a) <= 10)
			order_ten(&pilha_a, &pilha_b);
		if (ft_stack_lstsize(pilha_a) > 10 && ft_stack_lstsize(pilha_a) <= 200)
			order_hundred(&pilha_a, &pilha_b, 4);
		if (ft_stack_lstsize(pilha_a) > 200)
			order_hundred(&pilha_a, &pilha_b, 16);
		ft_free(&pilha_a);
	}
	return (0);
}
