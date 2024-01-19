/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:26 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/19 20:28:39 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

#include <stdio.h> //remove this

# define ERR "Error\n"

typedef struct s_data
{
	struct s_data	*next;
	void			*data;
}	t_data;

typedef struct s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int					value;
	int					current_position;
	int					push_price;
	int					above_median;
	int					cheapest;
}				t_stack_node;

/* commands */
void			pa(t_stack_node **a, t_stack_node **b, int checker);
void			pb(t_stack_node **b, t_stack_node **a, int checker);

void			rra(t_stack_node **a, int checker);
void			rrb(t_stack_node **b, int checker);
void			rrr(t_stack_node **a, t_stack_node **b, int checker);

void			ra(t_stack_node **a, int checker);
void			rb(t_stack_node **b, int checker);
void			rr(t_stack_node **a, t_stack_node **b, int checker);

void			sa(t_stack_node **a, int checker);
void			sb(t_stack_node **b, int checker);
void			ss(t_stack_node **a, t_stack_node **b, int checker);

//command_utils
int				lst_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);

//push_swap_init
void			set_current_position(t_stack_node *stack);
void			set_push_price(t_stack_node *a, t_stack_node *b);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *a);
void			init_nodes(t_stack_node *a, t_stack_node *b);

//init_stack
void			append_node(t_stack_node **a, int num);
t_stack_node	*find_smallest(t_stack_node *a);
int				init_stack(t_stack_node **a, char *argv[]);
char			**parsed(char *argv[], int argc);
//tiny_sort
int				is_sorted(t_stack_node *a);
void			tiny_sort(t_stack_node **a);
int				handle_5(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_highest(t_stack_node *a);

//error_syntax
int				err_syntax(char *str);
int				err_rep(t_stack_node *a, int num);
void			free_stack(t_stack_node **a, char *argv[]);
void			free_matrice(char *argv[]);

//libft functions
long			ft_atol(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *s, char c);

//controller
void			finish_rot(t_stack_node **stack,
					t_stack_node *cheap_node, char stack_n);
void			rotate_everything(t_stack_node **a, t_stack_node **b);

//median algo
int				find_median(t_stack_node *a);

//my_malloc
void			*my_malloc(size_t size, int mode);
#endif
