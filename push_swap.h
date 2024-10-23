/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:53:30 by ferda-si          #+#    #+#             */
/*   Updated: 2024/10/21 19:53:34 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	long			key_nbr;
	long			tm_aux;
	struct s_stack	*next;
}	t_stack;

long			particiona(long *v, long inicio, long fim);
long			*get_vetor_sort(t_stack *a, long *tm);
long			ft_atoi_limit(const char *str);
int				ft_isdigit_str(char *str);
int				ft_isdigit(int c);
int				ft_checkdup(t_stack *a);
int				ft_checksorted(t_stack *stack_a);
int				ft_stack_lstsize(t_stack *lst);
int				ft_min(t_stack *a);
int				ft_max(t_stack *a);
int				ft_find_index(t_stack *a, int nbr);
size_t			ft_strlen(const char *s);
void			ft_error(void);
void			ft_ra(t_stack **a, int j);
void			liberty(char **tmp, char **tmp2, int argc);
void			verify_valid_number(char **argv, int argc);
void			ft_sa(t_stack **a, int j);
void			ft_pa(t_stack **a, t_stack **b, int j);
void			ft_rra(t_stack **a, int j);
void			ft_ss(t_stack **a, t_stack **b, int j);
void			push(t_stack **stack, t_stack *stack_new);
char			**ft_split(char const *s, char c);
void			ft_freestr(char **str);
void			ft_free(t_stack **lst);
void			fill_index(t_stack **stack);
void			ft_pb(t_stack **stack_a, t_stack **stack_b);
void			aproximacao(t_stack **a);
void			aproximacao2(t_stack **b);
void			ft_rrb(t_stack **b, int j);
void			ft_rb(t_stack **b, int j);
void			sort_true(t_stack **a);
void			order_ten(t_stack **pilha_a, t_stack **pilha_b);
void			quicksort(long *v, long inicio, long fim);
void			sort_aux(t_stack **pilha_a, t_stack **pilha_b);
void			order_hundred(t_stack **pilha_a, \
				t_stack **pilha_b, long diviser);
t_stack			*ft_stack_lstlast(t_stack *lst);
t_stack			*ft_init_sub(char **argv, int argc);
t_stack			*ft_stack_new(int content);
t_stack			*ft_init(int argc, char **argv);

#endif
