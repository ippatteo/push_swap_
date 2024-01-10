/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:13:38 by mcamilli          #+#    #+#             */
/*   Updated: 2023/12/30 14:10:37 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int checkna(int x, t_stack *stack)
{
	int i;

	while (i <= stack->last_a)
	{
		if (stack->a[i] == x && stack->a[i - 1] ==
		x-1 && stack->a[i + 1] == x+1)
			return(0);
		i++;
	}
	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] == x && stack->b[i-1] == x+1 &&
		stack->b[i+1] == x - 1)
			return (0);
		i++;
	}
	return (1);
}

int nstack(int x, t_stack *stack)
{
	int i;

	i = 0;
	while (i <= stack->last_a)
	{
		if (stack->a[i] == x)
			return (0);
		i++;
	}
	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] == x)
			return(1);
		i++;
	}
	return (-1);
}
int npos(int x, t_stack *stack)
{
	int i;
	int pos;

	pos = -1;
	i = 0;
	while (i <= stack->last_a)
	{
		if (stack->a[i] == x)
			return (pos);
		i++;
	}
	i = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] == x)
			return(pos);
		i++;
	}
	return (-1);
}


int nsure(int pos, int st, t_stack *stack)
{
	int n;

	n = 1;
	if (st)
	{
		while (stack->b[pos - n] == stack->b[pos] + n)
			n++;
		if (stack->b[pos + 1] == stack->b[pos] - 1)
		{
			while (stack->b[pos + n] == stack->b[pos] - n)
				n++;
		}
	}
	else
	{
		while (stack->a[pos - n] == stack->a[pos] - n)
			n++;
		if (stack->a[pos + 1] == stack->a[pos] + 1)
		{
			while (stack->a[pos + n] == stack->a[pos] + n)
			n++;
		}
	}
	return (n);
}

int n(int x, t_stack *stack)
{
	int pos;

	pos = npos(x, stack);
	if (checkna(x, stack))
	{
		return (nsure(pos, nstack(x, stack), stack));
	}
	else
		return(0);

}




