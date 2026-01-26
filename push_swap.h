/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:23:30 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:23:34 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				size;
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				chunk_counter;
	int				chunk_length;
	int				chunk_amount;
}					t_chunk;

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

int					stack_size(t_stack *a);
void				set_indexes(t_stack **stack_a);
void				setup(t_stack **a, int total_size, t_chunk *chunk);
void				push_to_b(t_stack **a, t_stack **b, t_chunk *chunk);
void				push_to_a(t_stack **a, t_stack **b);

int					ft_atoi(const char *str, int *error);
int					has_duplicates(t_stack *a, int value);
int					parse_arguments(int ac, char **av, t_stack **a);
int					init_new_node(t_stack **a, int value);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *a);
void				reverse_stack(t_stack **a);
int					count_words(char *str);
char				**split_arguments(char *str, int *count);
void				free_split(char **arr);
int					in_chunk(t_stack *node, t_chunk *chunk);
int					chunk_in_stack(t_stack *a, t_chunk *chunk);
t_stack				*find_closest_in_chunk(t_stack *a, t_chunk *chunk);
void				set_positions(t_stack *stack);
int					get_min_index_pos(t_stack *a);
void				set_target_pos(t_stack *a, t_stack *b);
void				set_costs(t_stack *b);
int					calculate_total_cost(int cost_a, int cost_b);
t_stack				*get_cheapest(t_stack *b);
void				execute_move(t_stack **a, t_stack **b, t_stack *cheapest);
void				final_rotate(t_stack **a);
void				rra_no_write(t_stack **stack_a);
void				rrb_no_write(t_stack **stack_b);
void				sa_no_write(t_stack **stack_a);
void				sb_no_write(t_stack **stack_b);
void				ss_no_write(t_stack **stack_a, t_stack **stack_b);
void				pa_no_write(t_stack **stack_a, t_stack **stack_b);
void				pb_no_write(t_stack **stack_a, t_stack **stack_b);
void				ra_no_write(t_stack **stack_a);
void				rb_no_write(t_stack **stack_b);
void				rr_no_write(t_stack **stack_a, t_stack **stack_b);
void				rrr_no_write(t_stack **stack_a, t_stack **stack_b);
int					parse_input(int ac, char **av, t_stack **a);

#endif