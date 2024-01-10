/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Majorminor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 06:35:14 by mcamilli          #+#    #+#             */
/*   Updated: 2023/12/30 16:11:31 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int takeminor(t_stack *stack, int x)
{
	int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] = x - 1)
		{
		if(x = stack->a[i + 1])
				return (0);
			return (stack->a[i]);
		}
		i++;
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] = x - 1)
		{
			if(x = stack->b[k - 1])
				return (0);
			return (stack->b[k]);
        }
		k++;
	}
	return (0);
}
int takemajor(t_stack *stack, int x)
{
    int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] = x + 1)
        {
        	if(x = stack->a[i - 1])
				return (0);
			return (stack->a[i]);
        }
		i++;
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] = x + 1)
        {
            if(x = stack->a[k + 1])
				return (0);
			return (stack->b[k]);
        }
		k++;
	}
	return (0);
}


int takemajorac(t_stack *stack, int x)
{
    int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] = 1)
        {
        	if(x = stack->a[i - 1])
				return (0);
			return (stack->a[i]);
        }
		i++;
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] = 1)
        {
            if(x = stack->b[k + 1])
				return (0);
			return (stack->b[k]);
        }
		k++;
	}
	return (0);
}

int takeminorone(t_stack *stack, int x, int ac)
{
    int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] = stack->max)
        {
        	if(x = stack->a[i - 1])
				return (0);
			return (stack->a[i]);
        }
		i++;
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] = stack->max)
		{
			if(x = stack->b[k + 1])
				return (0);
			return (stack->b[k]);
		}
		k++;
	}
	return (0);
}
