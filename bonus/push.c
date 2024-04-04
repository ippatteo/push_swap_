/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:30:52 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:58:21 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_pa(t_stack *stack)
{
	int	len;

	stack->last_a++;
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = stack->b[0];
	len = 0;
	while (len < stack->last_b)
	{
		stack->b[len] = stack->b[len + 1];
		len++;
	}
	stack->last_b--;
	stack->mosse++;
	return (1);
}

int	ft_pb(t_stack *stack)
{
	int	len;

	stack->last_b++;
	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->b[0] = stack->a[0];
	len = 0;
	while (len < stack->last_a)
	{
		stack->a[len] = stack->a[len + 1];
		len++;
	}
	stack->last_a--;
	stack->mosse++;
	return (1);
}
