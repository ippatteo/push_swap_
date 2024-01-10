/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:30:10 by mcamilli          #+#    #+#             */
/*   Updated: 2023/12/07 20:53:37 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void renum(t_stack *stack, int ac)
{
	int j;
	int tmp;
	int tmp2;
	int tmpp2 = 0;
	int limit;
    int max;
    
	j = 0;
    tmp = stack->a[0];
    max = tmp;
    while (j < ac - 2)
    {
        if (stack->a[j] < tmp)
            tmp = stack->a[j];
        j++;
    }
    stack->min = tmp;
    limit = tmp + (ac - 2);
    j = 0;
     while (j < ac - 2)
    {
        if (stack->a[j] > max)
            max = stack->a[j];
        j++;
    }
    while (tmp < limit)
    {
        tmp2 = max;
        j = 0;
        tmpp2 = j;
        while( j <= ac - 2)
        {
            if (stack->a[j] <= tmp2 && stack->a[j] > tmp)
            {
                tmp2 = stack->a[j];
                tmpp2 = j;
            }
            j++;
        }
        tmp++;
        stack->a[tmpp2] = tmp; 
    }
    tmp = stack->min;
    stack->max = limit;
    while (tmp <= limit)
    {
        j = 0;
        while (j <= stack->last_a)
        {
            if (stack->a[j] == tmp)
                stack->a[j] = tmp - stack->min + 1;
            j++;
        }
        tmp++;
    }
   
    
}


//funzioni per versione alternativa di renum
void lookingfor(t_stack *stack, int tmp2, int a)
{
     while (j <= ac - 2)
    {
        if (stack->copy[j] = tmp2)
        {
            stack->a[j] = a;
            break;
        }
        j++;
    }
}
int firstnumber(t_stack *stack)
{
    int j;
    int tmp0; 
   
   tmp0 = stack->copy[0];
   j = 1;
    while (j <= ac - 2)
    {
        if (stack->copy[j] < tmp0)
            tmp0 = stack->a[j];
        j++;
    }
    lookingfor(stack, tmp0, 1);
    return (tmp0);
}

int othernumber(t_stack *stack, int tmp0)
{
    int j;
    int tmp2; 
   
   tmp2 = stack->copy[0];
   j = 1;
    while (j <= ac - 2)
    {
        if (stack->copy[j] < tmp2 && stack->copy[j] > tmp0)
            tmp2 = stack->copy[j];
        j++;
    }
    return (tmp2);
}
void renum2(t_stack *stack)
{
    int f;
    int a;

    a = 2;
    j = 0;
    f = firstnumber(stack);
   while (a <= ac - 2)
    {
        f = othernumber(stack, f);
        lookingfor(stack, f, a);
        a++;   
    }
}

