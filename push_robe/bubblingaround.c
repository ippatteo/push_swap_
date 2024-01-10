/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblingaround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:29:53 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/03 15:24:16 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../push_swap.h"

void dispari(t_stack *stack)
{
    while(stack->last_b + 1 != ((ac - 1)/2)) //+ (ac - 1)%2)) questo pezzo serve se devo avere numeri dispari su b
    {
        if (stack->a[0]%2 && stack->a[0] != stack->max)
            ft_pb(stack);
        else
            ft_ra(stack);
    }
}
//  quando si fa la sccannerizzazione per i numeri ricordarsi che nell'eventualità di
//avere tutto su uno strack a deve stare SOPRA e b SOTTO
//mi traduce i numeri in posizioni e appartenenza a stack
int calculatestacks(int x, int y, t_stack *stack)
{
	int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->a[i] == x || stack->a[i] == y)
			stack->stck += 10;
		i++:
	}
	while (k <= stack->last_b)
	{
		if (stack->b[k] == x || stack->b[k] == y)
			stack->stck += 1 ;
		k++;
	}
	if (k > stack->last_b)
        calculate1arraya(stack);
	else if (i > stack->last_a)
        calculate1arrayb(stack);
}







int calculatenumbers(int x, int y, t_stack *stack)
{
	int i;
	int k;

	while (i <= stack->last_a)
	{
		if (stack->stack_a[i] == x || stack->stack_a[i] == y)
			stack->posa = i ;
		if (stack->stack_a[i] == x || stack->stack_a[i] == y)
			stack->posb = i ;
		i++:
	}
	while (k <= stack->last_b)
	{
		if (stack->stack_b[k] == x || stack->stack_b[k] == y)
			stack->posa = k ;
		if (stack->stack_b[k] == x || stack->stack_b[k] == y)
			stack->posb = k ;
		k++:
	}
	if (k > stack->last_b)
        calculate1arraya(stack);
	else if (i > stack->last_a)
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
    if (stack->posb + n(stack->posa, stack->a))
    {
        stack->mosse = stack->posb + n(stack->posa, stack->a);
        stack->move = 1;
    }
    if (stack->mosse > (2*(stack->posa + n(stack->posa, stack->a))
            + (stack->last_a - stack->posb)))
    {
        stack->mosse = (2*(stack->posa + n(stack->posa, stack->a))
        + (stack->last_a - stack->posb));
        stack->move = 2;
    }
    if (stack->mosse > (2*(stack->posa + n(stack->posa, stack->a))
         + (stack->last_a - stack->posb)))
    {
        stack->mosse = ((stack->last_a - stack->posa) - 1 + n(stack->posb, stack->a));
        stack->move = 3;
    }
    if (stack->mosse > 2*(stack->last_a - stack->posb) + 3* n(stack->posb, stack->a) + stack->posa)
    {
        stack->mosse = 2*(stack->last_a - stack->posb) + 3* n(stack->posb, stack->a) + stack->posa;
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
        if (stack->mosse > (2*stack->posa + last - stack->posb +3))
        {
            stack->mosse = 2*stack->posa + last - stack->posb +3;
            stack->move = 2;
        }
        if (stack->mosse > (stack->last_a + 2 * n(stack->posb, stack->a) + 1
             - n(stack->posa, stack->a) - stack->posb))
        {
            stack->mosse = stack->last_a + 2 * n(stack->posb, stack->a) + 1
                - n(stack->posa, stack->a) - stack->posb;
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


int na()


int nb()

int calculate2array(int a, int b)
{
    int tmp;
//tmp deve essere risettato sulla funzione di scan di tutto
//calculate array e altri sono solo funzioni di controlloti tipo if(tmp > calculate(...)
    stack->mosse = 2000000;
    if (a >= b)
    {
        tmp = a;
        if ((stack->last_b + 1 - b + 1) < tmp)
            tmp = stack->last_b + 1 - b + 1 ;
        if((stack->last_a + 1 - a + 1) + b < tmp)
            tmp = (stack->last_a + 1 - a + 1) + b;
    }
    else if (a < b)
    {
        tmp = b;
        if ((stack->last_a + 1 - a) < tmp + 1)
            tmp = stack->last_a + 1 - a + 1;
        if((stack->last_b + 1 - b) + a < tmp + 1)
            tmp = (stack->last_b + 1 - b) + a + 1;
    }
    return  (tmp);
	/*bisogna far si che calculatemoves si calcoli le mosse partendo dai numeri e non dalle poisizioni, se e' versatile
	posso fare pi casistiche, essendo univoci e conseguenziali i valori posso spazzolarmi pognoi volta tutti gli array e cappire dove stanno,
	poi in base alle posizioni fare i calcoli.*/
}

int decidenumbers(t_stack *stack)
{
	int k;

	k = 0;
	stak->tmp2 = 0;
		if ((ac - 1)%2)
		{
			while (k <= stack->last_b)
            {
				while (k <= stack->last_a)
				{
					if (stack->stack_a[k] == stack->posb + 1 || stack->stack_a[k] == stack->posb - 1)
					{
						if (tmp > calculatemoves(stack->posa, stack->posb))
							stack->posa = k;
						k++;
					}
				}
			}
		}
	return (1) ;
}

k = 0;
while (k <= stack->last_b)
{
	i = 0;


	while (i <= stack->last_a)
	{
		if(k = 0 || k = stack->last_b)
			if ()
		if (stack->stack_a[i] == stack->stack_b[k] + 1 || stack->stack_a[k] == stack->stack_b[k] - 1)
		{
			if (tmp > calculatemoves(i, k))
			{
				stack->posa = i;
				stack->posb = k;
				tmp = calculatemoves(i, k);
			}
		}
		i++;
	}
	k++;
}
