/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 12:35:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_push(t_stack *stack)
{
	if (stack->last_a > 3)
	{
		ft_pb(stack);
		ft_pb(stack);
	}
	else if (stack->last_a == 3)
		ft_pb(stack);
}

void	takevalues(t_stack *stack) //a ogni giro trova il min e il max di b
{
	int	i;

	i = 0;
	if (stack->b[0] == -1)
		return ;
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

int	find_num(int num, t_stack *stack)//trova il numero sopra quale deve andare
{
	int	i;

	i = 1;
	if (num < stack->minb || num > stack->maxb)
		return (find_posb(stack->maxb, stack));
	while (i <= stack->last_b)
	{
		if (num > stack->b[0] && num < stack->b[stack->last_b])
			return (0);
		if (num > stack->b[i] && num < stack->b[i - 1])
			return (i);
		i++;
	}
	return (0);
}

int	find_posb(int x, t_stack *stack) //trova la posb che devo far diventare 0
{
	int	i;

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

void	setall(int posb, int posa, t_stack *stack)
{
	stack->defa = posa;
	stack->defb = posb;
}
