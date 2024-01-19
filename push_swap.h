/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:06:42 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/19 14:41:46 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
    int mosse;
	int counterm;
    int last_a;
    int last_b;
    int move; // id della mossa
    //int posa;
    //int posb;
    int defa;
    int defb;
	int minb;
	int maxb;
	int error;
	int stck;
}	t_stack;
void setmain(int ac, t_stack *stack);
void finalrotatea(t_stack *stack);
void sorts(t_stack *stack);
void startpush(t_stack *stack);
void sort_five(t_stack *stack);
void sort_four(t_stack *stack);
void sort_three(t_stack *stack);
int takemin(t_stack *stack);
int takemax(t_stack *stack);
void find_move_1(int posb, int posa, t_stack *stack);
void find_move_2(int posb, int posa, t_stack *stack);
int controlst(t_stack *stack);
void	ft_cazzo(t_stack *stack);
void	finalmove(t_stack *stack);
void	printarrayb(int *i, t_stack *stack);
void	mecha_torc(t_stack *stack);
void	ft_downup(t_stack *stack);
void	ft_updown(t_stack *stack);
void	ft_downdownaminb(t_stack *stack);
void	ft_downdownamagb(t_stack *stack);
void	ft_upupaminb(t_stack *stack);
void	ft_upupamagb(t_stack *stack);
void	movesinuse(t_stack *stack);
void	find_move(int posb, int posa, t_stack *stack);
void	setall(int posb, int posa, t_stack *stack);
int		find_posb(int x, t_stack *stack);
int		find_num(int num, t_stack *stack);
void	takevalues(t_stack *stack);
void	start_push(t_stack *stack);
void	error(int ac, t_stack *stack);
int		ft_atoi(char *str, t_stack *stack);
int		ft_isdigit(int c);
void	ft_exit(t_stack *stack);
int		checkdoubles(int ac, t_stack *stack);
void	printarray(int *i, t_stack *stack);
void	takeints(t_stack *stack, int ac, char **av);
int		ft_rra(t_stack *stack);
int	ft_rrb(t_stack *stack);
int	ft_rrr(t_stack *stack);
int	ft_ra(t_stack *stack);
int	ft_rb(t_stack *stack);
int	ft_rr(t_stack *stack);
int	ft_sa(t_stack *stack);
int	ft_sb(t_stack *stack);
int	ft_ss(t_stack *stack);
int	ft_pa(t_stack *stack);
int	ft_pb(t_stack *stack);
#endif
