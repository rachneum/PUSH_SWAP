#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
    int             value;
    int             index;
    int             push_cost;
    struct s_stack  *next;
    struct s_stack  *prev;
    struct s_stack  *target_node;
}                   t_stack;

/*static void push(t_stack **dst, t_stack **src);
static void	rev_rotate(t_stack **stack);
static void	rotate(t_stack **stack);
static long ft_atol(const char *str);
static void append(t_stack **stack, int nb);
static void	swap(t_stack **head);*/

void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **b, t_stack **a);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void    init_stack_a(t_stack **a, char **argv);

int main(int argc, char **argv);
int	error_syntax(char	*str_nb);
int	error_duplicate(t_stack *a, int nb);
int nb_len(int nbr);
int find_max(t_stack *a);
int radix_sort_index(t_stack *a);

t_stack *find_last_node(t_stack *stack);


#endif