/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_torc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 11:34:59 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void start_push(t_stack *stack)
{
	if (stack->last_a > 3)
	{
		ft_pb(stack);
		ft_pb(stack);
	}
	else if (stack->last_a == 3)
		ft_pb(stack);
}

void takevalues(t_stack *stack) //a ogni giro trova il min e il max di b
{
	int i;

	i = 0;
	if (stack->b[0] == -1)
		return;
	stack->minb = stack->b[0];
	while (i <= stack->last_b)
	{

		if (stack->b[i] < stack->minb)
			stack->minb = stack->b[i];
		i++;
	}
	i = 0;
	stack->maxb = stack->b[0];
	while (i <= stack->last_b)
	{

		if (stack->b[i] > stack->maxb)
			stack->maxb = stack->b[i];

		i++;
	}
}

int find_num(int num, t_stack *stack)//trova il numero sopra quale deve andare
{
	int i;

	i = 1;
	if (num < stack->minb || num > stack->maxb)
		return (find_posb(stack->maxb, stack));
	while (i <= stack->last_b)
	{
		if (num > stack->b[0] && num < stack->b[stack->last_b])
			return(0);
		if (num > stack->b[i] && num < stack->b[i - 1])
			return (i);
		i++;
	}
	return (0);
}




int find_posb(int x, t_stack *stack) //trova la posb che devo far diventare 0
{
	int i;

	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] == x)
			return (i);
		i++;
	}
	ft_exit(stack);
	return (0);
}

void setall(int posb, int posa, t_stack *stack)
{
	stack->defa = posa;
	stack->defb = posb;
}



void ft_upupamagb(t_stack *stack)
{
	int i;

	i = stack->defb;
	while (i > 0)
	{
		ft_rr(stack);
		i--;
	}
	i = stack->defa - stack->defb;
	while (i > 0)
	{
		ft_ra(stack);
		i--;
	}
	ft_pb(stack);
}

void ft_upupaminb(t_stack *stack)
{
	int i;

	i = stack->defa;
	while (i > 0)
	{
		ft_rr(stack);
		i--;
	}
	i = stack->defb - stack->defa;
	while (i > 0)
	{
		ft_rb(stack);
		i--;
	}
	ft_pb(stack);
}

void ft_downdownamagb(t_stack *stack)
{
	int i;

	i = stack->last_b - stack->defb + 1;
	if (stack->last_a - stack->defa == stack->last_b - stack->defb)
	{
		while (i > 0)
		{
			ft_rrr(stack);
			i--;
		}
		return;
	}
	while (i > 0)
	{
		ft_rrr(stack);
		i--;
	}
	i = (stack->last_a - stack->defa + 1) - (stack->last_b - stack->defb + 1);
	while (i > 0)
	{
		ft_rra(stack);
		i--;
	}
	ft_pb(stack);
}

void ft_downdownaminb(t_stack *stack)
{
	int i;

	i = stack->last_a - stack->defa + 1;
	while (i > 0)
	{
		ft_rrr(stack);
		i--;
	}
	i = (stack->last_b - stack->defb + 1) - (stack->last_a - stack->defa + 1);
	while (i > 0)
	{
		ft_rrb(stack);
		i--;
	}
	ft_pb(stack);
}

void ft_updown(t_stack *stack)
{
	int i;

	i = stack->defb;
	while (i > 0)
	{
		ft_rb(stack);
		i--;
	}
	i = stack->last_a - stack->defa + 1;
	while (i > 0)
	{
		ft_rra(stack);
		i--;
	}
	ft_pb(stack);
}

void ft_downup(t_stack *stack)

{
	int i;

	i = stack->last_b - stack->defb + 1;
	while (i > 0)
	{
		ft_rrb(stack);
		i--;
	}
	i = stack->defa;
	while (i > 0)
	{
		ft_ra(stack);
		i--;
	}
	ft_pb(stack);
}

void mecha_torc(t_stack *stack)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (stack->last_a > -1)
	{
		takevalues(stack);
		stack->counterm = 2000000;
		k = 0;
		while (k <= stack->last_a)
		{
			i = find_num(stack->a[k], stack);
			find_move(i, k, stack);
			k++;
		}
		movesinuse(stack);
	}
	finalmove(stack);
}
/*void mecha_torc(t_stack *stack)
{
	int k;

	k = 0;
	start_push(stack);
	//ft_printf("last_a = %d \n", stack->last_a);
	while (stack->last_a != -1)
	{
		//ft_printf("while1");
		stack->counterm = 2000000;
		k = 0;
		while (k <= stack->last_a)
		{
			find_move(find_posb(find_num(stack->a[k], stack), stack), stack->a[k], stack);
			k++;
			//ft_printf("k  progressione= %d \n", k);

		}
		//movesinuse(stack);
		//return;
	}
	while (stack->last_b != -1)
		ft_pa(stack);
}*/

void	finalmove(t_stack *stack)
{
	int i;

	takevalues(stack);
	i = find_posb(stack->maxb, stack);
	if (i <= stack->last_b - i + 1)
	{
		while (i--)
			ft_rb(stack);
	}
	else
	{
		i = stack->last_b - i + 1;
		while (i--)
			ft_rrb(stack);
	}
	while (stack->last_b != -1)
		ft_pa(stack);
}