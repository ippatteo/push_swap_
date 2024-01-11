/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_torc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/11 17:49:36 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void start_push(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
	if (stack->b[0] < stack->b[1])
		ft_swap(stack);
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
	if (num < stack->min || num > stack->max)
		return (stack->max);
	while (i <= stack->last_b)
	{
		if (stack->b[0])
		i++;
	}
	while (k <= stack->last_b)
	{
		if ()
			stack->posa = k ;
		if (stack->b[k] == x || stack->b[k] == y)
			stack->posb = k ;
		k++;
	}
}

int find_posb(int x, t_stack *stack)
{
	int i;

	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] = x)
			return (i);
		i++;
	}
	return (-1);
}
