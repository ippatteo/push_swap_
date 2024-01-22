/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five 2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 11:29:25 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void startpush(t_stack *stack)
{
	if (stack->last_a > 3)
	{
		ft_pb(stack);
		ft_pb(stack);
	}
	else if (stack->last_a == 3)
		ft_pb(stack);
}
void sorts(t_stack *stack)
{
	startpush(stack);
	if(stack->last_a == 2)
		sort_three(stack);
	if (stack->last_b == -1)
		return;
	if(stack->last_a == 2 && stack->last_b == 0)
	{
		sort_four(stack);
		finalrotatea(stack);
		return;
	}
	if(stack->last_a == 2 && stack->last_b == 1)
	{
		sort_five(stack);
		finalrotatea(stack);
		return;
	}
	if (stack->last_a > 2)
		mecha_torc(stack);
}
void finalrotatea(t_stack *stack)
{
	int i;

	i = takemin(stack);
	if (i < stack->last_a / 2)
	{
		while (i--)
			ft_ra(stack);
	}
	else
	{
		i = stack->last_a - i + 1;
		while (i--)
			ft_rra(stack);
	}
}
