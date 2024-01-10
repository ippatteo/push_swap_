/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:33:48 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/03 15:24:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int checktotal(t_stack *stack)
{
	int i;
	int num;

	num = 0;
	i = 0;
	while (i <= stack->last_a)
	{
		num += n(stack->a[i], stack);
		i++;
	}
	i = 0;
	while (i <= stack->last_b)
	{
		num += n(stack->a[i], stack);
		i++;
	}
	if (num >= (stack->max\2) * 4)
		return (1);
	else
		return(0);
}


int finalpush(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->last_a)
	{
		if (!(stack->a[i + 1] == stack->a[i] + 1))
			return (0);
		i++;
	}
	i = 0;
	while (i < stack->last_b)
	{
		if (!(stack->a[i + 1] == stack->a[i] - 1))
			return (0);
	i++;
	}
	return (1)
}

void points(t_stack *stack, int ac)
{
	stack->max = ac - 1;
	stack->mid = stack->max / 2;
}