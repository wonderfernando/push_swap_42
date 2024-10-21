/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:41:33 by ferda-si          #+#    #+#             */
/*   Updated: 2024/10/21 19:41:39 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	order_ten(t_stack **pilha_a, t_stack **pilha_b)
{
	if (ft_stack_lstsize(*pilha_a) == 2 && !ft_checksorted(*pilha_a))
		ft_sa(pilha_a, 0);
	while (ft_stack_lstsize(*pilha_a) > 3 && !ft_checksorted(*pilha_a))
	{
		fill_index(pilha_a);
		aproximacao(pilha_a);
		ft_pb(pilha_a, pilha_b);
	}
	if (!ft_checksorted(*pilha_a) && ft_stack_lstsize(*pilha_a) == 3)
		sort_true(pilha_a);
	while (*pilha_b != NULL)
	{
		fill_index(pilha_b);
		aproximacao2(pilha_b);
		ft_pa(pilha_a, pilha_b, 0);
	}	
}

void	quicksort(long *v, long inicio, long fim)
{
	long	pos;

	if (inicio < fim)
	{
		pos = particiona(v, inicio, fim);
		quicksort(v, inicio, pos - 1);
		quicksort(v, pos, fim);
	}
}

void	sort_aux(t_stack **pilha_a, t_stack **pilha_b)
{
	int		index_min;
	long	aux;
	t_stack	*tmp;

	aux = (*pilha_a)->key_nbr;
	tmp = *pilha_a;
	while (tmp)
	{
		if (tmp->nbr <= aux)
		{
			fill_index(pilha_a);
			index_min = ft_find_index(*pilha_a, tmp->nbr);
			if ((index_min < ft_stack_lstsize(*pilha_a) / 2))
				while ((*pilha_a)->nbr != tmp->nbr)
					ft_ra(pilha_a, 0);
			else
				while ((*pilha_a)->nbr != tmp->nbr)
					ft_rra(pilha_a, 0);
			while (*pilha_a && (*pilha_a)->nbr <= aux)
				ft_pb(pilha_a, pilha_b);
			tmp = *pilha_a;
		}
		tmp = tmp->next;
	}
}

void	order_hundred(t_stack **pilha_a, t_stack **pilha_b, long diviser)
{
	long	*vetor_sort;
	long	diviser_count;
	long	vetor_size;

	diviser_count = 1;
	vetor_sort = get_vetor_sort(*pilha_a, &vetor_size);
	while (diviser_count < diviser && \
			!ft_checksorted(*pilha_a) && ft_stack_lstsize(*pilha_a) > 10)
	{
		(*pilha_a)->key_nbr = \
			vetor_sort[((diviser_count * vetor_size) / diviser) - 1];
		sort_aux(pilha_a, pilha_b);
		diviser_count++;
	}
	order_ten(pilha_a, pilha_b);
	free(vetor_sort);
}

void	sort_true(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->next->nbr)
	{
		ft_rra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else
		ft_sa(a, 0);
}
