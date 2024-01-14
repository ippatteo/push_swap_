/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_torc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/14 20:36:58 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void start_push(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
	if (stack->b[0] < stack->b[1])
		ft_sb(stack);
}

void takevalues(t_stack *stack) //a ogni giro trova il min e il max di b
{
	int i;

	i = 0;
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

	i = 0;
	takevalues(stack);
	if (num < stack->minb || num > stack->maxb)
		return (stack->maxb);
	while (i <= stack->last_b)
	{
		if (num > stack->b[0] && num < stack->b[stack->last_b])
			return(stack->b[0]);
		if (num < stack->b[i] && num > stack->b[i + 1])
			return (stack->b[i]);
		i++;
	}
	return (42);
}

int find_posb(int x, t_stack *stack) //trova la pos che devo far diventare 0
{
	int i;

	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

void setall(int posb, int posa, t_stack *stack)
{
	stack->defa = posa;
	stack->defb = posb;
}

void find_move(int posb, int posa, t_stack *stack)
{
	if (posb < posa)
	{
		if (stack->mosse > posa + 1) //upup
		{
			stack->mosse = posa + 1;
			stack->move = 1;
			setall(posb, posa, stack);
		}
		if (stack->mosse > (stack->last_a - posa + 1) +
		((stack->last_b - posb + 1) - (stack->last_a - posa + 1)) + 1) //down down
		{
			stack->mosse = (stack->last_b - posb + 1) +
			((stack->last_a - posa + 1) - (stack->last_b - posb + 1)) + 1;
			stack->move = 2;
			setall(posb, posa, stack);
		}
	}
	if (posa < posb)
	{
		if (stack->mosse > posb + 1) //upup
		{
			stack->mosse = posb + 1;
			stack->move = 1;
			setall(posb, posa, stack);
		}
		if (stack->mosse > (stack->last_b - posb + 1) +
		((stack->last_a - posa + 1) - (stack->last_b - posb + 1)) + 1) //down down
		{
			stack->mosse = (stack->last_b - posb + 1) +
			((stack->last_a - posa + 1) - (stack->last_b - posb + 1)) + 1;
			stack->move = 2;
			setall(posb, posa, stack);
		}
	}
	if (stack->mosse > (posb + 1 + (stack->last_a - posa) + 1)) // up down
	{
		stack->mosse = posb + 1 + (stack->last_a - posa) + 1;
		stack->move = 3;
		setall(posb, posa, stack);
	}
	if (stack->mosse > (stack->last_b - posb + 1 + posa + 1)) //down up
	{
		stack->mosse = stack->last_b - posb + 1 + posa + 1;
		stack->move = 4;
		setall(posb, posa, stack);
	}
}


void movesinuse(t_stack *stack)
{
	if (stack->move == 1 && stack->defb << stack->defa)
	{
		ft_upupamagb(stack);
	}
	if (stack->move == 1 && stack->defb >> stack->defa)
	{
		ft_upupaminb(stack);
	}
	if (stack->move == 2 && stack->defb << stack->defa)
	{
		ft_downdownamagb(stack);
	}
	if (stack->move == 2 && stack->defb << stack->defa)
	{
		ft_downdownaminb(stack);
	}
	if (stack->move == 3)
	{
		ft_updown(stack);
	}
	if (stack->move == 4)
	{
		ft_downup(stack);
	}
}

void ft_upupamagb(t_stack *stack)
{
	int i;

	i = stack->defb;
	while (i--)
		ft_rr(stack);
	i = stack->defa - stack->defb;
	while (i--)
	 ft_ra(stack);
	ft_pa(stack);
}

void ft_upupaminb(t_stack *stack)
{
	int i;

	i = stack->defa;
	while (i--)
		ft_rr(stack);
	i = stack->defb - stack->defa;
	while (i--)
	 ft_rb(stack);
	ft_pa(stack);
}

void ft_downdownamagb(t_stack *stack)
{
	int i;

	i = stack->last_a - stack->defa + 1;
	while (i--)
		ft_rrr(stack);
	i = (stack->last_b - stack->defb + 1) - (stack->last_a - stack->defa + 1);
	while (i--)
		ft_rrb(stack);
	ft_pa(stack);

}

void ft_downdownaminb(t_stack *stack)
{
	int i;

	i = stack->last_b - stack->defb + 1;
	while (i--)
		ft_rrr(stack);
	i = (stack->last_a - stack->defa + 1) - (stack->last_b - stack->defb + 1);
	while (i--)
		ft_rra(stack);
	ft_pb(stack);

}

void ft_updown(t_stack *stack)
{
	int i;

	i = stack->defb;
	while (i--)
		ft_rb(stack);
	i = stack->last_a - stack->defa + 1;
	while (i--)
		ft_rra(stack);
	ft_pb(stack);
}

void ft_downup(t_stack *stack)

{
	int i;

	i = stack->last_b - stack->defb + 1;
	while (i--)
		ft_rrb(stack);
	i = stack->defa;
	while (i--)
		ft_ra(stack);
	ft_pb(stack);
}

void mecha_torc(t_stack *stack)
{
	int k;

	k = 0;
	start_push(stack);
	while (stack->last_a != 0)
	{
		stack->mosse = 2000000;
		k = 0;
		while (k <= stack->last_a)
		{
			find_move(find_posb(find_num(stack->a[k], stack), stack), stack->a[k], stack);
			k++;
		}
		movesinuse(stack);
	}
	while (stack->last_b != 0)
		ft_pa(stack);
}

