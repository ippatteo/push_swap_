/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renum_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:05:30 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/10 18:05:46 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void renum(t_stack *stack, int ac)
{
	int max;

    renum1(stack, ac, max);
    renum2(stack, ac, max);
    while (stack->tmp <= stack->limit)
    {
        stack->i = 0;
        while (stack->i <= stack->last_a)
        {
            if (stack->a[stack->i] == stack->tmp)
                stack->a[stack->i] = stack->tmp - stack->min + 1;
            stack->i++;
        }
        stack->tmp++;
    }
}


void renum1(t_stack *stack, int ac, int max)
{
	stack->tmpp2 = 0;
	stack->i = 0;
    stack->tmp = stack->a[0];
    max = stack->tmp;
    while (stack->i < ac - 2)
    {
        if (stack->a[stack->i] < stack->tmp)
            stack->tmp = stack->a[stack->i];
        stack->i++;
    }
    stack->min = stack->tmp;
    stack->limit = stack->tmp + (ac - 2);
    stack->i = 0;
     while (stack->i < ac - 2)
    {
        if (stack->a[stack->i] > max)
            max = stack->a[stack->i];
        stack->i++;
    }
}
void renum2(t_stack *stack, int ac, int max)
{
	 while (stack->tmp < stack->limit)
    {
        stack->tmp2 = max;
        stack->i = 0;
        stack->tmpp2 = stack->i;
        while( stack->i <= ac - 2)
        {
            if (stack->a[stack->i] <= stack->tmp2 && stack->a[stack->i] > stack->tmp)
            {
                stack->tmp2 = stack->a[stack->i];
                stack->tmpp2 = stack->i;
            }
            stack->i++;
        }
        stack->tmp++;
        stack->a[stack->tmpp2] = stack->tmp;
    }
    stack->tmp = stack->min;
    stack->max = stack->limit;
}

