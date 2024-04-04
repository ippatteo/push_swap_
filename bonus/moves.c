/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:15 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_upupamagb(t_stack *stack)
{
	int	i;

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

void	ft_upupaminb(t_stack *stack)
{
	int	i;

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

void	ft_downdownamagb(t_stack *stack)
{
	int	i;

	i = stack->last_b - stack->defb + 1;
	if (stack->last_a - stack->defa == stack->last_b - stack->defb)
	{
		while (i > 0)
		{
			ft_rrr(stack);
			i--;
		}
		return ;
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

void	ft_downdownaminb(t_stack *stack)
{
	int	i;

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

void	ft_updown(t_stack *stack)
{
	int	i;

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
