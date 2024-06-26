/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:31:41 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:58:46 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_rra(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a];
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	stack->mosse++;
	return (1);
}

int	ft_rrb(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->b[stack->last_b];
	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->b[0] = tmp;
	stack->mosse++;
	return (1);
}

int	ft_rrr(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a];
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	tmp = stack->b[stack->last_b];
	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->b[0] = tmp;
	stack->mosse++;
	return (1);
}
