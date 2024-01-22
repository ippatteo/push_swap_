/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:31:52 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 11:34:15 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void find_move(int posb, int posa, t_stack *stack)
{
	if (posb <= posa)
	{
		if (stack->counterm > posa + 1)
		{
			stack->counterm = posa + 1;
			stack->move = 1;
			setall(posb, posa, stack);
		}
	}
	find_move_1(posb, posa, stack);
	find_move_2(posb, posa, stack);
}

void find_move_1(int posb, int posa, t_stack *stack)
{
	if (stack->last_b - posb <= stack->last_a - posa)
		{
			if (stack->counterm > stack->last_a - posa + 2)
			{
				stack->counterm = stack->last_a - posa + 2;
				stack->move = 2;
				setall(posb, posa, stack);
			}
		}
	if (stack->last_b - posb > stack->last_a - posa)
	{
		if (stack->counterm > stack->last_b - posb + 2)
		{
			stack->counterm = stack->last_b - posb + 2;
			stack->move = 2;
			setall(posb, posa, stack);
		}
	}
}

void find_move_2(int posb, int posa, t_stack *stack)
{
	if (posa < posb)
	{
		if (stack->counterm > posb + 1)
		{
			stack->counterm = posb + 1;
			stack->move = 1;
			setall(posb, posa, stack);
		}
	}
	if (stack->counterm > (posb + 1 + (stack->last_a - posa) + 1))
	{
		stack->counterm = posb + 1 + (stack->last_a - posa) + 1;
		stack->move = 3;
		setall(posb, posa, stack);
	}
	if (stack->counterm > (stack->last_b - posb + 1 + posa + 1))
	{
		stack->counterm = stack->last_b - posb + 1 + posa + 1;
		stack->move = 4;
		setall(posb, posa, stack);
	}
}


void movesinuse(t_stack *stack)
{

	if (stack->move == 1 && stack->defb <= stack->defa)
		ft_upupamagb(stack);
	else if (stack->move == 1 && stack->defb > stack->defa)
		ft_upupaminb(stack);
	else if (stack->move == 2 && stack->last_b - stack->defb <= stack->last_a - stack->defa)
		ft_downdownamagb(stack);
	else if (stack->move == 2 && stack->last_b - stack->defb > stack->last_a - stack->defa)
		ft_downdownaminb(stack);
	else if (stack->move == 3)
		ft_updown(stack);
	else if (stack->move == 4)
		ft_downup(stack);
}