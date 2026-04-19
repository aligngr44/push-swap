#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value; // Sayının kendisi
	int				index; // Sıralamadki konum
	struct s_stack	*next; // Sonraki node
	struct s_stack	*prev; // Önceki node
}	t_stack;

/*
** LINKSTACK
*/
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_add_front(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int value);
int		stack_size(t_stack *stack);

/*
** MOVES
*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*
** HELPERS
*/
int		is_sorted(t_stack *stack);
int	stack_max(t_stack *stack);
int	stack_min(t_stack *stack);
int	find_position(t_stack *stack, int value);
/*


**algorithms
*/
void	min_push_to_b(t_stack **a, t_stack **b);
void sort_two(t_stack **a);
void	sort_three(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b);

void	indexing(t_stack *stack);
t_stack	*find_unindexed_min(t_stack *stack);

int		chunk_size(int size);
int		has_chunk_value(t_stack *a, int start, int end);
void	push_chunks_to_b(t_stack **a, t_stack **b);

int		stack_max_index(t_stack *stack);
int		find_position_by_index(t_stack *stack, int index);
void	rotate_b_to_top(t_stack **b, int target_index);
void	push_back_to_a(t_stack **a, t_stack **b);

void	chunk_sort(t_stack **a, t_stack **b);


/*
**UTILS
*/
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	ft_error(void);

/*
**PARSİNG
*/
int		is_number_string(char *s);
long	ft_atol(const char *str);
int		the_same(t_stack *a, int value);
int		add_number_to_stack(t_stack **a, char *token);
int		parse_arg(t_stack **a, char *arg);
int		parse_input(t_stack **a, int ac, char **av);

#endif