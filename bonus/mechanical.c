/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:10 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	mecha_torc(t_stack *stack)
{
	int	k;
	int	i;

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

void	finalmove(t_stack *stack)
{
	int	i;

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
