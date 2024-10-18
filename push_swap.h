#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Protótipos das funções
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
typedef struct s_stack
{
	long            nbr;
	long            index;
	long            key_nbr;
	long            tm_aux;
	struct s_stack  *next;
} t_stack;

// Funções relacionadas à pilha
t_stack *ft_stack_lstlast(t_stack *lst);
void    ft_error(void);
void    ft_ra(t_stack **a, int j);
void    ft_sa(t_stack **a, int j);
void    ft_pa(t_stack **a, t_stack **b, int j);
void    ft_rra(t_stack **a, int j);
void    ft_ss(t_stack **a, t_stack **b, int j);
int     ft_atoi_limit(const char *str);
t_stack *ft_init_sub(char **argv);
void    push(t_stack **stack, t_stack *stack_new);
t_stack *ft_stack_new(int content);
t_stack *ft_init(int argc, char **argv);
void	order_ten(t_stack **pilha_a, t_stack **pilha_b);
// Funções auxiliares
int     ft_isdigit(int c);
size_t  ft_strlen(const char *s);
char    **ft_split(char const *s, char c);
static int  count_words(const char *s, char c);  // Faltando implementação
static char    *word_dup(const char *s, int start, int end);  // Faltando implementação
void    ft_freestr(char **str);  // Faltando implementação
void	ft_free(t_stack **lst);
int	ft_checkdup(t_stack *a);
int	ft_checksorted(t_stack *stack_a);
void	fill_index(t_stack **stack);
int		ft_stack_lstsize(t_stack *lst);
int		ft_min(t_stack *a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
int		ft_max(t_stack *a);
int		ft_find_index(t_stack *a, int nbr);
void	aproximacao(t_stack **a);
void	sort_true(t_stack **a);
 
#endif 