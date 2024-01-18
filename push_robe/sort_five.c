/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/18 18:07:29 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int takemax(t_stack *stack) //a ogni giro trova il min e il max di b
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i <= stack->last_a)
	{

		if (stack->b[i] < stack->a[a])
			a = i;
		i++;
	}
	return(a);
}


int takemin(t_stack *stack) //a ogni giro trova il min e il max di b
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i <= stack->last_a)
	{

		if (stack->b[i] > stack->a[a])
			a = i;
		i++;
	}
	return(a);
}

