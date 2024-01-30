/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 14:45:39 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_numfive(int num, t_stack *stack)
{
	int	i;

	i = 1;
	if (num < takemin(stack) || num > takemax(stack))
		return (find_posa(takemax(stack), stack));
	while (i <= stack->last_b)
	{
		if (num > stack->a[0] && num < stack->a[stack->last_b])
			return (0);
		if (num > stack->a[i] && num < stack->a[i - 1])
			return (i);
		i++;
	}
	return (0);
}

int	find_posa(int x, t_stack *stack) //trova la posb che devo far diventare 0
{
	int	i;

	i = 0;
	while (i <= stack->last_a)
	{
		if (stack->a[i] == x)
			return (i);
		i++;
	}
	return (0);
}
