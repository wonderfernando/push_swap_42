#include "push_swap.h"

long	particiona(long *v, long inicio, long fim)
{
	long	pivo;
	long	temp;

	pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
	while (inicio < fim)
	{
		while (inicio < fim && v[inicio] <= pivo)
			inicio++;
		while (inicio < fim && v[fim] > pivo)
			fim--;
		temp = v[inicio];
		v[inicio] = v[fim];
		v[fim] = temp;
	}
	return (inicio);
}



long	*getVetorSort(t_stack *a, long *tm)
{
	long	*vet;
	int		i;

	i = 0;
	vet = malloc(sizeof(long) * ft_stack_lstsize(a));
	while (a)
	{
		vet[i] = a->nbr;
		a = a->next;
		i++;
	}
	*tm = i;
	quicksort(vet, 0, i - 1);
	return (vet);
}

void	aproximacao(t_stack **a)
{
	int	index_min;

	index_min = ft_find_index(*a, ft_min(*a));
	if (index_min < ft_stack_lstsize(*a) / 2)
		while ((*a)->nbr != ft_min(*a))
			ft_ra(a, 0);
	else
		while ((*a)->nbr != ft_min(*a))
			ft_rra(a, 0);
}
void	aproximacao2(t_stack **pilha_b)
{
	int	index_max;

	index_max = ft_find_index(*pilha_b, ft_max(*pilha_b));
	if (index_max < ft_stack_lstsize(*pilha_b) / 2)
		while ((*pilha_b)->nbr != ft_max(*pilha_b))
			ft_rb(pilha_b, 0);
	else
		while ((*pilha_b)->nbr != ft_max(*pilha_b))
			ft_rrb(pilha_b, 0);
}
 

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}