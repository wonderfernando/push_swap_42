/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:37:14 by ferda-si          #+#    #+#             */
/*   Updated: 2024/10/21 19:37:18 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

void	fill_index(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = -1;
	while (a->nbr != nbr)
	{
		i = a->index;
		a = a->next;
	}
	return (i);
}

void	push(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stack_lstlast(*stack))->next = stack_new;
}
