/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:31:33 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:59:04 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_ra(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	stack->mosse++;
	return (1);
}

int	ft_rb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	stack->mosse++;
	return (1);
}

int	ft_rr(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->last_a)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	i = -1;
	tmp = stack->b[0];
	while (++i < stack->last_b)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	stack->mosse++;
	return (1);
}
