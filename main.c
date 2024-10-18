#include "push_swap.h"
t_stack	*ft_stack_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_stack_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}


 int	ft_atoi_limit(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

t_stack	*ft_init_sub(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
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
void	push(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stack_lstlast(*stack))->next = stack_new;
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
			a = ft_init_sub(argv);
		else
		{
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


void fill_index(t_stack **stack)
{
	t_stack *current = *stack;
	int index = 0;
	
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
 
int	ft_min(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	write(1, "pb\n", 3);
}

int	ft_max(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	while (a->nbr != nbr)
	{
		i = a->index;
		a = a->next;
	}
	return (i);
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
int main(int argc, char **argv) 
{
    t_stack *pilha_a;
    t_stack *pilha_b;
	pilha_b = NULL;
	if(argc == 1)
		return (0);

    pilha_a = ft_init(argc, argv);
	if (ft_checkdup(pilha_a))
	{
		ft_free(&pilha_a);
		ft_error();
	}

	if (ft_checksorted(pilha_a))
	{
		ft_free(&pilha_a);
	}
	else
	{
		if(ft_stack_lstsize(pilha_a) <= 10)
		{
			order_ten(&pilha_a, &pilha_b);
		}
	/* 	if (ft_stack_lstsize(pilha_a) > && ft_stack_lstsize(pilha_a)<= 200)
		{

		} */
	}
	return (0); 
}


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

	while(*pilha_b != NULL)
		ft_pa(pilha_a, pilha_b, 0);
		
}	

/* t_stack *tmp = pilha_a;
			while (tmp)
			{
				printf("%ld ", tmp->nbr);
				tmp = tmp->next;
			}
			printf("\n"); */