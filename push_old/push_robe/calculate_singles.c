/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_singles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:42:52 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/03 15:24:17 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//trova a e b nei singoli stacks
void positionsingle(int x, int y, t_stack *stack)
{
	int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] == x || stack->a[i] == y)
			stack->posa = i ;
		if (stack->a[i] == x || stack->a[i] == y)
			stack->posb = i ;
		i++;
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] == x || stack->b[k] == y)
			stack->posa = k ;
		if (stack->b[k] == x || stack->b[k] == y)
			stack->posb = k ;
		k++;
	}
}
void monomoves_a(int x, int y, t_stack *stack)
{
	positionssingle(x, y, stack);
	calculate1arraya(stack);
}

void monomoves_b(int x, int y, t_stack *stack)
{
	positionssingle(x, y, stack);
    calculate1arrayb(stack);
}

void calculate1arraya(t_stack *stack)
{ 
    stack->mosse = 2000000;
	if (stack->a[stack->posa] > stack->a[stack->posb])
        smistamentostaamagb(stack);
    if (stack->a[stack->posa] < stack->a[stack->posb])
        smistamentostaaminb(stack);           
}

void smistamentostaamagb(t_stack *stack)
{
    if (stack->mosse > stack->posb + n(stack->posa, stack->a) + 1)
    {
        stack->mosse = stack->posb + n(stack->posa, stack->a) + 1;
        stack->move = 1;
    }
    if (stack->mosse > (2*(stack->posa + n(stack->posa, stack->a)) 
            + (stack->last_a - stack->posb)))
    {
        stack->mosse = (2*(stack->posa + n(stack->posa, stack->a)) 
        + (stack->last_a - stack->posb));
        stack->move = 2;
    }
    if (stack->mosse > (stack->last_a - stack->posa) +1 + n(stack->posb, stack->a))
    {
        stack->mosse = (stack->last_a - stack->posa) +1 + n(stack->posb, stack->a);
        stack->move = 3;
    }
    if (stack->mosse > 2*(stack->last_a - stack->posb) + 3 * n(stack->posb, stack->a) + stack->posa)
    {
        stack->mosse = 2*(stack->last_a - stack->posb) + 3 * n(stack->posb, stack->a) + stack->posa;
        stack->move = 4;
    }     
}

void smistamentostaaminb(t_stack *stack)
{
         if (stack->mosse > stack->posb + n(stack->posa, stack->a))
        {
            stack->mosse = stack->posb + n(stack->posa, stack->a);
            stack->move = 1;
        }
        if (stack->mosse > (2*stack->posa + stack->last_a - stack->posb +3))
        {
            stack->mosse = 2*stack->posa + stack->last_a - stack->posb +3;
            stack->move = 2;
        }
        if (stack->mosse > (stack->last_a + 2 * n(stack->posb, stack->a) + 1
             - n(stack->posa, stack->a) - stack->posa))
        {
            stack->mosse = stack->last_a + 2 * n(stack->posb, stack->a) + 1
                - n(stack->posa, stack->a) - stack->posa;
            stack->move = 3;
        }
        if (stack->mosse > 2*(stack->last_a - stack->posb) 
            + 2 + stack->posa + n(stack->posa, stack->a) + n(stack->posb, stack->a))
        {
            stack->mosse = 2*(stack->last_a - stack->posb) 
            + 2 + stack->posa + n(stack->posa, stack->a) + n(stack->posb, stack->a);
            stack->move = 4;
        }     
    }


    void calculate1arrayb(t_stack *stack)
{ 
    stack->mosse = 2000000;
	if (stack->a[stack->posa] > stack->a[stack->posb])
        smistamentostbamagb(stack);
    if (stack->a[stack->posa] < stack->a[stack->posb])
        smistamentostbaminb(stack);           
}
void smistamentostbaminb(t_stack *stack)
{
    if (stack->mosse > stack->posb + n(stack->posa, stack->b) + 1)
    {
        stack->mosse = stack->posb + n(stack->posa, stack->b) + 1;
        stack->move = 1;
    }
    if (stack->mosse > (2*(stack->posa + n(stack->posa, stack->b)) 
            + (stack->last_b - stack->posb)))
    {
        stack->mosse = (2*(stack->posa + n(stack->posa, stack->b)) 
        + (stack->last_b - stack->posb));
        stack->move = 2;
    }
    if (stack->mosse > (stack->last_b - stack->posa) +1 + n(stack->posb, stack->b))
    {
        stack->mosse = (stack->last_b - stack->posa) +1 + n(stack->posb, stack->b);
        stack->move = 3;
    }
    if (stack->mosse > 2*(stack->last_b - stack->posb) + 3 * n(stack->posb, stack->b) + stack->posa)
    {
        stack->mosse = 2*(stack->last_b - stack->posb) + 3 * n(stack->posb, stack->b) + stack->posa;
        stack->move = 4;
    }     
}

void smistamentostbamagb(t_stack *stack)
{
         if (stack->mosse > stack->posb + n(stack->posa, stack->b))
        {
            stack->mosse = stack->posb + n(stack->posa, stack->b);
            stack->move = 1;
        }
        if (stack->mosse > (2*stack->posa + stack->last_b - stack->posb +3))
        {
            stack->mosse = 2*stack->posa + stack->last_b - stack->posb +3;
            stack->move = 2;
        }
        if (stack->mosse > (stack->last_b + 2 * n(stack->posb, stack->a) + 1
             - n(stack->posa, stack->a) - stack->posa))
        {
            stack->mosse = stack->last_a + 2 * n(stack->posb, stack->a) + 1
                - n(stack->posa, stack->a) - stack->posa;
            stack->move = 3;
        }
        if (stack->mosse > 2*(stack->last_a - stack->posb) 
            + 2 + stack->posa + n(stack->posa, stack->a) + n(stack->posb, stack->a))
        {
            stack->mosse = 2*(stack->last_a - stack->posb) 
            + 2 + stack->posa + n(stack->posa, stack->a) + n(stack->posb, stack->a);
            stack->move = 4;
        }     
    }