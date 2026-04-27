/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:48:41 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 15:17:10 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// typedef enum e_op {
// 	SIMPLE,
// 	MEDIUM,
// 	COMPLEX
// } t_op;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	active;
}	t_bench;

void	bench_init(t_bench *bench, int active);
void	bench_count(t_bench *bench, char *op);
void	bench_print(t_bench *bench, double disorder,
			char *strategy, char *complexity);

typedef struct s_stack
{
	int value;            // Sayının kendisi
	int index;            // Sıralamadki konum
	struct s_stack *next; // Sonraki node
	struct s_stack *prev; // Önceki node
}		t_stack;

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

void	m_ss(t_stack **a, t_stack **b);
void	m_rr(t_stack **a, t_stack **b);
void	m_rrr(t_stack **a, t_stack **b);
void	m_sb(t_stack **b);
void	m_rb(t_stack **b);
void	m_rrb(t_stack **b);
void	m_sa(t_stack **a);
void	m_ra(t_stack **a);
void	m_rra(t_stack **a);
void	m_pb(t_stack **a, t_stack **b);
void	m_pa(t_stack **a, t_stack **b);

/*
** HELPERS
*/
int		is_sorted(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
int		find_position(t_stack *stack, int value);
/*


**algorithms
*/
void	min_push_to_b(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	simple_sort(t_stack **a, t_stack **b); //!!!!!!!!

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

int		get_all_bits(int max_index);
int		get_bit(int index, int bit);
void	radix_sort(t_stack **a, t_stack **b);

double	disorder(t_stack *a);
void	adaptive_sort(t_stack **a, t_stack **b);

/*
**UTILS
*/
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	ft_error(void);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);

/*
**PARSİNG
*/
int		is_number_string(char *s);
int		the_same(t_stack *a, int value);
int		add_number_to_stack(t_stack **a, char *token);
int		parse_arg(t_stack **a, char *arg);
int		parse_input(t_stack **a, int *mode, int ac, char **av);

#endif
