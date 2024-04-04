/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:54 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	takemax(t_stack *stack)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i <= stack->last_a)
	{
		if (stack->a[i] > stack->a[a])
			a = i;
		i++;
	}
	return (a);
}

int	takemin(t_stack *stack)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i <= stack->last_a)
	{
		if (stack->a[i] < stack->a[a])
			a = i;
		i++;
	}
	return (a);
}

void	sort_three(t_stack *stack)
{
	int	max;
	int	min;

	min = takemin(stack);
	max = takemax(stack);
	if (min == 1 && max == 2)
		ft_sa(stack);
	else if (min == 2 && max == 0)
	{
		ft_sa(stack);
		ft_rra(stack);
		return ;
	}
	else if (min == 1 && max == 0)
		ft_ra(stack);
	else if (min == 2 && max == 1)
		ft_rra(stack);
	else if (min == 0 && max == 1)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
}

void	sort_four(t_stack *stack)
{
	if (stack->b[0] > stack->a[2])
		ft_pa(stack);
	else if (stack->b[0] > stack->a[1] && stack->b[0] < stack->a[2])
	{
		ft_rra(stack);
		ft_pa(stack);
	}
	else if (stack->b[0] > stack->a[0] && stack->b[0] < stack->a[1])
	{
		ft_ra(stack);
		ft_pa(stack);
	}
	else if (stack->b[0] < stack->a[0])
		ft_pa(stack);
}

void	sort_five(t_stack *stack)
{
	sort_four(stack);
	if (find_numfive(stack->a[0], stack) == 2)
	{
		ft_rra(stack);
		ft_pa(stack);
	}
	else if (find_numfive(stack->a[0], stack) == 1)
	{
		ft_ra(stack);
		ft_ra(stack);
		ft_pa(stack);
	}
	else if (find_numfive(stack->a[0], stack) == 0)
	{
		ft_ra(stack);
		ft_pa(stack);
	}
	else if (find_numfive(stack->a[0], stack) == 3)
		ft_pa(stack);
}
